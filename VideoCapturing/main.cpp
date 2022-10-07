#include "opencv2/opencv.hpp"
using namespace cv;
int const fps = 20; // 20 frames per second, i.e. 50ms 
/*---------------------------
/   It's possible to capture no only
/   video fro a camera (e.g. a WebCam), but also
/   read video from a video file or an image sequence,  which is good for testing CV algorytms
---------------------------*/
int main(int argc, char** argv)
{
    Mat frame; // cuurent video frame will be stored procceced here then it'll move on to the next frame
    VideoCapture vid(1); // CAP_ANY flag means it'll autochoose a video reader (number specyfies USB port which the camera connected to)
    if (!vid.isOpened()) 
    {
        return -1; // or throw the exception
    }
    while(vid.read(frame)) // loop is running while it's possible to capture current video frame into frame variable
    {
        // vid >> frame; another way to push current video frame into frame variable using bitwise shift operator
        if (frame.empty())
        {
            break;
        }
        imshow("Webcam", frame);
        
        if(waitKey(1000/fps) >= 0) 
        {
            // to quit video stream
            break;
        }
        waitKey(1000/fps); // waitKey() will wait at least forn 1000/fps ms, but it might be longer (during this time we can do image processing)
        
    }
    return 1;
}