///*****************************************************************//**
// * @file   InputSystem.cpp
// * @brief  Implementation of input handling.
// * 
// * Project:LAST_CONTACT
// * Course: GAM150S25
// * 
// * @author Xander Boosinger (xander.boosinger@digipen.edu)
// * @date   February 2025
// * 
// * Copyright © 2025 DigiPen (USA) Corporation.
// *********************************************************************/
///*  __  __  ___  ____ ____  
// * |  \/  |/ _ \|  _ \___ \ 
// * | |\/| | | | | | | |__) |
// * | |  | | |_| | |_| / __/ 
// * |_|  |_|\___/|____/_____|
// */
//
//#include <WinUser.h>
//
//#include <map>
//
//using namespace std;
//
////------------------------------------------------------------------------------
//// Private Constants And Enums:
////------------------------------------------------------------------------------
//
////------------------------------------------------------------------------------
//// Private Structures And Classes:
////------------------------------------------------------------------------------
//
//class Input
//{
//public:
//
//	char inputValue;
//	vector<Object*> reservations;
//};
//
//typedef struct InputSystem
//{
//	// WARNING: The base class must always be included first.
//	BaseSystem	base;
//
//	// Add any system-specific variables second.
//	Input LeftClick;
//	Input RightClick;
//	Input Exit;
//	Input Jump;
//	Input RotateLeft;
//	Input RotateRight;
//	Input Reverse;
//	Input GotoMainMenu;
//	Input GotoLevelTwo;
//	Input GotoLevelThree;
//	Input GotoLevelFour;
//	Input GotoLevelFive;
//	Input GotoLevelSix;
//	Input GoToLevelSeven;
//	Input GoToLevelEight;
//	Input UpArrow;
//	Input DownArrow;
//
//
//	map<unsigned char, Input*> inputDictionary;
//	map<const char*, Input*> stringInputDictionary;
//} InputSystem;
//
////------------------------------------------------------------------------------
//// Public Variables:
////------------------------------------------------------------------------------
//
////------------------------------------------------------------------------------
//// Private Function Declarations:
////------------------------------------------------------------------------------
//
////  System-specific State functions:
//static bool InputSystemInit(void);
//static void InputSystemUpdate(float& dt);
//static void InputSystemRender(void);
//static void InputSystemExit(void);
//
//void InputSystemReserveInput(const char* input, Object* reserve);
//void InputSystemCancelReservation(const char* input, Object* canceler);
//char InputSystemObjectHasReservation(const char* input, Object* object);
//
////------------------------------------------------------------------------------
//// Private Variables:
////------------------------------------------------------------------------------
//
//static InputSystem instance =
//{
//	{ "InputSystem", InputSystemInit, InputSystemUpdate, InputSystemRender, InputSystemExit},
//
//	{Input()},
//	{Input()},
//	{Input()},
//	{Input()},
//	{Input()},
//	{Input()},
//	{Input()},
//};
//
////------------------------------------------------------------------------------
//// Public Functions:
////------------------------------------------------------------------------------
//
//// Get the instance of the Input System.
//// Returns:
////	 Pointer to the abstract BaseSystem for this derived System.
//BaseSystem* InputSystemGetInstance()
//{
//	// Initialize any system-specific variables here:
//
//	// Return a reference to the instance of this system.
//	return (BaseSystem*)&instance;
//}
//
////------------------------------------------------------------------------------
//// Private Functions:
////------------------------------------------------------------------------------
//
///**
// * @brief Sets the InputSystem instance of input to value.
// * 
// * @param input String corresponding to an input.
// * @param value Value to be set.
// */
//void InputSystemSetInput(const char* input, char value)
//{
//	if (instance.stringInputDictionary.find(input) != instance.stringInputDictionary.end())
//	{
//		(instance.stringInputDictionary[input]->inputValue) = value;
//	}
//}
//
///**
// * @brief Gets the value of InputSystem instance of input.
// * 
// * @param input String corresponding to an input.
// * @return input value.
// */
//char InputSystemGetInput(const char* input)
//{
//	if (instance.stringInputDictionary.find(input) != instance.stringInputDictionary.end())
//	{
//		return instance.stringInputDictionary[input]->inputValue;
//	}
//
//	return 0;
//}
//
///**
// * @brief Gets whether input is in 'down' state.
// *
// * @param input String corresponding to an input.
// * @return 1 if input is 'down', 0 if not.
// */
//bool InputSystemInputDown(const char* input, Object* object)
//{
//	if (instance.stringInputDictionary.find(input) != instance.stringInputDictionary.end())
//	{
//		if (!InputSystemObjectHasReservation(input, object))
//		{
//			return 0;
//		}
//
//		if (instance.stringInputDictionary[input]->inputValue > 0)
//		{
//			return 1;
//		}
//	}
//
//	return 0;
//}
//
///**
// * @brief Gets whether input is in 'triggered' state.
// *
// * @param input String corresponding to an input.
// * @return 1 if input is 'down' and was not last frame, 0 if not.
// */
//bool InputSystemInputTriggered(const char* input, Object* object)
//{
//	if (instance.stringInputDictionary.find(input) != instance.stringInputDictionary.end())
//	{
//		if (!InputSystemObjectHasReservation(input, object))
//		{
//			return 0;
//		}
//
//		if (instance.stringInputDictionary[input]->inputValue == 1)
//		{
//			return 1;
//		}
//	}
//
//	return 0;
//}
//
///**
// * @brief Gets whether input is in 'released' state.
// *
// * @param input String corresponding to an input.
// * @return 1 if input is not 'down' but was last frame, 0 if not.
// */
//bool InputSystemInputReleased(const char* input, Object* object)
//{
//	if (instance.stringInputDictionary.find(input) != instance.stringInputDictionary.end())
//	{
//		if (!InputSystemObjectHasReservation(input, object))
//		{
//			return 0;
//		}
//
//		if (instance.stringInputDictionary[input]->inputValue == -1)
//		{
//			return 1;
//		}
//	}
//
//	return 0;
//}
//
///**
// * @brief Sets the initial dictionary states for the input dictionaries.
// * 
// * @return Whether InputSystem was initialized successfully.
// */
//static bool InputSystemInit(void)
//{
//	instance.stringInputDictionary["LeftClick"] = &instance.LeftClick;
//	instance.inputDictionary[1] = &instance.LeftClick;
//	
//	instance.stringInputDictionary["RightClick"] = &instance.RightClick;
//	instance.inputDictionary[VK_RBUTTON] = &instance.RightClick;
//
//	instance.stringInputDictionary["Reverse"] = &instance.Reverse;
//	instance.inputDictionary['R'] = &instance.Reverse;
//
//	instance.stringInputDictionary["Exit"] = &instance.Exit;
//	instance.inputDictionary[VK_ESCAPE] = &instance.Exit;
//
//	instance.stringInputDictionary["Jump"] = &instance.Jump;
//	instance.inputDictionary[' '] = &instance.Jump;
//
//	instance.stringInputDictionary["RotateLeft"] = &instance.RotateLeft;
//	instance.inputDictionary['Q'] = &instance.RotateLeft;
//
//	instance.stringInputDictionary["RotateRight"] = &instance.RotateRight;
//	instance.inputDictionary['E'] = &instance.RotateRight;
//
//	instance.stringInputDictionary["GotoMainMenu"] = &instance.GotoMainMenu;
//	instance.inputDictionary['1'] = &instance.GotoMainMenu;
//
//	instance.stringInputDictionary["GotoLevelTwo"] = &instance.GotoLevelTwo;
//	instance.inputDictionary['2'] = &instance.GotoLevelTwo;
//
//	instance.stringInputDictionary["GotoLevelThree"] = &instance.GotoLevelThree;
//	instance.inputDictionary['3'] = &instance.GotoLevelThree;
//
//	instance.stringInputDictionary["GotoLevelFour"] = &instance.GotoLevelFour;
//	instance.inputDictionary['4'] = &instance.GotoLevelFour;
//
//	instance.stringInputDictionary["GotoLevelFive"] = &instance.GotoLevelFive;
//	instance.inputDictionary['5'] = &instance.GotoLevelFive;
//
//	instance.stringInputDictionary["GotoLevelSix"] = &instance.GotoLevelSix;
//	instance.inputDictionary['6'] = &instance.GotoLevelSix;
//
//	instance.stringInputDictionary["GoToLevelSeven"] = &instance.GoToLevelSeven;
//	instance.inputDictionary['7'] = &instance.GoToLevelSeven;
//
//	instance.stringInputDictionary["GoToLevelEight"] = &instance.GoToLevelEight;
//	instance.inputDictionary['8'] = &instance.GoToLevelEight;
//
//	instance.stringInputDictionary["UpArrow"] = &instance.UpArrow;
//	instance.inputDictionary[VK_UP] = &instance.UpArrow;
//
//	instance.stringInputDictionary["DownArrow"] = &instance.DownArrow;
//	instance.inputDictionary[VK_DOWN] = &instance.DownArrow;
//
//	// Return false if the system was NOT initialized successfully.
//
//	// Return true if the system was initialized successfully.
//	return true;
//}
//
//void InputSystemReserveInput(const char* input, Object* reserve)
//{
//	if (InputSystemObjectHasReservation(input, reserve) < 2)
//	{
//		instance.stringInputDictionary[input]->reservations.push_back(reserve);
//	}
//}
//
//void InputSystemCancelReservation(const char* input, Object* canceler)
//{
//	for (int i = 0; i < instance.stringInputDictionary[input]->reservations.size(); ++i)
//	{
//		if (instance.stringInputDictionary[input]->reservations[i] == canceler)
//		{
//			instance.stringInputDictionary[input]->reservations.erase(instance.stringInputDictionary[input]->reservations.begin() + i);
//		}
//	}
//}
//
//void InputSystemClearInputReservations(const char* input)
//{
//	if (instance.stringInputDictionary.find(input) != instance.stringInputDictionary.end())
//	{
//		instance.stringInputDictionary[input]->reservations.clear();
//	}
//}
//
//void InputSystemClearAllReservations()
//{
//	for (unsigned char i = 0; i < 255; i++)
//	{
//		if (instance.inputDictionary.find(i) != instance.inputDictionary.end())
//		{
//			instance.inputDictionary[i]->reservations.clear();
//		}
//	}
//}
//
//char InputSystemObjectHasReservation(const char* input, Object* object)
//{
//	if (instance.stringInputDictionary.find(input) != instance.stringInputDictionary.end())
//	{
//		if (instance.stringInputDictionary[input]->reservations.size() == 0)
//		{
//			return 1;
//		}
//
//		for (int i = 0; i < instance.stringInputDictionary[input]->reservations.size(); ++i)
//		{
//			if (instance.stringInputDictionary[input]->reservations[i] == object)
//			{
//				return 2;
//			}
//		}
//	}
//
//	return 0;
//}
//
///**
// * @brief Checks every input for its current down state. TODO: optimize to only check for inputs we care about.
// * 
// * @param dt Time since last frame.
// */
//static void InputSystemUpdate(float& dt)
//{
//	InputSystemClearAllReservations();
//
//	// Tell the compiler that the 'dt' variable is unused.
//	UNREFERENCED_PARAMETER(dt);
//
//	for (unsigned char i = 0; i < 255; i++)
//	{
//		if (DGL_Input_KeyDown(i))
//		{
//			if (instance.inputDictionary.find(i) != instance.inputDictionary.end())
//			{
//				if (instance.inputDictionary[i]->inputValue > 0)
//				{
//					instance.inputDictionary[i]->inputValue = 2;
//				}
//				else
//				{
//					instance.inputDictionary[i]->inputValue = 1;
//				}
//			}
//		}
//		else
//		{
//			if (instance.inputDictionary.find(i) != instance.inputDictionary.end())
//			{
//				if (instance.inputDictionary[i]->inputValue > 0)
//				{
//					instance.inputDictionary[i]->inputValue = -1;
//				}
//				else
//				{
//					instance.inputDictionary[i]->inputValue = 0;
//				}
//			}
//		}
//	}
//
//	
//}
//
///**
// * @brief Shouldn't ever do anything that isn't debug.
// * 
// */
//static void InputSystemRender(void)
//{
//}
//
///**
// * @brief Shouldn't ever do anything that isn't debug..
// * 
// */
//static void InputSystemExit(void)
//{
//}
//
