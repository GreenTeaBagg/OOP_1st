#include "figure_factory.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include <memory>
#include <iostream>

unique_ptr<Figure> FigureFactory::createCircle() {
    string name;
    askName(name);
    double x, y, r;
    cout << "Enter center coordinates (x y): ";
    cin >> x >> y;
    cout << "Enter radius: ";
    cin >> r;

    unique_ptr<Figure> result;
    try {
        result = make_unique<Circle>(name, Point(x, y), r);
    } catch (...) {
        cerr << "Error creating circle.\n";
    }
    return result;
}


unique_ptr<Figure> FigureFactory::createRectangle() {
    string name;
    askName(name);
    double x1, y1, x2, y2;
    cout << "Enter the coordinates of two opposite corners (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    unique_ptr<Figure> result;
    try {
        result = make_unique<Rectangle>(name, Point(x1, y1), Point(x2, y2));
    } catch (...) {
        cerr << "Error creating rectangle.\n";
    }
    return result;
}



unique_ptr<Figure> FigureFactory::createTriangle() {
    string name;
    askName(name);
    double x1, y1, x2, y2, x3, y3;
    cout << "Enter the coordinates of the three vertices (x1 y1 x2 y2 x3 y3): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    unique_ptr<Figure> result;
    try {
        result = make_unique<Triangle>(name, Point(x1, y1), Point(x2, y2), Point(x3, y3));
    } catch (...) {
        cerr << "Error creating triangle.\n";
    }
    return result;
}


string FigureFactory::askName(string &name) {
    cout << "Enter a name for the shape: ";
    cin >> name;
    return name;
}
