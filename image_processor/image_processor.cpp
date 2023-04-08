#include "image_info/image.h"
#include "filters/crop.h"
#include "filters/edge_detection.h"
#include "filters/sharpening.h"
#include "filters/grayscale.h"
#include "filters/matrix.h"
#include "filters/negative.h"
#include "filters/my_filter.h"
#include <string>

int main(int argc, char** argv) {
    const char* read_path = argv[1];
    const char* export_path = argv[2];
    Image input;
    input.ReadBMP(read_path);
    if (argc < 3) {
        throw std::runtime_error("Error");
    }
    for (int i = 3; i < argc; ++i) {
        if (std::string(argv[i]) == "-crop") {
            if (argc < 5) {  // NOLINT
                throw std::runtime_error("Error");
            }
            Crop copy(input);
            copy.ApplyCropping(std::stoi(argv[i + 1]), std::stoi(argv[i + 2]));  // а?
        } else if (std::string(argv[i]) == "-neg") {
            Negative copy(input);
            copy.NegativeApply();
        } else if (std::string(argv[i]) == "-gs") {
            Grayscale copy(input);
            copy.ApplyGrayscale();
        } else if (std::string(argv[i]) == "-sharp") {
            Sharpening copy({{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}}, input);  // NOLINT
            copy.ApplySharpening();
        } else if (std::string(argv[i]) == "-3d") {
            if (argc < 5) {  // NOLINT
                throw std::runtime_error("Error");
            }
            ThreeDimension copy(input, std::stoi(argv[i + 1]), std::stof(argv[i + 2]));
            copy.ThreeDimensionApply();
        } else if (std::string(argv[i]) == "-edge") {
            if (argc < 5) {
                throw std::runtime_error("Error");
            }
            EdgeDetection copy({{0, -1, 0}, {-1, 4, -1}, {0, -1, 0}}, input, std::stof(argv[i + 1]));  // NOLINT
            copy.ApplyEdgeDetection();
        }
        input.SaveBMP(export_path);  // NOLINT
    }
    /*Image input;*/
    /*input.ReadBMP("../tasks/image_processor/test_script/data/lenna.bmp");
    Grayscale output(input);
    output.ApplyGrayscale();
    output.image_.SaveBMP("../tasks/image_processor/test_script/data/len.bmp");
    }*/

    /*else if (std::string(argv[i]) == "-sharp") {
        Sharpening copy({{0, -1, 0}, {-1, 4, -1}, {0, -1, 0}}, input);
        copy.ApplySharpening();*/
    /*} else if (std::string(argv[i]) == "-edge") {
                EdgeDetection copy({{0, -1, 0}, {-1, 4, -1}, {0, -1, 0}}, input, std::stof(argv[i + 1]) / 255.0);  //
       NOLINT copy.ApplyEdgeDetection();*/
}