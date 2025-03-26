#define CATCH_CONFIG_MAIN
#include "../delaunay/delaunay.h" 

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE( "Is Inside Circumcircle", "[TestCircumcircle]") {
    std::vector<Vertex> vetices = {
        { 50.0f, -25.0f,  0.0f },
    };

    DelaunayMeshGeneration delaunay(vetices);
    Point pInside = { 2.0f, 1.0f };
    Point pOutside = { 5.0f, 5.0f };

    Point p1 = { 0.0f, 0.0f };
    Point p2 = { 4.0f, 0.0f };
    Point p3 = { 2.0f, 3.0f };
    DelaunayTriangle triangle = { p1, p2, p3 };

    REQUIRE(delaunay.isInsideCircumcircle(pInside, triangle) == true);
    REQUIRE(delaunay.isInsideCircumcircle(pOutside, triangle) == false);

}