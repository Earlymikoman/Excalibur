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
	dt;
	return 1;
}

void Engine::Render()
{

}

void Engine::Exit()
{

}

void Engine::Add(ECS* ecs)
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
