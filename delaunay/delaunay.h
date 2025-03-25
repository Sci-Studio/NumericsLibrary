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
    bool isBad = false; // Flag for illegal triangles
 };

class DelaunayMeshGeneration 
{
    public:
        DelaunayMeshGeneration(std::vector<Vertex> vetrices);

        bool isInsideCircumcircle(const Point& p, const DelaunayTriangle& t);
        std::vector<DelaunayTriangle> delaunayTriangulation(std::vector<Point>& points);
    
        void printPoints();

    private:
        std::vector<Point> m_Points;
};

#endif // DELAUNAY_H
