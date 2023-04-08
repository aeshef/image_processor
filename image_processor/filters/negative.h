#pragma once
#include "../image_info/image.h"

class Negative {
private:
    Image& image_;

public:
    explicit Negative(Image& image);
    void NegativeApply();
};