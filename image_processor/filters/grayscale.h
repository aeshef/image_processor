#pragma once
#include "../image_info/image.h"

class Grayscale {

public:
    explicit Grayscale(Image& image);
    void ApplyGrayscale();
    Image& image_;
};