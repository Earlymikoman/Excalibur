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

#include <vector>

using std::vector;

class Platform;
class System;
class Object;
class Message;

class Engine
{
public:

	Engine(Engine const& rhs) = delete;

	Engine& operator=(Engine const& rhs) = delete;

	~Engine();

	int Init();

	int Update(double& dt);

	void Render();

	void Exit();

	void HandleMessage(Message* message);

	void Add(System* system);

	static Engine* GetSingleton();

	Object* GetSourceObject() { return source; }

	void SetPlatform(Platform* Platform) { platform = Platform; }

private:

	Engine();

	Platform* platform;

	Object* source;

	vector<System*> systems;

};
