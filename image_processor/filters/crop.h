#pragma once

#include "crop.h"
#include "../image_info/image.h"

class Crop {
    Image& image_;

public:
    explicit Crop(Image& image);
    ~Crop(){};
    void ApplyCropping(int cropped_width, int cropped_height);
};
