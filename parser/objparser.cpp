#include "objparser.h"
#include <sstream>
#include <fstream>
#include <iostream>

ObjParser::ObjParser() {}

ObjParser::ObjParser(const std::string fileName)
    : m_FileName(fileName) {}

void ObjParser::parseObjFile()
{
    std::ifstream objFile(m_FileName);

    if(!objFile.is_open()) {
        std::cout << "Failed to open the OBJ file!" << std::endl;
        return;
    }

    std::string line;
    while(std::getline(objFile, line)) {
        if (line.substr(0, 2) == "v ") {
            std::istringstream iss(line.substr(2));
            Vertex v;
            iss >> v.x >> v.y >> v.z;
            m_Vertices.push_back(v);
        }
    }

    objFile.close();

}

void ObjParser::printObjFile() {
    std::cout << "Vertices:\n";
    for (const auto& v : m_Vertices) {
        std::cout << "v " << v.x << " " << v.y << " " << v.z << std::endl;;
    }
}
    