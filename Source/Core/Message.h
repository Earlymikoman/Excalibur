/*********************************************************************
 * @file   Message.h
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

#include "Enums.h"

//#include "MultiField.h"

#include <vector>

//using namespace std;

class Object;
class NamedMultiFieldWrapper;

class Message
{
public:

	Message(MessageTag Tag, Object* Caller = nullptr, NamedMultiFieldWrapper* Resources = nullptr) : tag(Tag), caller(Caller), resources(Resources) {}
	Message(InputType Tag, Object* Caller = nullptr, NamedMultiFieldWrapper* Resources = nullptr) : tag(Tag), caller(Caller), resources(Resources) {}

	~Message();

	int GetTag() { return tag; }

	NamedMultiFieldWrapper* GetResources() { return resources; }

private:

	int tag;

	Object* caller;

	NamedMultiFieldWrapper* resources;

};
