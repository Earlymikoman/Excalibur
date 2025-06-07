/*********************************************************************
 * @file   Enums.h
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

enum UpdateLayer
{
	FASTEST = 0,

	FAST,
	AVERAGE,
	SLOW,

	SLOWEST,

	LAYERSCOUNT//DO NOT USE
};

enum InputType
{
	UNKNOWN,//DO NOT USE

	JUMP,
	UP,
	LEFT,
	DOWN,
	RIGHT,

	cInputStateMax//DO NOT USE
};

enum MessageTag
{
	MESSAGECONTINUITY = InputType::cInputStateMax,//DO NOT USE


};

enum Direction
{
	BACKWARD = 0,
	FORWARD = 1,
};

enum DrawMode
{
	PIXEL,
	TEXTURE
};
