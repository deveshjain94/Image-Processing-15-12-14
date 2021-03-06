//OpenCV Libraries
#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp> 
#include <opencv/cv.h>
#include <time.h>
#include <fstream>
#include "gnuplot_i.hpp"
using namespace std;
using namespace cv;

int main()
{
//Gnuplot g1("lines");
std::vector<double> xVec, yVec;
char key;
int x,y;
double area; //area of contour
int isColor = 1;
int fps = 15;		//FPS of recorded video
float t1=0;		  //Time Variable
float radius=0; //Radius for the overlay circle

//thresholds for each channel 
int redmax=70; 
int redmin=35;
int greenmax=70;
int greenmin=35;
int bluemax=115;
int bluemin=50;

Mat image; //Input image matrix
 
VideoCapture capture(1);    //Capture using any camera connected to your system
capture>>image;							//Extract a frame and store in the 'image' matrix
//Define Frame Height and Width
int framewidth=image.cols;	
int frameheight=image.rows;

//Define VideoWriter object for storing the video
VideoWriter video("capture.avi",CV_FOURCC('D','I','V','3'),fps,cvSize(framewidth,frameheight));
ofstream image_file("radtime.csv"); //initializing csv file for plotting data
float t0=clock(); //measuring time T-Zero

//Loop for Processing
while(1)
{ 
	capture>>image; //Create image frames from capture
	Mat output = Mat::zeros(image.size(),CV_8UC1);	//Output Matrix of the same size as input image
	std::vector<std::vector<cv::Point> > contours;	//Defining Contour variable as a vector
	
//Thresholding the RGB image and converting into binary image
	for(y=0;y<image.rows;y++)
	{
		for(x=0;x<image.cols;x++)
		{
			if(((int)image.at<Vec3b>(y,x)[0]>bluemin)&&((int)image.at<Vec3b>(y,x)[0]<bluemax)&&((int)image.at<Vec3b>(y,x)[1]>greenmin)&&		  
		  ((int)image.at<Vec3b>(y,x)[1]<greenmax)&&((int)image.at<Vec3b>(y,x)[2]>redmin)&&((int)image.at<Vec3b>(y,x)[2]<redmax))
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

     //selecting contours based on area and height-width ratio of bounding box
    	if (area >= 400 && std::abs(1 - ((double)rect.width / (double)rect.height)) <= 0.15) 
    	{ 
      //impose circle of the found radius over the contour
        cv::circle(image, cv::Point(rect.x + radius, rect.y + radius), radius, Scalar(0,0,255), 2); 
    	}
	}

namedWindow("Input",2); 
imshow("Input",image); //BGR image

namedWindow("output",2);
imshow("output",output);  //Show image frames on created window

t1=clock()-t0; //measuring time
t1=t1/1000;
image_file<<(float)t1<<"\t"<<radius<<"\n"; //insert the time and radius of pupil in the csv file
//xVec.push_back((float)t1);
//yVec.push_back((radius));
//g = Gnuplot::
/*g1.reset_plot();
g1.set_grid();
g1.set_style("points").plot_xy(x,y,"user-defined points 2d");*/

video<<image; // Save frame in video


key = waitKey(20); //Capture Keyboard stroke
	if (char(key) == 27)
	{
		break; //If you hit ESC key loop will break.
	}
}
image_file.close(); //close csv file
return 0;
} 
