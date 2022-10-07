#include "opencv2/opencv.hpp"
using namespace cv;
int main(int argc, char** argv)
{
    Mat testColor = imread("Uni.png", IMREAD_COLOR); // IMREAD_COLOR is a flag, Mat = matrix
    Mat testGray = imread("Uni.png", IMREAD_GRAYSCALE);
    imshow("color", testColor); // "coolor" is a name of output window
    imshow("gray", testGray);
    imwrite("Uni_gray.png", testGray); //saving image
    waitKey(); // cv function to wait for a key being pressed befor closing the window
    return 0;
}