#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"
#include "point.h"
#include <string>

class Triangle : public Figure {
private:
    Point a, b, c;

public:
    Triangle(const string& name, const Point& a, const Point& b, const Point& c);
    string getName() const override;
    string getDescription() const override;
    double getArea() const override;
};

#endif
