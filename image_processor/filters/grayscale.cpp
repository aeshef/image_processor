#include "grayscale.h"
#include <vector>

Grayscale::Grayscale(Image& image) : image_(image) {
}

void Grayscale::ApplyGrayscale() {
    std::vector<std::vector<RGB>> image_matrix = image_.GetMatrix();

    const float r_gs = 0.299;
    const float g_gs = 0.587;
    const float b_gs = 0.114;

    for (int y = 0; y < image_.GetSize().height; ++y) {
        for (int x = 0; x < image_.GetSize().width; ++x) {
            double anannas = r_gs * image_matrix[y][x].r + g_gs * image_matrix[y][x].g + b_gs * image_matrix[y][x].b;
            image_.SetColour({anannas, anannas, anannas}, x, y);  // NOLINT
        }
    }
}
