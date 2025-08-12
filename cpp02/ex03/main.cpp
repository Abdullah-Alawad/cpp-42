#include "Point.hpp"

void testBsp(Point a, Point b, Point c, Point p, const char *description) {
    std::cout << description << ": " << (bsp(a,b,c,p) ? "Inside" : "Outside") << "\n";
}

int main() {
    // Triangle vertices
    Point A(0, 0);
    Point B(10, 0);
    Point C(5, 10);

    // 1. Inside
    testBsp(A, B, C, Point(5, 5), "Inside case");

    // 2. On vertex
    testBsp(A, B, C, Point(0, 0), "On vertex (A)");

    // 3. On edge AB
    testBsp(A, B, C, Point(5, 0), "On edge AB");

    // 4. Outside
    testBsp(A, B, C, Point(10, 10), "Outside case");

    // 5. Negative coordinates
    testBsp(Point(-5, -5), Point(0, 0), Point(-5, 5), Point(-5, 0), "Negative coords - On edge");
    testBsp(Point(-5, -5), Point(0, 0), Point(-5, 5), Point(-4, 0), "Negative coords - Inside");

    // 6. Floating point precision issue (almost on edge)
    testBsp(A, B, C, Point(5, 0.0001f), "Near edge - should be inside");
}