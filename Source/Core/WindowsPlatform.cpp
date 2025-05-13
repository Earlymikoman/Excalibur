/*********************************************************************
 * @file   WindowsPlatform.cpp
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

#include "WindowsPlatform.h"

#define MAX_LOADSTRING 100

WCHAR szWindowClass[MAX_LOADSTRING];

static LRESULT CALLBACK PlatformCallback(_In_ HWND hWnd, _In_ UINT message, _In_ WPARAM wParam, _In_ LPARAM lParam);
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);

WindowsPlatform* WindowsPlatform::GetInstance()
{
    static WindowsPlatform instance;

    return &instance;
}

void WindowsPlatform::InitializeInstance(HINSTANCE hInstance)
{
    WindowsPlatform& platform = *WindowsPlatform::GetInstance();

    // Initialize any system-specific variables here:
    platform.mAppInstance = hInstance;

    // Initialize the DigiPen Graphics Library.
    platform.mAppInstance = platform.mAppInstance;

    platform.mShow = true; // Start with window hidden.

    platform.mWindowTitle = "Mod2 - LAST CONTACT";

    // Start the window with little to no resolution, this technically won't be seen as showing has been set to false.
    //! NOTE: Any smaller than these values and DGL will not start the game with the error: "Problem creating depth-stencil buffer. Error 0x80070057"
    platform.mWindowWidth = 50;
    platform.mWindowHeight = 50;

    platform.mMaxFrameRate = 120;

    platform.mClassStyle = CS_HREDRAW | CS_VREDRAW;
    #ifdef _DEBUG
    // Thin border with only a close button.
    platform.mWindowStyle = WS_CAPTION | WS_SYSMENU;
    platform.mCreateConsole = true;
    #else
    // Full screen type window.
    platform.mWindowStyle = WS_POPUPWINDOW;
    platform.mCreateConsole = false;
    #endif

    platform.pWindowsCallback = PlatformCallback;

    // Game window and taskbar icon.
    platform.mWindowIcon = IDI_EXCALIBURWINDOWS;

    LoadStringW(hInstance, IDC_EXCALIBURWINDOWS, szWindowClass, MAX_LOADSTRING);
    InitInstance(hInstance, platform.mShow);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    HINSTANCE hInst = hInstance; // Store instance handle in our global variable

    HWND hWnd = CreateWindowW(szWindowClass, (WCHAR*)WindowsPlatform::GetInstance()->GetWindowTitle(), WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

// This callback function is called every time the application receives a message from the OS.
static LRESULT CALLBACK PlatformCallback(_In_ HWND hWnd, _In_ UINT message, _In_ WPARAM wParam, _In_ LPARAM lParam)
{
    HINSTANCE hInst = WindowsPlatform::GetInstance()->GetAppInstance();

    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Parse the menu selections:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: Add any drawing code that uses hdc here...
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
