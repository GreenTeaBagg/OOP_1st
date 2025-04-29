#ifndef SHAPE_MANAGER_H
#define SHAPE_MANAGER_H

#include "figure.h"
#include <vector>
#include <memory>

class ShapeManager {
public:
    static double calculateTotalArea(const vector<unique_ptr<Figure>>& figures);

    static void sortByArea(vector<unique_ptr<Figure>>& figures);

    static bool deleteByIndex(vector<unique_ptr<Figure>>& figures, int index);

    static int deleteFiguresAboveArea(vector<unique_ptr<Figure>>& figures, double threshold);
};

#endif
