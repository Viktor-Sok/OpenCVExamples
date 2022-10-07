#include "opencv2/opencv.hpp"
using namespace cv;
int main(int argc, char** argv)
{
    Mat original = imread("Uni.png", IMREAD_COLOR);
    Mat splitChannels[3]; // array to store 3 channels RGB
    split(original, splitChannels);
    // resulting image wiil be in gray scale which wiil represent intencity of b,g,r channels
    imshow("Blue", splitChannels[0]);
    imshow("Green", splitChannels[1]);
    imshow("Red", splitChannels[2]);
    splitChannels[2] = Mat::zeros(splitChannels[2].size(), CV_8U); // CV_8U - unsinged int 8 bits, i.e. this is teh data type for our zeros
    Mat output;
    merge(splitChannels, 3, output); // merging channels from Mat array splitChannels to the Mat output 
    imshow("Merged", output);
    waitKey();
    return 0;
}