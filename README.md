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

# Thrid party libraries
* Eigen: Eigen is a C++ template library for linear algebra: matrices, vectors, numerical solvers, and related algorithms,
dowload the latest version(3.4.0) https://eigen.tuxfamily.org/index.php?title=Main_Page, extract the library to the project directory where `CMakeLists.txt` file exist. If another version than 3.4.0 is downladed, make sure to update the `CMakeLists.txt` file and `.gitignore`. 

* Catch: Catch is a testing library for c++, using catch version 3, to make it  work FetchContent is used. For further details how to setup catch and make it work, check https://www.youtube.com/watch?v=eBByZNtnpFM, and the library documnetation https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md#automatic-test-registration.