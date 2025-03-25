#include <string>
#include <vector>

struct Vertex {
    float x, y, z;
};

class ObjParser
{
    public:
        ObjParser();
        ObjParser(const std::string fileName);
        
        void parseObjFile();
        void printObjFile();

        void setFileName(std::string fileName);

        std::vector<Vertex> getVertices();
    private:
        std::string m_FileName;
        std::vector<Vertex> m_Vertices;
};
