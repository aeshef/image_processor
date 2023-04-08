#include "my_filter.h"
#include "../image_info/image.h"

ThreeDimension::ThreeDimension(Image& image, int shift, double shade) : image_(image), shift_(shift), shade_(shade) {
}

void ThreeDimension::ThreeDimensionApply() {
    int height = image_.GetSize().height;
    int width = image_.GetSize().width;

    std::vector<std::vector<RGB>> red_matrix = image_.GetMatrix();
    Image image_red = Image(red_matrix);

    for (int x = 0; x < height; ++x) {
        for (int y = 0; y < width; ++y) {
            image_red.SetColour({red_matrix[x][y].r, shade_, shade_}, y, x);  // NOLINT
        }
    }

    std::vector<std::vector<RGB>> blue_matrix = image_.GetMatrix();
    ;
    Image image_blue = Image(blue_matrix);

    for (int x = 0; x < height; ++x) {
        for (int y = 0; y < width; ++y) {
            image_.SetColour({shade_, shade_, blue_matrix[x][y].b}, y, x);  // NOLINT
        }
    }

    Image three_dimension = image_;

    for (int x = 0; x < shift_; ++x) {
        for (int y = 0; y < width; ++y) {
            three_dimension.SetColour(image_red.GetColour(y, x), x, y);  // NOLINT
        }
    }
    /*
    for (int x = shift_; x < height; ++x) {
        for (int y = 0; y < width; ++y) {
            three_dimension.SetColour(image_blue.GetColour(y, x - shift_), x - shift_, y);  // NOLINT
        }
    }*/
    image_ = three_dimension;
}
