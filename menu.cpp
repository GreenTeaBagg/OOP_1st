#include "menu.h"
#include "figure_factory.h"
#include "shape_manager.h"
#include <limits>
#include <algorithm>
#include <iomanip>
#include <iostream>


void Menu::displayMenu() const {
    cout << "\nMENU:\n"
         << "1. Add a shape (circle / rectangle / triangle)\n"
         << "2. Show a list of shapes with parameters\n"
         << "3. Show list of figures with areas\n"
         << "4. Show the sum of all areas\n"
         << "5. Sort by area ascending\n"
         << "6. Delete figure by number\n"
         << "7. Delete figures with area greater than entered\n"
         << "8. Exit\n"
         << "Your choice: ";
}

void Menu::addCircle() {
    figures.push_back(FigureFactory::createCircle());
}

void Menu::addRectangle() {
    figures.push_back(FigureFactory::createRectangle());
}

void Menu::addTriangle() {
    figures.push_back(FigureFactory::createTriangle());
}

void Menu::initializeFigure() {
    figureMap = {
        {CIRCLE, [this]() { addCircle(); }},
        {RECTANGLE, [this]() { addRectangle(); }},
        {TRIANGLE, [this]() { addTriangle(); }}
    };

    int type;
    cout << "Select the type of figure:\n"
         << "1. Circle\n"
         << "2. Rectangle\n"
         << "3. Triangle\n"
         << "Your choice: ";
    cin >> type;

    auto it = figureMap.find(type);
    if (it != figureMap.end()) {
        it->second();
    } else {
        cout << "Wrong figure type.\n";
    }
}

void Menu::handleShowFullInfo() const {
    if (figures.empty()) {
        cout << "Collection is empty.\n";
        return;
    }

    for (size_t i = 0; i < figures.size(); ++i) {
        cout << i + 1 << ". " << figures[i]->getName()
        << " — " << figures[i]->getDescription() << "\n";
    }
}

void Menu::handleShowAreas() const {
    if (figures.empty()) {
        cout << "Collection is empty.\n";
        return;
    }

    for (size_t i = 0; i < figures.size(); ++i) {
        cout << i + 1 << ". " << figures[i]->getName()
        << " — Square: " << fixed << setprecision(2)
        << figures[i]->getArea() << "\n";
    }
}

void Menu::handleTotalArea() const {
    double totalArea = ShapeManager::calculateTotalArea(figures);
    cout << "Sum of the areas of all figures: " << fixed << setprecision(2)
         << totalArea << "\n";
}

void Menu::handleSortByArea() {
    ShapeManager::sortByArea(figures);
    cout << "The figures are sorted in ascending order of area.\n";
}

void Menu::handleDeleteFigure() {
    if (figures.empty()) {
        cout << "The list is empty.\n";
        return;
    }

    int index;
    cout << "Enter the number of the figure to delete: ";
    if (!(cin >> index)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input error.\n";
        return;
    }

    if (ShapeManager::deleteByIndex(figures, index)) {
        cout << "Figure removed.\n";
    } else {
        cout << "Invalid number.\n";
    }
}

void Menu::handleDeleteFiguresAboveThreshold() {
    double threshold;
    cout << "Enter area value: ";
    if (!(cin >> threshold)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Value entry error.\n";
        return;
    }

    int removed = ShapeManager::deleteFiguresAboveArea(figures, threshold);
    cout << "Removed figures: " << removed << "\n";
}

void Menu::initializeCommands() {
    commandMap = {
        {ADD_FIGURE, [this]() { initializeFigure(); }},
        {OUTPUT_INFO, [this]() { handleShowFullInfo(); }},
        {OUTPUT_AREAS, [this]() { handleShowAreas(); }},
        {PRINT_AREAS_SUM, [this]() { handleTotalArea(); }},
        {SORT_AREAS, [this]() { handleSortByArea(); }},
        {DELETE_BY_NUM, [this]() { handleDeleteFigure(); }},
        {DELETE_LARGER_AREAS, [this]() { handleDeleteFiguresAboveThreshold(); }},
        {EXIT, []() { cout << "Exit the program.\n"; }}
    };
}

void Menu::run() {
    initializeCommands();
    bool running = true;

    while (running) {
        displayMenu();

        int choice;
        bool validInput = static_cast<bool>(cin >> choice);

        if (!validInput) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.\n";
        } else if (choice == EXIT) {
            running = false;
        } else {
            auto cmd = commandMap.find(choice);
            if (cmd != commandMap.end()) {
                cmd->second();
            } else {
                cout << "Incorrect choice.\n";
            }
        }
    }
}
