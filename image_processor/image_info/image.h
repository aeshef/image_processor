#pragma once

#include "colour.h"
#include <vector>
#include <fstream>

const int FILE_HEADER_S = 14;
const int INFO_SIZE = 40;
const int RGB_INT = 3;
const float TO_FORMAT = 255.0f;

struct Size {
    int height;
    int width;
};

class Image {

private:
    std::vector<std::vector<RGB>> colours_;
    int height_;
    int width_;

public:
    Image(){};
    Image(int width, int height);
    explicit Image(const char* path);
    explicit Image(std::vector<std::vector<RGB>> colours_matrix);
    ~Image(){};
    RGB GetColour(int x, int y) const;
    Size GetSize() const;
    void SetColour(RGB set, int x, int y);
    std::vector<std::vector<RGB>> GetMatrix() const;

    void ReadBMP(const char* path);
    void SaveBMP(const char* path);
};