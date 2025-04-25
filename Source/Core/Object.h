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

#include <vector>

class Component;
class ComponentID;

enum TypeEnum;

using namespace std;

class Object
{
public:
	vector<Object*> const& GetChildren() const;
	
	vector<ComponentID*> const& GetComponents() const;

	template<typename T>
	T* GetComponent(TypeEnum Type)
	{

	}

private:
	vector<Object*> children;
	vector<ComponentID*> components;
};
