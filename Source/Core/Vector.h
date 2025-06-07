/*********************************************************************
 * @file   Vector.h
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

template<unsigned int Dimensions>
class Vector
{
public:

	Vector() = default;

	float Get(unsigned int Dimension) { return dimensions[Dimension]; }

private:

	float dimensions [Dimensions];

};

template <>
class Vector<2>
{
public:

	Vector(float X = 0, float Y = 0) : x(X), y(Y) {};

	float X() const { return x; }

	float Y() const { return y; }

private:

	float x;

	float y;

};

template <>
class Vector<3>
{
public:

	Vector(float X = 0, float Y = 0, float Z = 0) : x(X), y(Y), z(Z) {};

	float X() const { return x; }

	float Y() const { return y; }

	float Z() const { return z; }

private:

	float x;

	float y;

	float z;

};
