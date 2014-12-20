#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv/cv.h>
// Include standard OpenCV headers

 
using namespace std;
 
// All the new API is put into "cv" namespace
using namespace cv;
 
int main (int argc, char *argv[])
{
// Create a matrix to keep the retrieved frame
    Mat frame;
    // Open the default camera
    VideoCapture capture(0);
 	capture>>frame;
    // Check if the camera was opened
    if(!capture.isOpened())
    {
        cerr << "Could not create capture";
        return -1;
    }
	 double width = frame.rows;
 	double height = frame.cols;
    // Get the properties from the camera
     
    cout << "Camera properties\n";
    cout << "width = " << width << endl <<"height = "<< height << endl;
 
    
 
    // Create a window to show the image
    namedWindow ("Capture", 2);
 
    // Create the video writer
    VideoWriter video("capture.avi",-1, 30, cvSize((int)width,(int)height) );
 	
    // Check if the video was opened
    if(!video.isOpened())
    {
        cerr << "Could not create video.";
        return -1;
    }
 
    cout << "Press Esc to stop recording." << endl;
 
    // Get the next frame until the user presses the escape key
    while(true)
    {
        // Get frame from capture
        capture >> frame;
 
        // Check if the frame was retrieved
        if(!frame.data)
        {
            cerr << "Could not retrieve frame.";
            return -1;
        }
 
        // Save frame to video
        video << frame;
 
        // Show image
        imshow("Capture", frame);
 
        // Exit with escape key
        if(waitKey(1) == 27)
            break;
    }
 
    // Exit
    return 0;
}
