#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>

#include <stdlib.h>
#define p printf
#define s scanf

using namespace cv;
using namespace std;

Mat image;

int main(int argc,char * argv[])
{
int x;
int y;
double area;
int radius;
std::vector<std::vector<cv::Point> > contours;
image=imread(argv[1], 1);
Mat output = Mat::zeros(image.size(),CV_8UC1);
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
findContours(output.clone(), contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
cv::drawContours(output, contours, -1, CV_RGB(255,255,255), -1);
for (int i = 0; i < contours.size(); i++)
{
     area = cv::contourArea(contours[i]);  
    cv::Rect rect = cv::boundingRect(contours[i]); 
     radius = rect.width/2;                     
    if (area >= 30 &&
        std::abs(1 - ((double)rect.width / (double)rect.height)) <= 0.2 &&
        std::abs(1 - (area / (CV_PI * std::pow(radius, 2)))) <= 0.2)   
    {
        cv::circle(image, cv::Point(rect.x + radius, rect.y + radius), radius, CV_RGB(255,0,0), 2);
    }
}
cout<<radius;
namedWindow("Input Image",2);
imshow("Input Image",image);
namedWindow("Output Image",2);
imshow("Output Image",output);
waitKey(0);
return 0;
}



