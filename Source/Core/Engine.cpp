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
#include "WindowsPlatform.h"
#include "../DirectX/DirectXGraphics.h"
#include "Mesh.h"
#include "ResourceLibrary.h"

#include <iostream>

using std::vector;

typedef WindowsPlatform EnginePlatform;
typedef DirectXData EngineGraphicsEngine;

//EngineGraphicsEngine::SetWindow(HWND const& windowHandle);

Object Engine::source;

vector<System*> Engine::systems;

Engine::Engine()
	//: source(Object::CreateObject())
{

}

Engine::~Engine()
{
	//delete source;
}

int Engine::Init(HINSTANCE const& HInstance)
{
	WindowsPlatform::InitializeInstance(HInstance);

	EngineGraphicsEngine::InitializeGraphics();



	return 1;
}

int Engine::Update(double& dt)
{
	EnginePlatform::Update(dt);

	for (int i = 0; i < systems.size(); ++i)
	{
		systems[i]->Update(dt);
	}

	//Test graphics code

	EngineGraphicsEngine::StartDrawing();

	static float xpos = 100;
	xpos += 1;

	EngineGraphicsEngine::SetPosition(Vector<2>(xpos, 100));
	EngineGraphicsEngine::SetScale(Vector<2>(100, 100));

	EngineGraphicsEngine::LoadTexture("Assets/Milk.png");
	//EngineGraphicsEngine::SetTexture(ResourceLibrary<Texture)

	Draw
	(
		*new Mesh
		(
			"TestMesh"
			, vector<VertexData>
	{
		VertexData(-0.5f, -0.5f, 0.5f, 0.6f, 0.9f, 1.0f, 0.0f, 1.0f)
			, VertexData(-0.5f, 0.5f, 0.5f, 0.6f, 0.9f, 1.0f, 0.0f, 0.0f)
			, VertexData(0.5f, 0.5f, 0.5f, 0.6f, 0.9f, 1.0f, 1.0f, 0.0f)
			, VertexData(-0.5f, -0.5f, 0.5f, 0.6f, 0.9f, 1.0f, 0.0f, 1.0f)
			, VertexData(0.5f, 0.5f, 0.5f, 0.6f, 0.9f, 1.0f, 1.0f, 0.0f)
			, VertexData(0.5f, -0.5f, 0.5f, 0.6f, 0.9f, 1.0f, 1.0f, 1.0f)
	}
		)
		, DrawMode::TEXTURE
	);

	EngineGraphicsEngine::LoadTexture("Assets/Ball.png");
	EngineGraphicsEngine::SetPosition(Vector<2>(200, 100));

	Draw
	(
		*new Mesh
		(
			"TestMesh"
			, vector<VertexData>
	{
		VertexData(-0.5f, -0.5f, 0.5f, 0.6f, 0.9f, 1.0f, 0.0f, 1.0f)
			, VertexData(-0.5f, 0.5f, 0.5f, 0.6f, 0.9f, 1.0f, 0.0f, 0.0f)
			, VertexData(0.5f, 0.5f, 0.5f, 0.6f, 0.9f, 1.0f, 1.0f, 0.0f)
			, VertexData(-0.5f, -0.5f, 0.5f, 0.6f, 0.9f, 1.0f, 0.0f, 1.0f)
			, VertexData(0.5f, 0.5f, 0.5f, 0.6f, 0.9f, 1.0f, 1.0f, 0.0f)
			, VertexData(0.5f, -0.5f, 0.5f, 0.6f, 0.9f, 1.0f, 1.0f, 1.0f)
	}
		)
		, DrawMode::TEXTURE
	);

	EngineGraphicsEngine::FinishDrawing();

	/*Draw
	(
		*new Mesh
		(
			"TestMesh"
			, vector<VertexData>
	{
		VertexData(-0.5f, -0.5f, 0.5f, 0.6f, 0.9f, 1.0f, 0.0f, 0.5f)
			, VertexData(-0.5f, 0.5f, 0.5f, 0.6f, 0.9f, 1.0f, 0.0f, 0.0f)
			, VertexData(0.5f, 0.5f, 0.5f, 0.6f, 0.9f, 1.0f, 0.5f, 0.0f)
			, VertexData(-0.5f, -0.5f, 0.5f, 0.6f, 0.9f, 1.0f, 0.0f, 0.5f)
			, VertexData(0.5f, 0.5f, 0.5f, 0.6f, 0.9f, 1.0f, 0.5f, 0.0f)
			, VertexData(0.5f, -0.5f, 0.5f, 0.6f, 0.9f, 1.0f, 0.5f, 0.5f)
	}
		)
		, DrawMode::TEXTURE
	);*/

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

void Engine::SetWindow(HWND const& WindowHandle)
{
	EngineGraphicsEngine::SetWindow(WindowHandle);
}

Engine* Engine::GetSingleton()
{
	static Engine instance = Engine();

	return &instance;
}

void Engine::Draw(Mesh const& MeshToDraw, DrawMode const& Mode)
{
	EngineGraphicsEngine::Draw(MeshToDraw, Mode);
}

#pragma region Resource Loading Functions

//Mesh* Engine::LoadMesh(string const& Name)
//{
//	return EngineGraphicsEngine::Load
//}
//
Texture* Engine::LoadTexture(string const& fileName)
{
	return EngineGraphicsEngine::LoadTexture(fileName);
}

#pragma endregion
