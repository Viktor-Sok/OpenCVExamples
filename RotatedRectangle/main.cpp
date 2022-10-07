#include "opencv2/opencv.hpp"
using namespace cv;
int main(int argc, char** argv)
{
    uint16_t width = 200, height = 200; // width and height of our image
    Size size(width,height);
    Mat im(size, CV_8UC3, Scalar(0)); // image with 3 channels
    RotatedRect rRect(Point2f(100,100), Size2f(100,50), 30); // objects created as an argument to a function, 30 is inclanation
    Point2f vertices[4]; // array of objects of the class Point2f, vertices of rectangle
    rRect.points(vertices); // coordinates of vertices of the rotated rectangle
    for (int i=0; i<4; ++i)
    //Drawing rotated rectangle through Point2f objects
    {   
        line(im, vertices[i], vertices[(i+1)%4], cv::Scalar(0,255,0), 2 ); // (i+1)%4 is used to draw the last edge correctly (green color)
    } 
    Rect brect = rRect.boundingRect(); // bounding rectangle of inclined rectangle
    // drawing bounding rectangle on the image
    rectangle(im, brect, Scalar(255,0,0), 2); // blue color, thikness 2
    imshow("Rectangles", im);
    waitKey();
    return 0;
}