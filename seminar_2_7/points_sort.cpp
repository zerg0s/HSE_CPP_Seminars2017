/* Выведите все исходные точки в порядке
убывания их расстояний от начала координат.
Создайте структуру Point
и сохраните исходные данные в векторе структур Point. */

#ifndef Point_
#define Point_

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
    
    //конструктор структуры Point
    Point(double x, double y) : x(x), y(y) {}
    
    //переопределение оператора меньше для std::sort
    bool operator < (const Point& other) {
        double d1 = sqrt(x * x + y * y);
        double d2 = sqrt(other.x * other.x + other.y * other.y);
        return d1 > d2;
    }
};

void sortPoints() {
    vector<Point> points;
    points.emplace_back(1, 2);
    points.emplace_back(3, 4);
    points.emplace_back(0, 0);
    sort(points.begin(), points.end());
    for(const auto& point : points) {
        cout << "Point: " << point.x << " " << point.y << endl;
    }
}

#endif
