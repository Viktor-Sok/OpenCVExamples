#include "opencv2/opencv.hpp"
using namespace cv;
void takeDFT(Mat& source, Mat& destination)
{
    Mat originalComplex[2] = {source, Mat::zeros(source.size(), CV_32F)}; // array of original and empty mat images
    // Creating two channels for storing  the real and imagenary part of DFT
    Mat dftReady; // Mat object with 2 channels for storing DFT results (real and imagenary part)
    merge(originalComplex, 2, dftReady);
    Mat dftOfOriginal;
    dft(dftReady, dftOfOriginal, DFT_COMPLEX_OUTPUT);
    destination = dftOfOriginal;

}
void recenterDFT(Mat& source)
{
    int centerX = source.cols/2;
    int centerY = source.rows/2;
    // q1,q2,q3,q4 are quadrants for swapping
    // cropping rectangles from the image
    Mat q1(source, Rect(0, 0, centerX, centerY)); // Rect(<x_coord>, <y_coord>, <width>, <hieght>)
    Mat q2(source, Rect(centerX, 0, centerX, centerY));
    Mat q3(source, Rect(0, centerY, centerX, centerY));
    Mat q4(source, Rect(centerX, centerY, centerX, centerY));
    Mat swapMap;
    // swapping q1 with q2 and q3 with q4
    q1.copyTo(swapMap);
    q4.copyTo(q1);
    swapMap.copyTo(q4);

    q2.copyTo(swapMap);
    q3.copyTo(q2);
    swapMap.copyTo(q3);

}
void showDFT(Mat& source)
{
    Mat splitArray[2] = {Mat::zeros(source.size(), CV_32F), Mat::zeros(source.size(), CV_32F)};
    split(source, splitArray); // input: source, output: splitArray
    Mat dftMagnitude;
    magnitude(splitArray[0], splitArray[1], dftMagnitude); // calculating magnitude as sum of squared real and imagenary parts
    // we wont to take log to better visualize DFT, so let\s add 1 to every "pixel"
    dftMagnitude += Scalar::all(1); 
    log(dftMagnitude, dftMagnitude); // input dftMagnitude abd output is also dftMagnitude
    normalize(dftMagnitude, dftMagnitude, 0, 1, NORM_MINMAX); // normalization , so the values from 0 to 1
    recenterDFT(dftMagnitude);
    imshow("DFTMagnitude", dftMagnitude);
    waitKey();
}
void invertDFT(Mat& source, Mat& destination)
{
    Mat inverse;
    dft(source, inverse, DFT_INVERSE | DFT_REAL_OUTPUT | DFT_SCALE);
    destination = inverse;

}
int main(int argc, char** argv)
{
    Mat original = imread("uni.png", IMREAD_GRAYSCALE);// DFT is possible to take only from grayscale image
    imshow("original", original);
    Mat originalFloat;
    // converting 0-255 unsinged int to the 0-1 floating point to take DFT
    original.convertTo(originalFloat,CV_32FC1, 1.0/255.0 );// flag CV_32FC1 is a type, 1.0/255.0 is normalization
    Mat dtfOfOriginal;
    takeDFT(originalFloat, dtfOfOriginal);
    showDFT(dtfOfOriginal);
    Mat invertedDFT;
    invertDFT(dtfOfOriginal, invertedDFT);
    imshow("InvertedDFTY Result", invertedDFT);
    waitKey();
    return 0;
}