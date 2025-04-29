#include "triangle.h"
#include <cmath>
#include <stdexcept>

Triangle::Triangle(const string& name, const Point& a, const Point& b, const Point& c)
    : Figure(name), a(a), b(b), c(c) {
    double area = Triangle::getArea();
    if (area < EPS) {
        throw invalid_argument("Error: Triangle with zero area (vertices are collinear).");
    }
}

string Triangle::getName() const {
    return name;
}

string Triangle::getDescription() const {
    return "Triangle with vertices (" + to_string(a.get_x()) + ", " + to_string(a.get_y()) + "), (" +
           to_string(b.get_x()) + ", " + to_string(b.get_y()) + "), (" +
           to_string(c.get_x()) + ", " + to_string(c.get_y()) + ")";
}

double Triangle::getArea() const {
    return abs((a.get_x() * (b.get_y() - c.get_y()) +
                     b.get_x() * (c.get_y() - a.get_y()) +
                     c.get_x() * (a.get_y() - b.get_y())) / 2.0);
}
