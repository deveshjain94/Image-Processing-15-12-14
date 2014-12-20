#include <stdio.h>
#include <opencv2/opencv.hpp>
//#include "opencv2/imgproc/imgproc.hpp"
#include <vector>
#include <iostream>
//#include "opencv2/highgui/highgui.hpp"
using namespace cv;
using namespace std;

//places all classes and functions of opencv

// input image
Mat smoothened1;
//Mat smoothened2;
Mat Grayscaled;
Mat edgedetected1;
Mat edgedetected2;
Mat edgedetected3;
Mat edgedetected4;
Mat original;
int t1;
int t2;
int t3;
int t4;
int t5;
int t6;

void rad(int, void*)
 {

  Mat smoothened;
  GaussianBlur(original, smoothened, Size(2*t1+1, 2*t1+1), t5, t6, BORDER_DEFAULT);

  imshow("Smoothened original image", smoothened);
}
void med(int, void*)
{
  Mat smoothened1;
  medianBlur(original, smoothened1, 2*t2+1);

  imshow("Smoothened1 original image", smoothened1);
}

void edge1(int, void*)
{

  Laplacian(Grayscaled, edgedetected1, -1 , 2*t3+1, 2 , 0);
  imshow("edgedetected1 grayscaled image", edgedetected1);
}

void edge2(int, void*) {

  Sobel(Grayscaled, edgedetected2, -1 , 1 , 1, 2*t4+1, 1,0 );
  imshow("edgedetected2 grayscaled image", edgedetected2);
}



int main( int argc, char** argv) {
// defining path for original image


// Applying smoothening functions
  original=imread("images.jpeg");


  namedWindow("Smoothened original image",CV_WINDOW_AUTOSIZE);
  createTrackbar("Gaussian blur, kernel","Smoothened original image", &t1, 10, rad, 0);
  createTrackbar("Gaussian blur, deviation x","Smoothened original image", &t5, 10, rad, 0);
  createTrackbar("Gaussian blur, deviation y","Smoothened original image", &t6, 10, rad, 0);

  namedWindow("Smoothened1 original image",CV_WINDOW_AUTOSIZE);
  createTrackbar("Median blur","Smoothened1 original image", &t2, 10, med, 0);


//converting rgb to grayscale image
  cvtColor(original, Grayscaled, CV_BGR2GRAY, 0);


//applying edge detection functions


  namedWindow("edgedetected1 grayscaled image",CV_WINDOW_AUTOSIZE);
  createTrackbar("Laplacian","edgedetected1 grayscaled image", &t3, 15, edge1 , 0);




  namedWindow("edgedetected2 grayscaled image",CV_WINDOW_AUTOSIZE);
  createTrackbar("sobel", "edgedetected2 grayscaled image", &t4, 15 , edge2 , 0);

  waitKey(0);
  return 0;
}
