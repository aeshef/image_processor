#pragma once

#include "matrix.h"
#include "../image_info/image.h"

class Sharpening : public Matrix {
    Image& image_;
    Matrix matrix_ = Matrix({{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}}, image_);  // NOLINT

public:
    Sharpening(std::vector<std::vector<int>> matrix, Image& image);
    void ApplySharpening();
};
