/*********************************************************************
 * @file   Object.h
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

#include "Component/Transform.h"
#include "ECS.h"
#include "Enums.h"

#include <vector> 
#include <unordered_map> 

class Component;
class ComponentID;

using std::vector;
using std::unordered_map;

class ComponentData
{
public:

	ComponentData(Component* const& Component, ComponentAccessInfo const& AccessInfo);

	Component*& GetComponent() { return component; }

	ComponentAccessInfo& GetComponentAccessInfo() { return accessInfo; }

private:

	Component* component;

	ComponentAccessInfo accessInfo;

};

class Object final
{

private:

	Object() = default;

	Object(Object const& rhs) = default;

	Object& operator=(Object const& rhs) = default;

public:

	static Object* CreateObject();

	Transform* const& GetTransform() const { return transform; }

	std::vector<Object*> const& GetChildren() const;
	
	std::vector<ComponentID*> const& GetComponents() const;

	template<typename T>
	T* AddComponent(T const& ComponentToAdd, UpdateLayer Layer = UpdateLayer::SLOWEST)
	{
		ECS<T>* componentSystemInstance = ECS<T>::GetInstance();

		ComponentAccessInfo accessInfo = componentSystemInstance->AddComponent(ComponentToAdd, Layer);

		T* componentPointer = componentSystemInstance->GetComponent(accessInfo);
		componentPointer->SetParent(this);

		components.insert({ ECS<T>::GetComponentType(), ComponentData((Component*)componentPointer, accessInfo) });

		return componentPointer;
	}

	template<typename T>
	T* GetComponent(TypeEnum Type)
	{
		return components.find(Type);
	}

private:

	Object(vector<Object*> Children, unordered_map<TypeEnum, ComponentData> Components);

	Transform* transform;

	vector<Object*> children;
	unordered_map<TypeEnum, ComponentData> components;

};
