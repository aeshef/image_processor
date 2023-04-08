#include "image.h"

Image::Image(int width, int height) {
    height_ = height;
    width_ = width;
    colours_ = std::vector<std::vector<RGB>>(height_, std::vector<RGB>(width_));
}

Image::Image(std::vector<std::vector<RGB>> colours_matrix) {
    try {
        colours_ = colours_matrix;
        width_ = static_cast<int>(colours_[0].size());
        height_ = static_cast<int>(colours_.size());  //
    } catch (...) {
        throw std::runtime_error("Image is empty");
    }
}

Image::Image(const char *path) {
    Image::ReadBMP(path);
}

void Image::SetColour(RGB set, int x, int y) {
    colours_[y][x].r = set.r;
    colours_[y][x].g = set.g;
    colours_[y][x].b = set.b;
}

Size Image::GetSize() const {
    Size size;
    size.height = height_;
    size.width = width_;

    return size;
}

RGB Image::GetColour(int x, int y) const {
    return colours_[x][y];
}

std::vector<std::vector<RGB>> Image::GetMatrix() const {
    return colours_;
}