#include <opencv2/highgui/highgui.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>
#include <stdio.h>
#define p printf
#define s scanf

int main()
{

CvCapture* cap=cvCreateCameraCapture(0);
IplImage* frame;
cvNamedWindow("LiveFeed",CV_WINDOW_AUTOSIZE);

while(1)
{
frame=cvQueryFrame(cap);

if(!frame)
	p("\nNo");

cvShowImage("LiveFeed",frame);
char c=cvWaitKey(33);

if(c==27)
	break;
}

}

