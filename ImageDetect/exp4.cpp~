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
Mat output = Mat::zeros(image.size(),CV_8UC1);
for(y=0;y<image.rows;y++)
{
for(x=0;x<image.cols;x++)
{
if(((int)image.at<Vec3b>(y,x)[0]>0)&&((int)image.at<Vec3b>(y,x)[0]<20)&&((int)image.at<Vec3b>(y,x)[1]>0)&&((int)image.at<Vec3b>(y,x)[1]<20)&&((int)image.at<Vec3b>(y,x)[2]>0)&&((int)image.at<Vec3b>(y,x)[2]<20))
{
output.at<uchar>(y,x)=255;
cout << x << " " << y << "\n";
}
}
}
namedWindow("Output Image",1);
imshow("Output image",output);
imwrite("../Morpho/bin.jpg",output);
waitKey(0);
return 0;
}




