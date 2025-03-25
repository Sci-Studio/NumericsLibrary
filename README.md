# NumericsLibrary
This repository is for a c++ library that includes mathematical algorithm for meshing geometry

# Build and Run
follow the following steps
* create a build directory`mkdir build`
* navigate to the build directory `cd build` and run `cmake ..` and for debug `cmake -DCMAKE_BUILD_TYPE=Debug ..`
* build the executable`make` which will generate an executable with the name `NumericasLibrary`
* run the executable `./NumericasLibrary`

# Debug with VS Code
exact steps are introduced by this video https://www.youtube.com/watch?v=Qng2RW_bjS8, check the actual debugging part.
Following VS code extension required
* C/C++ for Visual Studio Code
* C/C++ Extension Pack
* CMake Tools
* CMake For VisualStudio Code

Following the video a launch.json file should be created, make sure while building the executable to se the cmake flag for debug 