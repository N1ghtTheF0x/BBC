# BBC

A Tower Defence Game using SFML and C++

# Building

You need:

- [Visual Studio Code](https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwiw4rLMqLHzAhVw_rsIHQFwDCoQjBB6BAgMEAE&url=https%3A%2F%2Fcode.visualstudio.com%2Fdownload&usg=AOvVaw11fc5fOXYIyxQh75jYLjXg)
- [MinGW GCC 7.3.0 SEH 64-bit](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/7.3.0/threads-win32/seh/x86_64-7.3.0-release-win32-seh-rt_v5-rev0.7z)
- [C/C++ Extension for VS Code](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
- [SFML 2.5.1](https://www.sfml-dev.org/files/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit.zip)

## Instructions

1. Download all the things above and install the VS Code Extension
2. Change the following Things in `.vscode` Folder for you:
 - `c_cpp_properties.json` = `"compilerPath": <path/to/g++>`
 - `tasks.json` = `"command": <same as above>`
 - `launch.json` = `"miDebuggerPath": <path/to/gpd>`
3. You can now press `CTRL + Shift + B -> Build` to create a Build and `F5` to start the debugger!