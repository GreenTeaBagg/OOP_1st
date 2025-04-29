#ifndef FIGURE_H
#define FIGURE_H

#include <string>
#include "point.h"
#include <iostream>

using namespace std;
constexpr double EPS = 1e-6;

class Figure {
protected:
    string name;

public:
    Figure() = default;
    Figure(const string& name) : name(name) {}
    virtual ~Figure() = default;
    virtual string getName() const = 0;
    virtual string getDescription() const = 0;
    virtual double getArea() const = 0;
};

#endif
