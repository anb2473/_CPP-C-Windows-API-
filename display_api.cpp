#include <winsock2.h>
#include <windows.h>
#include <iostream>
#include "C:\Users\austi\Downloads\VSCode\Display_API\API\render_function.cpp"
#include "C:\Users\austi\Downloads\VSCode\Display_API\API\window_protocol_function.cpp"

int WinStart(const char CLASS_NAME[], int TIMER_DELAY, int POS[2], int SIZE[2], HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Register the window class
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    RegisterClass(&wc);

    if (POS == NULL){
        POS[0] = CW_USEDEFAULT;
        POS[1] = CW_USEDEFAULT;
    }

    if (SIZE == NULL){
        SIZE[0] = 800;
        SIZE[1] = 500;
    }

    // Generate the window
    HWND hwnd = CreateWindowEx(
        0,                                              // Optional window styles
        CLASS_NAME,                                     // Window class
        CLASS_NAME,                                     // Window title
        WS_OVERLAPPEDWINDOW,                            // Window style
        POS[0], POS[1], SIZE[0], SIZE[1], // Size and position
        NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) { return 1; printf("Window handler creation failed"); }

    ShowWindow(hwnd, nCmdShow);

    SetTimer(hwnd, 1, TIMER_DELAY, NULL);

    // Loop through messages and send them to the WindowProc
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg); // Send to WindowProc
        DispatchMessage(&msg);  // Delete message
    }

    KillTimer(hwnd, 1);

    return 0;
}