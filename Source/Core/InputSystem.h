/*********************************************************************
 * @file   InputSystem.h
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

#include "System.h"

#include "Stream.h"
#include "Message.h"
#include "Enums.h"
#include "Engine.h"
#include "MultiField.h"

//#include "WinUser.h"

#include <cassert>
#include <vector>
#include <map>
#include <string>

using std::vector;

//using namespace std;

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Forward References:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Constants And Enums:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Typedefs:
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

class Input
{
public:

	Input(InputType inputType, std::string const& Name/*, char CurrentState = 0*/);

	InputType GetType() const { return type; }

	std::string const& GetName() const { return name; }

private:

	InputType type;

	std::string name;

	//char currentState;

};

template<typename KeyType>
class InputSystem
{
public:

	InputSystem(
		std::vector<Input> const* Inputs = new std::vector<Input>(),
		std::map<KeyType, Input const*> const* InputMappings = new std::map<KeyType, Input const*>(),
		std::vector<Message> const* MessageQueue = new std::vector<Message>())
		: inputs(*Inputs)
		, inputMappings(*InputMappings)
		, messageQueue()
	{
	}

	void Init()
	{
		inputs.push_back(Input(JUMP, std::string("Jump")));

		inputs.push_back(Input(UP, std::string("Up")));

		inputs.push_back(Input(LEFT, std::string("Left")));

		inputs.push_back(Input(DOWN, std::string("Down")));

		inputs.push_back(Input(RIGHT, std::string("Right")));



		Stream dataStream = StreamOpen("Data/DefaultInputMappings.txt");

		assert(dataStream && "Invalid Stream!");

		ReadInputMap(dataStream);
	}

	void QueueMessage(Message* message)
	{
		static vector<Message*> queued;

		for (int i = 0; i < queued.size(); ++i)
		{
			if (message == queued[i])
			{
				int a = 0;
				++a;
			}
		}

		queued.push_back(message);

		messageQueue.push_back(*message);
	}

	void SendMessages()
	{
		int size = (int)messageQueue.size();

		for (int i = 0; i < size; ++i)
		{
			Engine::GetSingleton()->HandleMessage(messageQueue[i]);
		}

		for (int i = size - 1; i << size >= 0; --i)
		{
			messageQueue.erase(messageQueue.begin() + i);
		}
	}

	Input const* FindInput(std::string& InputName)
	{
		for (int i = 0; i < inputs.size(); ++i)
		{
			if (InputName == inputs[i].GetName())
			{
				return &inputs[i];
			}
		}

		return nullptr;
	}

	void AddInputMapping(KeyType keycode, Input const* input)
	{
		inputMappings[keycode] = input;
	}

	void ReadInputMap(Stream openStream)
	{
		while (int keycode = StreamReadInt(openStream))
		{
			StreamReadToken(openStream);
			std::string name = StreamReadToken(openStream);

			AddInputMapping(keycode, FindInput(name));
		}
	}

	void KeyDown(KeyType key)
	{
		Message* message = new Message(inputMappings[key]->GetType(), nullptr, new NamedMultiField(NamedField("InputState", (char)1)));

		QueueMessage(message);

		//Engine::GetSingleton()->HandleMessage(message);
	}

	void KeyReleased(KeyType key)
	{
		Message* message = new Message(inputMappings[key]->GetType(), nullptr, new NamedMultiField(NamedField("InputState", (char)0)));

		QueueMessage(message);

		//Engine::GetSingleton()->HandleMessage(message);
	}

private:

	std::vector<Input> inputs;
	std::map<KeyType, Input const*> inputMappings;

	std::vector<Message> messageQueue;

};

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

/*----------------------------------------------------------------------------*/
