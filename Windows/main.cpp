#include "opencv2/opencv.hpp"
using namespace cv;
int main(int argc, char** argv)
{
    Mat file1 = imread("Uni.png", IMREAD_COLOR);
    Mat file2 = imread("Uni.png", IMREAD_GRAYSCALE);
    namedWindow("Color", WINDOW_FREERATIO); // Color is a window handler (like ID)
    namedWindow("Fixed",WINDOW_AUTOSIZE);
    imshow("Color", file1);
    imshow("Fixed", file2);
    resizeWindow("Color",file1.cols/2, file1.rows/2 );
    resizeWindow("Fixed",file1.cols/2, file1.rows/2 );
    moveWindow("Color",10, 10); // positioning windows on the screen (upper left corner is the origin of coordinate system in px)
    moveWindow("Fixed",10 + file1.cols/2+5, 10);



    waitKey(); //hold program from finishing
    return 0;
}