# C / C++ Windows API

This is a basic windows API for c / c++. Simply install a C / C++ compiler. (The most common is GCC, which can be downloaded at https://gcc.gnu.org/) Once installed, compile the emulator.cpp file with the following commmands:

```powershell
g++ $f -o a.exe -lgdi32
./a.exe
```

This should create a basic test window. From there, you can edit the `render_functions.cpp` file to edit what is rendered on the screen, or the `window_protocol_function.cpp` file to edit how the window events are managed.
