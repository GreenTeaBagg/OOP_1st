#ifndef POINT_H
#define POINT_H

class Point {
public:
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
    double get_x() const { return x; }
    double get_y() const { return y; }

private:
    double x, y;
};

#endif
