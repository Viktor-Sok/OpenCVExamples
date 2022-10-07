#include "opencv2/opencv.hpp"
#include <iostream>
#include <cmath>
#include <tuple>
//#include <memory>
using namespace cv;

typedef std::tuple<cv::Size, int, int, Mat> userParamsTuple;
void createGaussian(Size const & size, Mat& output, int uX, int uY, float sigmaX, float sigmaY, float amplitude = 1.0f)
{
    Mat temp = Mat(size, CV_32F);
    for (int r = 0; r < size.height; ++r)
    {
        for(int c = 0; c < size.width; ++c)
        {
            float xTerm = (std::pow(c-uX,2)) / (2.0f*std::pow(sigmaX,2));
            float yTerm = (std::pow(r-uY,2)) / (2.0f*std::pow(sigmaY,2));
            float value = amplitude*std::exp(-(xTerm + yTerm)); // gaussinan value for pixel in specific column and row
            temp.at<float>(r,c) = value;
        }
    }
    normalize(temp, temp, 0.0f, 1.0f, NORM_MINMAX); // vormalization between 0 and 1 to visualize a s a picture
    output = temp;
}
void callBackFunction(int event, int x, int y, int flags, void* userdataTuple)
{
    
    if (event = EVENT_LBUTTONDOWN)
    {
        cv::Size size;
        int uX, uY;
        Mat output;
        std::tie(size, uX, uY, output) = *(userParamsTuple*)userdataTuple; // converting void* to a specific pointer
        createGaussian(size, output, uX, uY, x, y);
        std::get<3>(*(userParamsTuple*)userdataTuple) = output;
    }
}
int main(int argc, char** argv)
{
    Mat output;
    namedWindow("DrawCenteredGaussian", WINDOW_AUTOSIZE);
    //typedef std::unique_ptr<userParamsTuple> ptrUserParamsTuple;
    userParamsTuple argumentsForCallBack;
    //ptrUserParamsTuple ptr(new userParamsTuple(cv::Size(256,256), 256/2, 256/2));
    argumentsForCallBack = std::make_tuple(cv::Size(256,256), 256/2, 256/2, output); // passing arguments to the CallBack function
    setMouseCallback("DrawCenteredGaussian", callBackFunction, &argumentsForCallBack);
    imshow("Gaussian", std::get<3>(argumentsForCallBack));
    waitKey(); 
    return 0; 
}