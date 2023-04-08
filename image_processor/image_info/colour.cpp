#include "colour.h"

RGB::RGB(double r_set, double g_set, double b_set) {
    r = r_set;
    b = b_set;
    g = g_set;
}

RGB::RGB(const RGB& other) {
    r = other.r;
    g = other.g;
    b = other.b;
}

RGB& RGB::operator=(const RGB& rgb) {
    r = rgb.r;
    g = rgb.g;
    b = rgb.b;
    return *this;
}
