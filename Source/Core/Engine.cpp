/*********************************************************************
 * @file   Engine.cpp
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

#include "Engine.h"

#include "Message.h"
#include "Platform.h"

#include <iostream>

using namespace std;

Engine* Engine::instance = nullptr;

Engine::Engine()
	: source(nullptr)
{

}

int Engine::Init()
{
	return 1;
}

int Engine::Update(double& dt)
{
	this->platform->Update(dt);

	dt;
	return 1;
}

void Engine::Render()
{

}

void Engine::Exit()
{

}

void Engine::HandleMessage(Message& message)
{
	std::cout << message.GetTag() << std::endl;
}

void Engine::Add(System* ecs)
{
	ecs;
}

Engine* Engine::GetSingleton()
{
	if (!instance)
	{
		instance = new Engine();
	}

	return instance;
}
