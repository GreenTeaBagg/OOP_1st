#ifndef CIRCLE_H
#define CIRCLE_H

#include "figure.h"
#include "point.h"
#include <string>

class Circle : public Figure {
private:
    Point center;
    double radius;

public:
    Circle(const string& name, const Point& center, double radius);
    string getName() const override;
    string getDescription() const override;
    double getArea() const override;
};

#endif
