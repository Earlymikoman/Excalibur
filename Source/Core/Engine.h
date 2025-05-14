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

#include <vector>

//using namespace std;

class Platform;
class Object;
class System;
class Message;

class Engine
{
public:
	Engine(Engine const& rhs) = delete;

	Engine& operator=(Engine const& rhs) = delete;

	int Init();

	int Update(double& dt);

	void Render();

	void Exit();

	void HandleMessage(Message& message);

	void Add(System* ecs);

	static Engine* GetSingleton();

	Object* GetSourceObject() { return source; }

	void SetPlatform(Platform* Platform) { platform = Platform; }

private:
	Engine();

	static Engine* instance;

	Platform* platform;

	Object* source;

	std::vector<System*> systems;

};
