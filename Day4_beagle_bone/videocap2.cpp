//OpenCV Libraries
#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv/cv.h>
#include <time.h>
#include <fstream>
#include <unistd.h>
#include <signal.h>
#include <cstdlib>
#include <math.h>
//#include "gnuplot_i.hpp"
using namespace std;
using namespace cv;

VideoCapture capture(0);
ofstream image_file("radtime.csv");

void signalhandler(int signum)
{
cout<<"Done Recording"<<endl;
image_file.close();
exit(0);
}

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
    Mat img = *((Mat*)userdata); // 1st cast , then deref

    if  ( event == EVENT_LBUTTONDOWN )
    {
        Vec3b pixel = img.at<Vec3b>(y,x); // y,x here !
        cout << "Left button clicked - position (" << x << ", " << y << ")" << endl;
        cout << "color (" << int(pixel[0])  << ", " << int(pixel[1])   << ", " << int(pixel[2])  << ")" << endl;
    }
}

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
int redmax=255;
int redmin=80;
int greenmax=255;
int greenmin=90;
int bluemax=255;
int bluemin=90;
Scalar m;
float pi=3.14;
Mat image; //Input image matrix

//VideoCapture capture(0); //Capture using any camera connected to your system
capture.set(CV_CAP_PROP_FRAME_WIDTH,320);
capture.set(CV_CAP_PROP_FRAME_HEIGHT,240);

capture>>image;
imwrite("cap.jpg",image);
//capture.release();//Extract a frame and store in the 'image' matrix
//Define Frame Height and Width
int framewidth=image.cols;
int frameheight=image.rows;
signal(SIGINT,signalhandler);

Mat hsv1;
//Define VideoiWriter object for storing the video
VideoWriter video("capture.avi",CV_FOURCC('M','J','P','G'),fps,cvSize(framewidth,frameheight));
float t0=clock(); //measuring time T-Zero
//Mat roiMat;
//Loop for Processing
Mat3b roiMat = image(Rect(110,105,105,105));
m =  mean(roiMat);
cout<<m[0]<<" "<<endl; //blue mean
cout<<m[1]<<" "<<endl; //green
cout<<m[2]<<" "<<endl<<"\n";
bluemin=m[0];
greenmin=m[1];
redmin=m[2];
while(1)
{
//VideoCapture capture(0); //Capture using any camera connected to your system
	 //Create image frames from capture
         //capture.set(CV_CAP_PROP_FRAME_WIDTH,320);
         //capture.set(CV_CAP_PROP_FRAME_HEIGHT,240);
	capture>>image;
 //red
        //capture>>image;
	Mat output = Mat::zeros(image.size(),CV_8UC1);	//Output Matrix of the same size as input image
	std::vector<std::vector<cv::Point> > contours;	//Defining Contour variable as a vector

//Mat element1=getStructuringElement( MORPH_RECT,Size(3,3),Point (1,1)); //defining structuring element for direction
//erode (image,image, element1);


Mat hsvout;

GaussianBlur(image, image, Size(11,11),0,0,BORDER_DEFAULT);
//cvtColor(hsvout, hsv1, CV_BGR2HSV);
//fastNlMeansDenoisingColored(image, image, 10,10, 7, 7);
//Thresholding the RGB image and converting into binary image
	for(y=105;y<image.rows-25;y++)
	{
		for(x=115;x<image.cols-115;x++)
		{
			if(((int)image.at<Vec3b>(y,x)[0]>bluemin)&&((int)image.at<Vec3b>(y,x)[0]<bluemax)&&((int)image.at<Vec3b>(y,x)[1]>greenmin)&&((int)image.at<Vec3b>(y,x)[1]<greenmax)&&((int)image.at<Vec3b>(y,x) [2]>redmin)&&((int)image.at<Vec3b>(y,x)[2]<redmax))
			{
				output.at<uchar>(y,x)=0;
			}
			else
			{
			output.at<uchar>(y,x)=255;
			}
		}
	}
//bitwise_not ( output, output );

//Dilation
//Mat element=getStructuringElement( MORPH_RECT,Size(7,7),Point (3,3)); //defining structuring element for direction
//dilate (output, output, element);

//Contour Detection
//findContours(output.clone(), contours, RETR_EXTERNAL, CHAIN_APPROX_NONE); //find contours
/*for (int i = 0; i < contours.size(); i++)
    {
        // Calculate contour area
        double area = cv::contourArea(contours[i]);

        // Remove small objects by drawing the contour with black color
        if ( area<=400 && area >= 1000)
            cv::drawContours(output, contours, i, CV_RGB(0, 0, 0), -1);
    }*/
//cv::drawContours(output, contours, -1, Scalar(255,255,255), -1); //detecting contours
findContours(output.clone(), contours, RETR_EXTERNAL, CHAIN_APPROX_NONE); //find contours
//cv::drawContours(output, contours, -1, Scalar(255,255,255), -1); //detecting contours
	for (int i = 0; i < contours.size(); i++)
	{
	//cout<<area<<"\n";
    area = cv::contourArea(contours[i]);    //area of contours
    cv::Rect rect = cv::boundingRect(contours[i]);  //creating bounding box for contour
   // radius = rect.width/2;                     //radius of circle
     //selecting contours based on area and height-width ratio of bounding box
    	if (area>=400 && area<=1200 && std::abs(1 - ((double)rect.width /(double)rect.height)) <= 0.15)
    	{
    	cout<<area<<"\n";
        radius=sqrt(area/pi);
      //impose circle of the found radius over the contour
        cv::circle(image, cv::Point(rect.x + radius, rect.y + radius), radius, Scalar(0,0,255), 2);
    	}
	}

//namedWindow("Input",2);
//imshow("Input",image); //BGR image

//namedWindow("output",2);
//imshow("output",output);  //Show image frames on created window
//setMouseCallback("Input", CallBackFunc, &image);
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

//sleep(1);
key = waitKey(100); //Capture Keyboard stroke
	if (char(key) == 27)
	{
		break; //If you hit ESC key loop will break.
	} 
//capture.release();

}
return 0;
}
