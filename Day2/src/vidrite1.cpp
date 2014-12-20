#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main() {
    CvCapture* capture = cvCaptureFromCAM( CV_CAP_DSHOW );
    CvSize size = cvSize(640,480);
    int codec = CV_FOURCC('M', 'J', 'P', 'G');
    CvVideoWriter* writer = cvCreateVideoWriter("video.avi",codec,15,size);

    int a = 100;
    while ( a > 0 ) {
        IplImage* frame = cvQueryFrame( capture );
        cvWriteToAVI(writer,frame);
        a--;
    }

    cvReleaseVideoWriter(&writer);
    cvReleaseCapture( &capture );
    return 0;
}
