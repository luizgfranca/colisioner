#pragma once

class Point {
public:
    int x;
    int y;

    Point(int x, int y);
    void set_coordinates(int x, int y);
    int * get_coordinates();

    unsigned int get_distance_from(Point b);
};