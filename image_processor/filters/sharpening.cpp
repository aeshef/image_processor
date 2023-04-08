#include "../image_info/image.h"
#include "matrix.h"
#include "sharpening.h"

Sharpening::Sharpening(std::vector<std::vector<int>> matrix, Image& image) : Matrix(matrix, image), image_(image) {
}

void Sharpening::ApplySharpening() {
    matrix_.ApplyMatrix();
}
