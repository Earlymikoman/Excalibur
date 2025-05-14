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
#include "Resource.h"

#include "Engine.h"
#include "WindowsPlatform.h"

#include "ECS.h"
#include "Message.h"

#include <chrono>
#include <omp.h>
#include <fstream>
#include <iostream>

class Transform;

void AttachConsoleWindow()//Courtesy of chatgpt.
{
	AllocConsole();  // Create a new console
	FILE* dummy;
	freopen_s(&dummy, "CONOUT$", "w", stdout);
	freopen_s(&dummy, "CONOUT$", "w", stderr);
	freopen_s(&dummy, "CONIN$", "r", stdin);
	std::cout.clear();
	std::cerr.clear();
	std::cin.clear();
}

void MessagesManagement(HINSTANCE hInstance);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	AttachConsoleWindow();
	WindowsPlatform::InitializeInstance(hInstance);
	
	Engine* mainEngine = Engine::GetSingleton();
	mainEngine->SetPlatform(WindowsPlatform::GetInstance());

	//Add things to Engine here.
	mainEngine->Add((System*)new TrueECS<Transform>());

	int running = mainEngine->Init();

	auto previousTime = std::chrono::high_resolution_clock::now();

	#pragma omp parallel sections
	{
		#pragma omp section
		{
			MessagesManagement(hInstance);
		}

		#pragma omp section
		{
			while (running)
			{
				auto newTime = std::chrono::high_resolution_clock::now();
				double dt = (std::chrono::duration<double>(newTime - previousTime)).count();
				previousTime = newTime;

				running = mainEngine->Update(dt);

				mainEngine->Render();
			}
		}
	}

	mainEngine->Exit();

	return 0;
}

void MessagesManagement(HINSTANCE hInstance)
{
	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EXCALIBURWINDOWS));

	MSG msg;

	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}
