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
