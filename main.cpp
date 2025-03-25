
#include "parser/objparser.h"
#include <iostream>  // Include the I/O stream library

int main() {
    // Print "Hello, World!" to the console
    std::cout << "Hello, World!" << std::endl;
    ObjParser parser("../../Data/rectangle-prism-final.obj");
    parser.parseObjFile();
    parser.printObjFile();

    return 0;  // Return 0 to indicate successful execution
}