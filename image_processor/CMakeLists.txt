add_executable(image_processor
        image_processor.cpp
        read_export/reader.cpp
        image_info/image.cpp
        image_info/colour.cpp
        filters/gaussian_blur.cpp
        filters/edge_detection.cpp
        filters/grayscale.cpp
        filters/negative.cpp
        filters/sharpening.cpp
        filters/my_filter.cpp
        filters/crop.cpp
        image_info/colour.cpp
        filters/matrix.cpp)

