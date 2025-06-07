/*********************************************************************
 * @file   Component.h
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

#include "../Enums.h"

class Object;

class Component
{
public:

	Component(Object* const& Parent = nullptr) : parent(Parent) {};

	Object* GetParent() { return parent; }

	void SetParent(Object* Parent) { parent = Parent; }

private:

	Object* parent;

};

template <TypeEnum Type>
class ComponentWithType : public Component
{
public:

	ComponentWithType() = default;

	static TypeEnum GetType()
	{
		return Type;
	}

private:



};
