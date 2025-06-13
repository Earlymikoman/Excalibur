/*********************************************************************
 * @file   Sprite.h
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

#include "Component/Component.h"

class Mesh;
class Texture;

class Sprite : public ComponentWithType<cSprite>
{
public:

	Sprite() = default;

private:

	Mesh* mesh;

	Texture* texture;

};
