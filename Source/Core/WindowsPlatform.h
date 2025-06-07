/*********************************************************************
 * @file   WindowsPlatform.h
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

#include "Platform.h"
#include "InputSystem.h"
#include "../DirectX/DirectXGraphics.h"

class WindowsPlatform : public Platform
{
private:

    WindowsPlatform() = default;

	WindowsPlatform(Platform const& rhs) = delete;

	WindowsPlatform& operator=(Platform const& rhs) = delete;

public:

    static WindowsPlatform* GetInstance();

    static void InitializeInstance(HINSTANCE hInstance);

	BOOL InitWindow(HINSTANCE hInstance, int nCmdShow);

    void Update(double& dt);

    ATOM RegisterWindowsClass();

    InputSystem<char>* GetInputSystem() { return &inputSystem; }

    HINSTANCE GetAppInstance() { return mAppInstance; }
    const char* GetWindowTitle() { return mWindowTitle; }

private:

	DirectXData* graphicsEngine;

    InputSystem<char> inputSystem;

    // This should be set to the first parameter from WinMain.
    // It is used to identify the application instance when creating and closing the window.
    HINSTANCE mAppInstance;

    // This should be set to the fourth parameter from WinMain.
    // It is used when creating the window to control whether it is shown or not.
    int mShow;

    // These two variables specify the width and height of the window to be created.
    // This will be the total window size including title bar and borders (if using).
    // Use the DGL_System_GetWindowSize() function afterwards to get the client size of 
    // a bordered window (the window size without title bar and borders).
    unsigned int mWindowWidth;
    unsigned int mWindowHeight;

    // This is used to set the framerate controller's maximum framerate. 
    unsigned int mMaxFrameRate;

    // Sets the Window Class Style to be used. 
    // This should usually be set to "CS_HREDRAW | CS_VREDRAW".
    unsigned int mClassStyle;

    // Sets the Window Style to be used.
    // If you are unsure, use "WS_OVERLAPPEDWINDOW" for a windowed application
    // or "WS_EX_TOPMOST | WS_POPUP" for a fullscreen application.
    // When using "WS_OVERLAPPEDWINDOW", adding "^ WS_THICKFRAME" will disable resizing.
    unsigned int mWindowStyle;

    // Sets the window title text that will be shown on the top bar of a windowed application.
    const char* mWindowTitle;

    // Specifies whether a debug console should be created. 
    // Use TRUE to show the console and FALSE to hide it.
    // This console will display output from stdout and stderr, including printf output.
    BOOL mCreateConsole;

    // The icon resource definition to use for the window title bar icon. 
    // Visual Studio will automatically create a file named Resource.h and a .ico file 
    // with the same name as your project. You can edit the .ico file with your own custom icon. 
    // Usually what you will set this to is IDI_YOURPROJECTNAME.
    int mWindowIcon;

    // This should be set to the name of your Windows callback function.
    // When created automatically by Visual Studio this is usually called WndProc. 
    WNDPROC pWindowsCallback;

};
