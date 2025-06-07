/*********************************************************************
 * @file   ECS.h
 * @brief  .
 *
 * Project: Excalibur
 *
 * @author Xander Boosinger (xboosinger@gmail.com)
 * @date   April 2025
 *
 *********************************************************************
/*
 *			*	/\
 *			   / /	*
 *		*	__/ /__
 *		      /	  *
 *			 /
 */

#pragma once

#include "Jive.h"
#include "Enums.h"
#include "System.h"

#include <stdlib.h>
#include <vector>

//#define ECS(Type) ECS<Type, c##Type>

using std::vector;

class Object;
class Component;

class ComponentAccessInfo
{
public:

	ComponentAccessInfo(UpdateLayer const& Layer, JiveIndex const& Index);

	UpdateLayer const& GetLayer() const { return layer; }

	JiveIndex const& GetIndex() const { return index; }

private:

	UpdateLayer layer;

	JiveIndex index;

};

//template<typename T>
//class ComponentParentWrapper
//{
//public:
//
//	ComponentParentWrapper() = default;
//
//	T& GetBase() { return base; }
//
//	Object* const& GetParent() const { return parent; }
//
//private:
//
//	T base;
//
//	Object* parent;
//
//};
//
//template<typename T>
//class ComponentReferenceParentWrapper
//{
//public:
//
//	ComponentReferenceParentWrapper() = default;
//
//	T const& GetBase() const { return base; }
//
//	vector<Object*> const& GetParents() const { return parents; }
//
//private:
//
//	T base;
//
//	vector<Object*> parents;
//
//};

template<typename T>
class ECS : public System
{
public:

	static ECS* GetInstance()
	{
		static ECS instance = ECS();

#ifdef _DEBUG
		SafetyCheck();
#endif

		return &instance;
	}

	void Update(double& dt) override
	{
		EnactRemovalBuffer();

		TakeRecipesSnapshot();

		for (int i = 0; i < _countof(components); ++i)
		{
			components[i].JiveIterate<FORWARD>([&dt](auto& ingredient) { ingredient.GetBase().Update(dt); }, recipesSnapshot[i]);
		}
	}

	void Render() override
	{
		for (int i = 0; i < _countof(components); ++i)
		{
			components[i].JiveIterate<FORWARD>([](auto& ingredient) { ingredient.GetBase().Render(); }, recipesSnapshot[i]);
		}
	}

#pragma region Getters

	static TypeEnum GetComponentType()
	{
		return T::GetType();
	}

	T* GetComponent(ComponentAccessInfo const& AccessInfo)
	{
		return &components[AccessInfo.GetLayer()][AccessInfo.GetIndex()];
	}

#pragma endregion

#pragma region Setters

	ComponentAccessInfo AddComponent(T const& Component, UpdateLayer const& Layer)
	{
		return ComponentAccessInfo(Layer, components->Add(Component));
	}

	void RemoveComponent(ComponentAccessInfo& AccessInfo)
	{
		removalBuffer.push_back(AccessInfo);
	}
	void RemoveComponent(T const& Component)
	{
		//components->Remove(&Component);
	}

private:

	void TakeRecipesSnapshot()
	{
		for (int i = 0; i < _countof(components); ++i)
		{
			recipesSnapshot[i] = components[i].GetRecipe();
		}
	}

	void EnactRemovalBuffer()
	{
		for (int i = 0; i < removalBuffer.size(); ++i)
		{
			components[removalBuffer[i].GetLayer()].Remove(removalBuffer[i].GetIndex());
		}

		removalBuffer.clear();
	}

#pragma endregion

protected:

	Jive<T, 100> components[UpdateLayer::LAYERSCOUNT];

	//Jive<ComponentReferenceParentWrapper<T>, 10> references[UpdateLayer::LAYERSCOUNT];

	vector<vector<Step>> recipesSnapshot[_countof(components)];

	vector<ComponentAccessInfo> removalBuffer;

private:

	void SingletonReminder() override {};

	ECS() = default;

	static void SafetyCheck()
	{
		T::GetType();
	}

};