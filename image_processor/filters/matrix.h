#pragma once

#include <deque>
#include <vector>
#include <cmath>
#include <numbers>
#include <algorithm>
#include "../image_info/image.h"

class Matrix {
private:
    std::vector<std::vector<int>> matrix_;
    Image& image_;

public:
    Matrix(std::vector<std::vector<int>> matrix, Image& image);
    ~Matrix(){};
    void ApplyMatrix();
};
