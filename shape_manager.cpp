#include "shape_manager.h"
#include <algorithm>

double ShapeManager::calculateTotalArea(const vector<unique_ptr<Figure>>& figures) {
    double total = 0;
    for (const auto& fig : figures) {
        total += fig->getArea();
    }
    return total;
}

void ShapeManager::sortByArea(vector<unique_ptr<Figure>>& figures) {
    sort(figures.begin(), figures.end(), [](const auto& a, const auto& b) {
        return a->getArea() < b->getArea();
    });
}

bool ShapeManager::deleteByIndex(vector<unique_ptr<Figure>>& figures, int index) {
    if (index < 1 || index > static_cast<int>(figures.size())) {
        return false;
    }
    figures.erase(figures.begin() + index - 1);
    return true;
}

int ShapeManager::deleteFiguresAboveArea(vector<unique_ptr<Figure>>& figures, double threshold) {
    auto it = remove_if(figures.begin(), figures.end(), [threshold](const unique_ptr<Figure>& fig) {
        return fig->getArea() > threshold;
    });
    int removed = static_cast<int>(distance(it, figures.end()));
    figures.erase(it, figures.end());
    return removed;
}
