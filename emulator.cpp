#include "C:\Users\austi\Downloads\VSCode\Display_API\API\display_api.cpp"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const char CLASS_NAME[] = "Display API";

    int TIMER_DELAY = 100;

    WinStart(CLASS_NAME, TIMER_DELAY, new int[2]{400, 100}, new int[2]{800, 500}, hInstance, hPrevInstance, lpCmdLine, nCmdShow);

    return 0;
}