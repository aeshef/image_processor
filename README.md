# BMP Image Processing Project

## Overview

This project focuses on implementing a BMP image processing application. The goal is to provide a platform for performing various operations on BMP (Bitmap) images, such as manipulation, enhancement, and analysis. The application is designed to be user-friendly, extensible, and efficient in processing BMP files.

## Filters

- **Crop (-crop width height)**
Trims the image to the specified width and height. The upper left side of the image is used.
If the requested width or height exceeds the size of the original image, the available part of the image is displayed.

- **Grayscale (-gs)**
Converts an image into gray by formula

- **Negative (-neg)**
Converts image to negative

- **Sharpening (-sharp)**
Sharpening. Achieved using a matrix

- **Edge Detection (-edge threshold)**
Selection of borders. The image is converted to grayscale and applied matrix
Pixels above threshold are colored white, others black.

- **Gaussian Blur (-blur sigma)**
Gaussian blur, parameter sigma.
## Getting Started

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/your-username/bmp-image-processing.git
   cd bmp-image-processing
   ```

2. **Install Dependencies:**
   
  ```py
  pip install -r requirements.txt
  ```

3. **Run the Application:**
  ```py
  python main.py
  ```
