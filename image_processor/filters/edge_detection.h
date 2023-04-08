#pragma once

#include "matrix.h"
#include "grayscale.h"

class EdgeDetection : Matrix {
    Image& image_;
    Matrix matrix_ = Matrix({{0, -1, 0}, {-1, 4, -1}, {0, -1, 0}}, image_);  // NOLINT
    double threshold_;

public:
    EdgeDetection(std::vector<std::vector<int>> matrix, Image& image, double threshold);
    void ApplyEdgeDetection();
};
