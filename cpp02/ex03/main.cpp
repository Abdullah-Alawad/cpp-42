#include "Point.hpp"

void testBsp(Point a, Point b, Point c, Point p, const char *description) {
    std::cout << description << ": " << (bsp(a,b,c,p) ? "Inside" : "Outside") << "\n";
}
int main()
{
    // Triangle vertices
    Point A(0, 0);
    Point B(10, 0);
    Point C(5, 10);

    // 1. Strictly inside points
    testBsp(A, B, C, Point(5, 5), "Center inside");
    testBsp(A, B, C, Point(4, 3), "Closer to A inside");
    testBsp(A, B, C, Point(7, 3), "Closer to B inside");
    testBsp(A, B, C, Point(5, 7), "Closer to C inside");

    // 2. On vertices
    testBsp(A, B, C, A, "Vertex A");
    testBsp(A, B, C, B, "Vertex B");
    testBsp(A, B, C, C, "Vertex C");

    // 3. On edges (midpoints)
    testBsp(A, B, C, Point(5, 0), "Edge AB midpoint");
    testBsp(A, B, C, Point(2.5, 5), "Edge AC midpoint");
    testBsp(A, B, C, Point(7.5, 5), "Edge BC midpoint");

    // 4. Near edges (inside, not on edge)
    testBsp(A, B, C, Point(5, 0.1f), "Near AB inside");
    testBsp(A, B, C, Point(2.6, 5.1f), "Near AC inside");
    testBsp(A, B, C, Point(7.4, 5.1f), "Near BC inside");

    // 5. Outside points
    testBsp(A, B, C, Point(-1, 5), "Outside left");
    testBsp(A, B, C, Point(11, 5), "Outside right");
    testBsp(A, B, C, Point(5, 11), "Outside top");
    testBsp(A, B, C, Point(5, -1), "Outside bottom");

    // 6. Negative coordinates inside
    Point D(-5, -5);
    Point E(-1, 0);
    Point F(-5, 2);
    testBsp(D, E, F, Point(-4, -1), "Negative inside");
    testBsp(D, E, F, D, "Negative vertex");
    testBsp(D, E, F, Point(-5, 0), "Negative edge midpoint");

    return 0;
}