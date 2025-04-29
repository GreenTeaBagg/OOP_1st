#ifndef MENU_H
#define MENU_H

#include "figure.h"
#include "figure_factory.h"
#include <vector>
#include <memory>
#include <map>
#include <functional>

enum figuresMap {
    CIRCLE = 1,
    RECTANGLE,
    TRIANGLE
};

enum MenuOption {
    ADD_FIGURE = 1,
    OUTPUT_INFO,
    OUTPUT_AREAS,
    PRINT_AREAS_SUM,
    SORT_AREAS,
    DELETE_BY_NUM,
    DELETE_LARGER_AREAS,
    EXIT
};

class Menu {
private:
    vector<unique_ptr<Figure>> figures;

    void displayMenu() const;
    void addCircle();
    void addRectangle();
    void addTriangle();
    void initializeFigure();
    void handleShowFullInfo() const;
    void handleShowAreas() const;
    void handleTotalArea() const;
    void handleSortByArea();
    void handleDeleteFigure();
    void handleDeleteFiguresAboveThreshold();
    void initializeCommands();

    map<int, function<void()>> commandMap;
    map<int, function<void()>> figureMap;

public:
    void run();
};

#endif
