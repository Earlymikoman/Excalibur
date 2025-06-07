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

using std::vector;

Engine::Engine()
	: source(Object::CreateObject())
{

}

Engine::~Engine()
{
	delete source;
}

int Engine::Init()
{
	return 1;
}

int Engine::Update(double& dt)
{
	this->platform->Update(dt);

	for (int i = 0; i < systems.size(); ++i)
	{
		systems[i]->Update(dt);
	}

	return 1;
}

void Engine::Render()
{
	for (int i = 0; i < systems.size(); ++i)
	{
		systems[i]->Render();
	}
}

void Engine::Exit()
{

}

void Engine::HandleMessage(Message* message)
{
	std::cout << message->GetTag() << std::endl;
}

void Engine::Add(System* system)
{
	systems.push_back(system);
}

Engine* Engine::GetSingleton()
{
	static Engine instance = Engine();

	return &instance;
}
