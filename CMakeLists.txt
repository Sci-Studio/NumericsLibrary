cmake_minimum_required(VERSION 3.5)
project(NumericasLibrary)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
set(SOURCES
    main.cpp
    parser/objparser.cpp
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Include header directories
target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/parser
)