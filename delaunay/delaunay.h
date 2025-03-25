#ifndef DELAUNAY_H
#define DELAUNAY_H

#include "../parser/objparser.h"

#include <vector>

struct Point {
    float x, y;
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

struct DelaunayTriangle { 
    Point p1, p2, p3;
    bool isBad; // Flag for illegal triangles

    DelaunayTriangle(const Point& a, const Point& b, const Point& c)
        : p1(a), p2(b), p3(c), isBad(false) {}
 };

class DelaunayMeshGeneration 
{
    public:
        DelaunayMeshGeneration(std::vector<Vertex> vetrices);

        bool isInsideCircumcircle(const Point& p, const DelaunayTriangle& t);
        std::vector<DelaunayTriangle> delaunayTriangulation();
    
        void printPoints();
        void printTriangles();

    private:
        std::vector<Point> m_Points;
        std::vector<DelaunayTriangle> m_Triangles;
};

#endif // DELAUNAY_H
