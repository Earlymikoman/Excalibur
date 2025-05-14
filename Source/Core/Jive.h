/*********************************************************************
 * @file   Jive.h
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

#define TESTSIZE 10

#include <vector>

using std::vector;

class Ingredient
{
public:

	Ingredient(char& Base) : base(Base){}

	char GetBase() { return base; }

	//unsigned int GetSeasoningInstruction() { return seasoningInstruction; }

private:

	char base;

	//unsigned int seasoningInstruction;

};

class Step
{
public:

	Step(unsigned int Start, unsigned int End) : start(Start), end(End) {}

	enum Direction
	{
		BACKWARD = 0,
		FORWARD = 1,
	};

	void Extend(Direction Direction)
	{
		if (Direction)
		{
			++end;
		}
		else
		{
			--start;
		}
	}

	void Contract(Direction Direction)
	{
		if (Direction)
		{
			--start;
		}
		else
		{
			++end;
		}
	}

	unsigned int GetStart() { return start; }

	unsigned int GetEnd() { return end; }

	void SetStart(unsigned int Start) { start = Start; }

	void SetEnd(unsigned int End) { end = End; }

private:

	unsigned int start;

	unsigned int end;
};

class Jive
{
public:

	void Add(char& Base)
	{
		unsigned int newStep = recipe[recipe.size() - 1].GetEnd();
		ExtendStep(Step::FORWARD, recipe.size() - 1);
	}

	void Remove(unsigned int Index)
	{

	}
	void Remove(Ingredient& Ingredient)
	{
		//for (int i = 0; i < T)
	}

	void ExtendStep(Step::Direction Direction, unsigned int Step)
	{
		recipe[Step].Extend(Direction);

		if (recipe[Step].GetEnd() == recipe[Step + 1].GetStart())
		{
			ConcatenateSteps(Step);
		}

		if (recipe[Step - 1].GetEnd() == recipe[Step].GetStart())
		{
			ConcatenateSteps(Step - 1);
		}
	}

	void ConcatenateSteps(unsigned int FirstStep)
	{
		recipe[FirstStep] = Step(recipe[FirstStep].GetStart(), recipe[FirstStep + 1].GetEnd());

		recipe.erase(recipe.begin() + FirstStep + 1);
	}

private:

	vector<Step> recipe;

	Ingredient mix[TESTSIZE];

	vector<Ingredient> spillage;

};
