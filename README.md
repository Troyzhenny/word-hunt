# Word Hunt Turn-based Console Game

I built this game to practice C++ as I know basic C++ but don't have much practice using it day to day. 
This is an attempt to use C++ more often by making small projects.

Word Hunt is a word game similar to wordle, but with a different layout, 
and some different mechanics.

As this is a basic C++ project, there's not much setup besides installing CMake if you don't already use it, then build the project.

## Building the Project
### If you're building on terminal outside of Visual Studio
```bash
cmake -B build
cmake --build build
```

### If you're using Ninja
```bash
cmake -B build -G Ninja
cmake --build build
```

## Running the executable
```bash
./build/WordHunt  

OR on Windows 

.\build\WordHunt.exe 
```