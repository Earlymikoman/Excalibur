/*********************************************************************
 * @file   System.h
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

class Message;

enum SystemEnum
{


	cSystemCount
};

class System
{

	System(SystemEnum type) : systemType(type){}

	System(System const& rhs) = delete;

	System& operator=(System const& rhs) = delete;

public:

	virtual System* GetInstance() = 0;

	virtual void Init(){}

	virtual void Update(double& dt) { dt; }

	virtual void Render(){}

	virtual void Exit(){}

	virtual void HandleMessage(Message& message){}


private:

	SystemEnum systemType;

};
