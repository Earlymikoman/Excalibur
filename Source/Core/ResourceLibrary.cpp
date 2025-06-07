/*********************************************************************
 * @file   ResourceLibrary.cpp
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

#include "ResourceLibrary.h"

#include "Engine.h"

//class Mesh;

template<>
static Mesh* ResourceLibrary<Mesh>::LoadResource(string const& Name)
{
	return nullptr;
}
