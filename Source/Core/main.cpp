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

#include "framework.h"

#include "Engine.h"
#include "WindowsPlatform.h"

#include "ECS.h"

#include <chrono>

class Transform;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	WindowsPlatform::InitializeInstance(hInstance);

	Engine* mainEngine = Engine::GetSingleton();
	mainEngine->SetPlatform(WindowsPlatform::GetInstance());

	//Add things to Engine here.
	mainEngine->Add((System*)new TrueECS<Transform>());

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
