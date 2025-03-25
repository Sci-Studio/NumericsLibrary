
#include "parser/objparser.h"
#include "delaunay/delaunay.h"

#include <iostream>  // Include the I/O stream library

int main() {
    
    ObjParser parser("../../Data/rectangle-prism-final.obj");
    parser.parseObjFile();
    parser.printObjFile();

    DelaunayMeshGeneration delaunay(parser.getVertices());
    delaunay.printPoints();
    
    return 0;  // Return 0 to indicate successful execution
}