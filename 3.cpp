#include <stdio.h>
#include <stdlib.h>

Mat I; //input array
Mat O; //grayscaled array
Mat T;  //Thresholded array

#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"


using namespace std;
using namespace cv;

RNG rng(12345);
int main( int argc, char** argv ){

I = imread("images.jpeg");
int width=I.rows;
int height=I.cols;
int i;
vector<vector<Point> > contours; //defining contours
vector<Vec4i> hierarchy; 

int alphaslider;


Vec3b intensity = I.at<Vec3b>(69,67);
cout<<intensity << endl;  //gives intensity at (69,67)

cvtColor(I, O, CV_BGR2GRAY,0);  //conversion

namedWindow("grayscale image", 2 ); 

imshow("grayscale image", O);

adaptiveThreshold(O, T, 90, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 41, 5);  //adaptive threshold
int slider1=255

createTrackbar("thresholding", "thresholded image", &slider1, thresh  );

thresh(slider1, 0);
namedWindow("thresholded image",2 );

  imshow("thresholded image", T);


findContours(T, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_NONE, Point(0,0) );  //contour formation

Mat drawing = Mat::zeros( T.size(), CV_8UC3 );  //defining an array drawing
for( int i = 0; i< contours.size(); i++ ) {
	Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
	drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, Point() );
}

}
namedWindow("contour",2 );  // contour formation

waitKey(0);


