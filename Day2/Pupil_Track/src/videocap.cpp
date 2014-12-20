#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp> //OpenCV libraries
#include <opencv/cv.h>
#include <time.h>


using namespace std;
using namespace cv;

char key;
int main()
{
int x;
int y;
double area; //area of contour
int redmax=80; //thresholds for each channel 
int redmin=35;
int greenmax=80;
int greenmin=35;
int bluemax=90;
int bluemin=50;
int isColor = 1;
int fps     = 25;  // or 30
int frameW  = 320; // 744 for firewire cameras
int frameH  = 240;
CvSize size;

size.width = frameW;
size.height = frameH;
VideoWriter video("Video.avi",-1,fps,size);

namedWindow("Camera_Output", 1); //Create window
VideoCapture capture(1); //Capture using any camera connected to your system
float t0=clock(); //measuring time
float t1=0;
Mat image; //input image matrix
float radius=0;
while(1)
{ //Create infinte loop for live streaming
	capture>>image; //Create image frames from capture
	Mat output = Mat::zeros(image.size(),CV_8UC1);
	std::vector<std::vector<cv::Point> > contours;
	//Thresholding the RGB image and converting into binary image

	for(y=0;y<image.rows;y++)
	{
		for(x=0;x<image.cols;x++)
		{
			if(((int)image.at<Vec3b>(y,x)[0]>0)&&((int)image.at<Vec3b>(y,x)[0]<20)&&((int)image.at<Vec3b>(y,x)[1]>0)&&((int)image.at<Vec3b>(y,x)[1]<20)&&((int)image.at<Vec3b>(y,x)[2]>0)&&((int)image.at<Vec3b>(y,x)[2]<20))
			{
				output.at<uchar>(y,x)=255;
			}
		}
	}

//Dilation
Mat element=getStructuringElement( MORPH_RECT,Size(9,9),Point (5,5)); //defining structuring element for direction
dilate (output, output, element); 

//Contour Detection
findContours(output.clone(), contours, RETR_EXTERNAL, CHAIN_APPROX_NONE); //find contours
cv::drawContours(output, contours, -1, Scalar(255,255,255), -1); //detecting contours
	for (int i = 0; i < contours.size(); i++)
	{
    area = cv::contourArea(contours[i]);    //area of contours
    cv::Rect rect = cv::boundingRect(contours[i]);  //creating bounding box for contour
    radius = rect.width/2;                     //radius of circle
    	if (area >= 400 && std::abs(1 - ((double)rect.width / (double)rect.height)) <= 0.15)
        //std::abs(1 - (area / (CV_PI * std::pow(radius, 2)))) <= 0.2)   
    	{ //selecting contours based on area and height-width ratio of bounding box
        cv::circle(image, cv::Point(rect.x + radius, rect.y + radius), radius, Scalar(0,0,255), 2); //impose circle of the found radius over the contour
    	}
	}
namedWindow("Input",2); 
imshow("Input",image); //BGR image
namedWindow("output",2);
imshow("output",output);  //Show image frames on created window
t1=clock()-t0; //measuring time
cout<<t1/100000;
cout<<"\n";
video.write(output);
key = waitKey(10); //Capture Keyboard stroke
	if (char(key) == 27)
	{
		break; //If you hit ESC key loop will break.
	}
}

return 0;
} 
