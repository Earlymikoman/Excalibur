/*********************************************************************
 * @file   Transform.h
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

#include "Component.h"
#include "../Vector.h"

class Transform : public ComponentWithType<cTransform>
{
public:

	void Update(double& dt) {}

	void Render() {}

	Vector<3> const& GetPosition() const { return position; }

	Vector<3> const& GetRotation() const { return rotation; }

	Vector<3> const& GetScale() const { return scale; }

private:

	Vector<3> position;

	Vector<3> rotation;

	Vector<3> scale;

};
