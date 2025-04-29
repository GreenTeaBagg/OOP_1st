#ifndef FIGURE_FACTORY_H
#define FIGURE_FACTORY_H

#include "figure.h"
#include <memory>
#include <string>

class FigureFactory {
public:
    static unique_ptr<Figure> createCircle();
    static unique_ptr<Figure> createRectangle();
    static unique_ptr<Figure> createTriangle();
    static string askName(string &name);
};

#endif
