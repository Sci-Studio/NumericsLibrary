#include "delaunay.h"

#include <iostream>

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