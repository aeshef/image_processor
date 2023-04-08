#include "../image_info/image.h"

#include <string>
#include <fstream>

void Image::ReadBMP(const char *path) {
    std::ifstream f;
    f.open(path, std::ios::in | std::ios::binary);
    if (!f.is_open()) {
        throw std::runtime_error("File not opened");
    }
    const int file_header_size = 14;
    const int information_header_size = 40;
    unsigned char file_header[file_header_size];
    f.read(reinterpret_cast<char *>(file_header), file_header_size);
    if (file_header[0] != 'B' || file_header[1] != 'M') {
        f.close();
        throw std::runtime_error("File not opened");
    }
    unsigned char information_header[information_header_size];
    f.read(reinterpret_cast<char *>(information_header), information_header_size);
    /*    int fileSize = fileHeader[2] + (fileHeader[3] << 8) + (fileHeader[4] << 16) + (fileHeader[5] << 24);  //
     * NOLINT*/
    width_ = information_header[4] + (information_header[5] << 8) + (information_header[6] << 16) +    // NOLINT
             (information_header[7] << 24);                                                            // NOLINT
    height_ = information_header[8] + (information_header[9] << 8) + (information_header[10] << 16) +  // NOLINT
              (information_header[11] << 24);                                                          // NOLINT
    RGB help(0, 0, 0);
    colours_.resize(height_);
    for (size_t i = 0; i < height_; ++i) {
        colours_[i].resize(width_);
        for (size_t j = 0; j < width_; ++j) {
            colours_[i][j] = help;
        }
    }
    const int padding_amount = ((4 - (width_ * 3) % 4) % 4);
    for (int y = 0; y < height_; ++y) {
        for (int x = 0; x < width_; ++x) {
            unsigned char color[3];
            f.read(reinterpret_cast<char *>(color), 3);
            colours_[y][x].r = static_cast<float>(color[2]) / 255.0f;  // NOLINT
            colours_[y][x].g = static_cast<float>(color[1]) / 255.0f;  // NOLINT
            colours_[y][x].b = static_cast<float>(color[0]) / 255.0f;  // NOLINT
        }
        f.ignore(padding_amount);
    }
    f.close();
};

void Image::SaveBMP(const char *path) {  // NOLINT
    std::ofstream f;
    f.open(path, std::ios::out | std::ios::binary);
    if (!f.is_open()) {
        throw std::runtime_error("File not opened");
    }
    unsigned char bmp_pad[3] = {0, 0, 0};
    const int padding_amount = ((4 - (width_ * 3) % 4) % 4);
    const int file_header_size = 14;
    const int information_header_size = 40;
    const int file_size = file_header_size + information_header_size + width_ * height_ * 3 + padding_amount * width_;
    unsigned char file_header[file_header_size];
    file_header[0] = 'B';
    file_header[1] = 'M';
    file_header[2] = file_size;
    file_header[3] = file_size >> 8;                               // NOLINT
    file_header[4] = file_size >> 16;                              // NOLINT
    file_header[5] = file_size >> 24;                              // NOLINT
    file_header[6] = 0;                                            // NOLINT
    file_header[7] = 0;                                            // NOLINT
    file_header[8] = 0;                                            // NOLINT
    file_header[9] = 0;                                            // NOLINT
    file_header[10] = file_header_size + information_header_size;  // NOLINT
    file_header[11] = 0;                                           // NOLINT
    file_header[12] = 0;                                           // NOLINT
    file_header[13] = 0;                                           // NOLINT
    unsigned char informationHeader[information_header_size];      // NOLINT
    informationHeader[0] = information_header_size;
    informationHeader[1] = 0;
    informationHeader[2] = 0;
    informationHeader[3] = 0;
    informationHeader[4] = width_;
    informationHeader[5] = width_ >> 8;     // NOLINT
    informationHeader[6] = width_ >> 16;    // NOLINT
    informationHeader[7] = width_ >> 24;    // NOLINT
    informationHeader[8] = height_;         // NOLINT
    informationHeader[9] = height_ >> 8;    // NOLINT
    informationHeader[10] = height_ >> 16;  // NOLINT
    informationHeader[11] = height_ >> 24;  // NOLINT
    informationHeader[12] = 1;              // NOLINT
    informationHeader[13] = 0;              // NOLINT
    informationHeader[14] = 24;             // NOLINT
    informationHeader[15] = 0;              // NOLINT
    informationHeader[16] = 0;              // NOLINT
    informationHeader[17] = 0;              // NOLINT
    informationHeader[18] = 0;              // NOLINT
    informationHeader[19] = 0;              // NOLINT
    informationHeader[20] = 0;              // NOLINT
    informationHeader[21] = 0;              // NOLINT
    informationHeader[22] = 0;              // NOLINT
    informationHeader[23] = 0;              // NOLINT
    informationHeader[24] = 0;              // NOLINT
    informationHeader[25] = 0;              // NOLINT
    informationHeader[26] = 0;              // NOLINT
    informationHeader[27] = 0;              // NOLINT
    informationHeader[28] = 0;              // NOLINT
    informationHeader[29] = 0;              // NOLINT
    informationHeader[30] = 0;              // NOLINT
    informationHeader[31] = 0;              // NOLINT
    informationHeader[32] = 0;              // NOLINT
    informationHeader[33] = 0;              // NOLINT
    informationHeader[34] = 0;              // NOLINT
    informationHeader[35] = 0;              // NOLINT
    informationHeader[36] = 0;              // NOLINT
    informationHeader[37] = 0;              // NOLINT
    informationHeader[38] = 0;              // NOLINT
    informationHeader[39] = 0;              // NOLINT
    f.write(reinterpret_cast<char *>(file_header), file_header_size);
    f.write(reinterpret_cast<char *>(informationHeader), information_header_size);
    for (int y = 0; y < height_; ++y) {
        for (int x = 0; x < width_; ++x) {
            unsigned char r = static_cast<unsigned char>(GetColour(y, x).r * 255.0f);  // NOLINT
            unsigned char g = static_cast<unsigned char>(GetColour(y, x).g * 255.0f);  // NOLINT
            unsigned char b = static_cast<unsigned char>(GetColour(y, x).b * 255.0f);  // NOLINT
            unsigned char color[] = {b, g, r};
            f.write(reinterpret_cast<char *>(color), 3);
        }
        f.write(reinterpret_cast<char *>(bmp_pad), padding_amount);
    }
    f.close();
}
