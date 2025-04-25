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

class ComponentID;

enum TypeEnum
{
	cNONE = 0,//Should not be used.
	
	cTransform,
	cSprite,
	cPhysics,
	cAnimation,
	cCollider,

	cALL//WTF does that even mean? It means don't use this.
};

class Component
{
public:


private:
	ComponentID* ID;

};
