#pragma once
#include <cstdint>

struct RGB {
    double r = .0;
    double g = .0;
    double b = .0;
    RGB(){};
    ~RGB(){};
    RGB(double r_set, double g_set, double b_set);
    RGB(const RGB& other);
    RGB& operator=(const RGB& rgb);
};