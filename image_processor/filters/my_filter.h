#pragma once

#include "../image_info/image.h"

class ThreeDimension {
public:
    Image& image_;
    int shift_;
    double shade_;
    explicit ThreeDimension(Image& image, int shift, double shade);
    void ThreeDimensionApply();
};