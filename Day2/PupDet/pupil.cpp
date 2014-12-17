#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>

#define p printf
#define s scanf

using namespace cv;
using namespace std;

Mat image;
int main(int argc,char * argv[])
{
    int x;
    int y;
    image=imread(argv[1], 1);

    cv::Mat output = Mat::zeros(image.size(),CV_8UC1);
    cv::Mat gray = Mat::zeros(image.size(),CV_8UC1);

cv::cvtColor(~image, gray, COLOR_BGR2GRAY);
cv::threshold(gray, gray, 220, 255, cv::THRESH_BINARY);
std::vector<std::vector<cv::Point> > contours;
findContours(gray.clone(), contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);

// Fill holes in each contour
cv::drawContours(gray, contours, -1, Scalar(255,255,255), -1);


for (int i = 0; i < contours.size(); i++)
{
    double area = cv::contourArea(contours[i]);    // Blob area
    cv::Rect rect = cv::boundingRect(contours[i]); // Bounding box
    int radius = rect.width/2;                     // Approximate radius

    // Look for round shaped blob
    if (area >= 30 &&
        std::abs(1 - ((double)rect.width / (double)rect.height)) <= 0.2 &&
        std::abs(1 - (area / (CV_PI * std::pow(radius, 2)))) <= 0.2)   
    {
        cv::circle(image, cv::Point(rect.x + radius, rect.y + radius), radius, Scalar(255,0,0), 2);
    }
}




imshow("Output image",image);
waitKey(0);
return 0;
}
