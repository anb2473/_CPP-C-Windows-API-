#include <cstdio>
#include <winsock2.h>
#include <windows.h>

void loop_func(HDC hdc, int width, int height) {
    printf("This is the loop program\n");

    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            // Create a simple red gradient
            COLORREF color = RGB(255, x * 255 / width, y * 255 / height);
            SetPixel(hdc, x, y, color);
        }
    }

    Rectangle(hdc, 50, 50, 250, 150);
}

void loop_proc(HWND hwnd) {
    HDC hdc = GetDC(hwnd); // Obtain the device context

    // Set up a draw rectangle
    RECT rect;
    GetClientRect(hwnd, &rect);
    int width = rect.right - rect.left;
    int height = rect.bottom - rect.top;

    loop_func(hdc, width, height);

    ReleaseDC(hwnd, hdc); // Release the device context
}