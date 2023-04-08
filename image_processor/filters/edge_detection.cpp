#include "edge_detection.h"

EdgeDetection::EdgeDetection(std::vector<std::vector<int>> matrix, Image& image, double threshold)
    : Matrix(matrix, image), image_(image), threshold_(threshold) {
}

void EdgeDetection::ApplyEdgeDetection() {
    int width = image_.GetSize().width;
    int height = image_.GetSize().height;

    Grayscale copy(image_);
    copy.ApplyGrayscale();

    std::vector<std::vector<RGB>> image_matrix = image_.GetMatrix();

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (image_matrix[y][x].r > threshold_ || image_matrix[y][x].g > threshold_ || image_matrix[y][x].b > threshold_) {
                image_.SetColour({0, 0, 0}, x, y);
            } else {
                image_.SetColour({1, 1, 1}, x, y);
            }
        }
    }
}