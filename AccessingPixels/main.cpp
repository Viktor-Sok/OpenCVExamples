#include "opencv2/opencv_modules.hpp"
//typedef unsigned char uint8_t; // for grayscale image instead fof cv::Vec3b
using namespace cv;
int main(int argc, char** argv)
{
    Mat original = imread("Uni.png", IMREAD_COLOR); //color image have blue, green , read channels (in this order in OpenCV)
    Mat modified = imread("Uni.png", IMREAD_COLOR);
    for (int r = 0; r < modified.rows; r++) 
    {
        for(int c = 0; c < modified.cols; c++)
        {
            //  Vec3b is 3D container with 1 byte (b) fro each element (becouse pixel has values 0 ... 255) 
            //we need 3D vector becouse each pixel has 3 channel RGB
            // 0.5f 32-bit float, modifying pixels at
            // getting read of green channel
            modified.at<cv::Vec3b>(r,c)[1] = modified.at<cv::Vec3b>(r,c)[1]*0; // [0] [1] [2] is blue, green, read channel   
        }
    }
    imshow("original", original);
    imshow("modified", modified);
    waitKey();
    

    
    return 0;
}