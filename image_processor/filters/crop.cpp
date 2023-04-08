#include "crop.h"

Crop::Crop(Image& image) : image_(image) {
}

void Crop::ApplyCropping(int cropped_width, int cropped_height) {
    int width_given = image_.GetSize().width;
    int height_given = image_.GetSize().height;

    int width_cropped = std::min(width_given, cropped_width);
    int height_cropped = std::min(height_given, cropped_height);

    std::vector<std::vector<RGB>> given_vector_matrix = image_.GetMatrix();
    std::vector<std::vector<RGB>> cropped_image;

    /*if (height_given == height_cropped && width_given == width_cropped) {
        throw std::runtime_error("The size of the cropped image is equal to the initial picture size");
    }
    */

    for (auto& rgb_vector : given_vector_matrix) {
        rgb_vector.resize(width_cropped);
    }

    for (int i = 0; i < height_cropped; ++i) {
        given_vector_matrix[height_given - i - 1].resize(width_cropped);
        cropped_image.push_back(given_vector_matrix[height_given - i - 1]);
    }
    std::reverse(cropped_image.begin(), cropped_image.end());
    image_ = Image(cropped_image);
}