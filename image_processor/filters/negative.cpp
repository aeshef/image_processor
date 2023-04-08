#include "negative.h"
#include <iostream>

Negative::Negative(Image& image) : image_(image) {
}

void Negative::NegativeApply() {
    int height = image_.GetSize().height;
    int width = image_.GetSize().width;
    std::vector<std::vector<RGB>> image_matrix = image_.GetMatrix();

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            image_.SetColour({1 - image_matrix[i][j].r, 1 - image_matrix[i][j].g, 1 - image_matrix[i][j].b}, j, i);
        }
    }
}
