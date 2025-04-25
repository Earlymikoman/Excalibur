/*********************************************************************
 * @file   main.cpp
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

#include "ECS.h"

#include <chrono>

class Transform;

int main()
{
	Engine* mainEngine = Engine::GetSingleton();

	//Add things to Engine here.
	mainEngine->Add(new TrueECS<Transform>());

	int running = mainEngine->Init();

	auto previousTime = std::chrono::high_resolution_clock::now();
	while (running)
	{
		auto newTime = std::chrono::high_resolution_clock::now();
		double dt = (std::chrono::duration<double>(newTime - previousTime)).count();
		previousTime = newTime;

		running = mainEngine->Update(dt);

		mainEngine->Render();
	}

	mainEngine->Exit();

	return 0;
}
