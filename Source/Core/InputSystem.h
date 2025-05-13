/*****************************************************************//**
 * @file   InputSystem.h
 * @brief  Public interface for input handling.
 * 
 * Project:LAST_CONTACT
 * Course: GAM150S25
 * 
 * @author Xander Boosinger (xander.boosinger@digipen.edu)
 * @date   February 2025
 * 
 * Copyright © 2025 DigiPen (USA) Corporation.
 *********************************************************************/
/*  __  __  ___  ____ ____  
 * |  \/  |/ _ \|  _ \___ \ 
 * | |\/| | | | | | | |__) |
 * | |  | | |_| | |_| / __/ 
 * |_|  |_|\___/|____/_____|
 */

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Forward References:
//------------------------------------------------------------------------------

typedef struct BaseSystem BaseSystem;

//------------------------------------------------------------------------------
// Public Constants And Enums:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Typedefs:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------
//void InputSystemSetInput(const char* input, char value);
//
//char InputSystemGetInput(const char* input);
//
//bool InputSystemInputDown(const char* input, Object* object = nullptr);
//
//bool InputSystemInputTriggered(const char* input, Object* object = nullptr);
//
//bool InputSystemInputReleased(const char* input, Object* object = nullptr);
//
//void InputSystemReserveInput(const char* input, Object* reserve);
//void InputSystemCancelReservation(const char* input, Object* canceler);
//
//void InputSystemClearInputReservations(const char* input);

// Get the instance of the Input System.
// Returns:
//	 Pointer to the abstract BaseSystem for this derived System.
BaseSystem* InputSystemGetInstance(void);

/*----------------------------------------------------------------------------*/
