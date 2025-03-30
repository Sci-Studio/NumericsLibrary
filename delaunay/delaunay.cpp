#include "delaunay.h"

#include <Eigen/Dense>
#include <iostream>
#include <algorithm>

DelaunayMeshGeneration::DelaunayMeshGeneration(std::vector<Vertex> vetrices)
{
    for (const Vertex v : vetrices) {
        m_Points.push_back({v.x, v.y});
    }
}

void DelaunayMeshGeneration::printPoints()
{
    for (const Point p : m_Points) {
        std::cout << p.x << " " << p.y << std::endl;
    }
}

bool DelaunayMeshGeneration::isInsideCircumcircle(const Point& p, const DelaunayTriangle& t)
{
    Eigen::MatrixXd A(4, 4); 

    float ax = t.p1.x, ay = t.p1.y, 
          bx = t.p2.x, by = t.p2.y,
          cx = t.p3.x, cy = t.p3.y;

    float dx = p.x, dy = p.y;
    
    float ax_2_plus_ay_2 = (ax * ax) + (ay * ay),
          bx_2_plus_by_2 = (bx * bx) + (by * by),
          cx_2_plus_cy_2 = (cx * cx) + (cy * cy),
          dx_2_plus_dy_2 = (dx * dx) + (dy * dy);

    A << ax, ay, ax_2_plus_ay_2, 1,
         bx, by, bx_2_plus_by_2, 1,
         cx, cy, cx_2_plus_cy_2, 1,
         dx, dy, dx_2_plus_dy_2, 1;
    // float ax = t.p1.x - p.x, ay = t.p1.y - p.y;
    // float bx = t.p2.x - p.x, by = t.p2.y - p.y;
    // float cx = t.p3.x - p.x, cy = t.p3.y - p.y;

    // float det = (ax * (by * (cx*cx + cy*cy) - cy * (bx*bx + by*by)) -
    //              ay * (bx * (cx*cx + cy*cy) - cx * (bx*bx + by*by)) +
    //              (ax*ax + ay*ay) * (bx * cy - cx * by));

    float det = A.determinant(); 
    return det > 0; // Point is inside if determinant > 0
}


std::vector<DelaunayTriangle> DelaunayMeshGeneration::delaunayTriangulation() 
{
    float minX = m_Points[0].x, minY = m_Points[0].y;
    float maxX = minX, maxY = minY;

    for (const Point p : m_Points) 
    {
        minX = std::min(minX, p.x);
        minY = std::min(minY, p.y);
        maxX = std::max(maxX, p.x);
        maxY = std::max(maxY, p.y);
    }

    float dx = maxX - minX, dy = maxY - minY;
    float deltaMax = std::max(dx, dy);
    Point p1 = { minX - deltaMax, minY - deltaMax };
    Point p2 = { minX - deltaMax, maxY + deltaMax };
    Point p3 = { maxX + deltaMax, minY - deltaMax };
    m_Triangles.push_back({ p1, p2, p3 });

    for (const Point p : m_Points) {
        std::vector<DelaunayTriangle> newTriangles;
        std::vector<DelaunayTriangle> toRemove; 

        for (DelaunayTriangle t : m_Triangles) {
            if (isInsideCircumcircle(p, t)) {
                t.isBad = true;
                toRemove.push_back(t);
            }
        }
        // m_Triangles.erase(std::remove_if(m_Triangles.begin(), m_Triangles.end(),
        //     [](const DelaunayTriangle& t) { return t.isBad; }), m_Triangles.end());

        for (const auto& t : toRemove) {
            newTriangles.push_back({ t.p1, t.p2, p });
            newTriangles.push_back({ t.p2, t.p3, p });
            newTriangles.push_back({ t.p3, t.p1, p });
        }

        // Add new triangles
        for (const auto& t : newTriangles) {
            m_Triangles.push_back(t);
        }

        // m_Triangles.erase(std::remove_if(m_Triangles.begin(), m_Triangles.end(),
        // [&p1, &p2, &p3](const DelaunayTriangle& t) {
        //     return t.p1 == p1 || t.p1 == p2 || t.p1 == p3 ||
        //            t.p2 == p1 || t.p2 == p2 || t.p2 == p3 ||
        //            t.p3 == p1 || t.p3 == p2 || t.p3 == p3;
        // }), m_Triangles.end());
    }
    std::cout << m_Triangles.size() << std::endl;
    return m_Triangles;
}

void DelaunayMeshGeneration::printTriangles()
{
    for (const DelaunayTriangle t : m_Triangles) {
        std::cout << "Triangle, p1: " << t.p1.x << " " << t.p1.y << std::endl;
        std::cout << "Triangle, p2: " << t.p2.x << " " << t.p2.y << std::endl;
        std::cout << "Triangle, p3: " << t.p3.x << " " << t.p3.y << std::endl;
        std::cout << "-----------------------" << std::endl;
    }   
}
