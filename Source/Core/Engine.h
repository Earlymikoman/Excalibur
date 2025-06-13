/*********************************************************************
 * @file   Engine.h
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

#include "Component/Transform.h"
#include "ECS.h"
#include "Object.h"

#include "framework.h"
#include "Resource.h"

#include <vector>
#include <string>

using std::vector;
using std::string;

class System;
class Object;
class Message;
//class HWND;

class Mesh;
class Texture;

class Engine
{
private:

	Engine();

public:

	Engine(Engine const& rhs) = delete;

	Engine& operator=(Engine const& rhs) = delete;

	~Engine();

	static int Init(HINSTANCE const& HInstance);

	static int Update(double& dt);

	static void Render();

	static void Exit();

	static void HandleMessage(Message* message);

	static void Add(System* system);

	static Engine* GetSingleton();

	static Object const& GetSourceObject() { return source; }

	static void SetWindow(HWND const& WindowHandle);

	//void SetPlatform(Platform* Platform) { platform = Platform; }

	//static Mesh* LoadMesh(string const& Name);
	static Texture* LoadTexture(string const& fileName);

	static void Draw(Mesh const& MeshToDraw, DrawMode const& Mode);

private:

	static Object source;

	static vector<System*> systems;

};
