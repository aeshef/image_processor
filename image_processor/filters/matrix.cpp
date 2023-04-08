#include "matrix.h"
#include <iostream>

Matrix::Matrix(std::vector<std::vector<int>> matrix, Image& image) : matrix_(matrix), image_(image) {
}

void Matrix::ApplyMatrix() {
    if (matrix_.size() != 3 || matrix_[0].size() != 3) {
        return;
    }

    int width = image_.GetSize().width;
    int height = image_.GetSize().height;
    std::vector<std::vector<RGB>> image_copy;
    std::vector<RGB> stroka;
    RGB nulls = RGB();

    image_copy.push_back(std::vector<RGB>(width + 2, nulls));

    std::vector<std::vector<RGB>> image_matrix_for_nulls = image_.GetMatrix();

    for (int y = 0; y < height; ++y) {
        stroka.push_back(nulls);
        for (int x = 0; x < width; ++x) {
            stroka.push_back(image_matrix_for_nulls[y][x]);
        }
        stroka.push_back(nulls);
        image_copy.push_back(stroka);
        stroka.clear();
    }

    image_copy.push_back(std::vector<RGB>(width + 2, nulls));

    for (auto i = 1; i < width + 1; ++i) {
        image_copy[0][i] = image_.GetColour(0, i - 1);
        image_copy[height + 1][i] = image_.GetColour(height - 1, i - 1);
    }

    for (auto i = 1; i < height + 1; ++i) {
        image_copy[i][0] = image_.GetColour(i - 1, 0);
        image_copy[i][width + 1] = image_.GetColour(i - 1, width - 1);
    }

    image_copy[0][0] = image_.GetColour(0, 0);
    image_copy[0][width + 1] = image_.GetColour(0, width - 1);
    image_copy[height + 1][0] = image_.GetColour(height - 1, 0);
    image_copy[height + 1][width + 1] = image_.GetColour(height - 1, width - 1);

    double ananas_r = .0;
    double ananas_g = .0;
    double ananas_b = .0;

    for (int x = 1; x < height + 1; ++x) {
        for (int y = 1; y < width + 1; ++y) {
            ananas_r = std::min(
                1.0, std::max(0., ((matrix_[0][1]) * image_copy[x][y - 1].r + (matrix_[1][0]) * image_copy[x - 1][y].r +
                                   (matrix_[1][1]) * image_copy[x][y].r + (matrix_[1][2]) * image_copy[x + 1][y].r +
                                   (matrix_[2][1]) * image_copy[x][y + 1].r)));
            ananas_g = std::min(
                1.0, std::max(0., ((matrix_[0][1]) * image_copy[x][y - 1].g + (matrix_[1][0]) * image_copy[x - 1][y].g +
                                   (matrix_[1][1]) * image_copy[x][y].g + (matrix_[1][2]) * image_copy[x + 1][y].g +
                                   (matrix_[2][1]) * image_copy[x][y + 1].g)));
            ananas_b = std::min(
                1.0, std::max(0., ((matrix_[0][1]) * image_copy[x][y - 1].b + (matrix_[1][0]) * image_copy[x - 1][y].b +
                                   (matrix_[1][1]) * image_copy[x][y].b + (matrix_[1][2]) * image_copy[x + 1][y].b +
                                   (matrix_[2][1]) * image_copy[x][y + 1].b)));
            image_.SetColour({ananas_r, ananas_g, ananas_b}, y - 1, x - 1);
        }
    }
}

/*for (int x = 1; x < height + 1; ++x) {
        for (int y = 1; y < width + 1; ++y) {
            if (x == 1 and y == 1) {
                image_matrix[x][y].r = image_matrix[x + 1][y + 1].r;
                image_matrix[x][y].g = image_matrix[x + 1][y + 1].g;
                image_matrix[x][y].b = image_matrix[x + 1][y + 1].b;
                continue;
            } else if (x == height - 2 and y == width - 2) {
                image_matrix[x][y].r = image_matrix[x - 1][y - 1].r;
                image_matrix[x][y].g = image_matrix[x - 1][y - 1].g;
                image_matrix[x][y].b = image_matrix[x - 1][y - 1].b;
                continue;
            } else if (x == 1 and y == width - 2) {
                image_matrix[x][y].r = image_matrix[x + 1][y - 1].r;
                image_matrix[x][y].g = image_matrix[x + 1][y - 1].g;
                image_matrix[x][y].b = image_matrix[x + 1][y - 1].b;
                continue;
            } else if (x == height - 2 and y == 1) {
                image_matrix[x][y].r = image_matrix[x - 1][y + 1].r;
                image_matrix[x][y].g = image_matrix[x - 1][y + 1].g;
                image_matrix[x][y].b = image_matrix[x - 1][y + 1].b;
                continue;
            } else if (x == 1) {
                image_matrix[x][y].r = image_matrix[x + 1][y].r;
                image_matrix[x][y].g = image_matrix[x + 1][y].g;
                image_matrix[x][y].b = image_matrix[x + 1][y].b;
                continue;
            } else if (y == 1) {
                image_matrix[x][y].r = image_matrix[x][y + 1].r;
                image_matrix[x][y].g = image_matrix[x][y + 1].g;
                image_matrix[x][y].b = image_matrix[x][y + 1].b;
                continue;
            } else if (x == height - 2) {
                image_matrix[x][y].r = image_matrix[x - 1][y].r;
                image_matrix[x][y].g = image_matrix[x - 1][y].g;
                image_matrix[x][y].b = image_matrix[x - 1][y].b;
                continue;
            } else if (y == width - 2) {
                image_matrix[x][y].r = image_matrix[x][y - 1].r;
                image_matrix[x][y].g = image_matrix[x][y - 1].g;
                image_matrix[x][y].b = image_matrix[x][y - 1].b;
                continue;
            }
        }
    }*/
