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

using namespace std;

class Object;
class ECS;

class Engine
{
public:
	Engine(Engine const& rhs) = delete;

	Engine& operator=(Engine const& rhs) = delete;

	int Init();

	int Update(double& dt);

	void Render();

	void Exit();

	void Add(ECS* ecs);

	static Engine* GetSingleton();

private:
	Engine();

	static Engine* instance;

	Object* source;

	vector<ECS*> componentSystems;

};
