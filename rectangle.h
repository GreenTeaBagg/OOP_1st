#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"
#include "point.h"
#include <string>

class Rectangle : public Figure {
private:
    Point p1;
    Point p2;

public:
    Rectangle(const string& name, const Point& p1, const Point& p2);
    string getName() const override;
    string getDescription() const override;
    double getArea() const override;
};

#endif
