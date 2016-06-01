#include<opencv2/opencv.hpp>
#include<stdio.h>
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	cout << "Hello World" << endl;
	VideoCapture myCapture1;
	VideoCapture myCapture2;
    myCapture1.open("http://192.168.10.91/mjpg/video.mjpg");
    myCapture2.open("http://192.168.10.92/mjpg/video.mjpg");

	if(!myCapture1.isOpened())
	{
		cout << "cannot open video cam 1" << endl;
		return -1;
	}

	if(!myCapture2.isOpened())
	{
		cout << "cannot open video cam 2" << endl;
		return -1;
	}

    Mat frame1,frame2;	
    namedWindow("camera1", CV_WINDOW_AUTOSIZE);
    namedWindow("camera2", CV_WINDOW_AUTOSIZE);
    moveWindow("camera1",0,0);
    moveWindow("camera2",701,0);

    int xCenter = 360;
    int yCenter = 318;
    int xLength = 30;
    int yLength = 20;
    int xWidth = 60;
    int yWidth = 40;
    
	while(1)
	{
		myCapture1.read(frame1);
		myCapture2.read(frame2);

        // line(Mat& img, Point pt1, Point pt2, const Scalar& color, int thickness=1, int lineType=8, int shift=0)
        // rectangle(Mat& img, Point pt1, Point pt2, const Scalar& color, int thickness=1, int lineType=8, int shift=0)
        line(frame2,Point(xCenter + xWidth/2,yCenter),Point(xCenter + xWidth/2 + xLength,yCenter),Scalar(0,255,0),1,8,0);
        line(frame2,Point(xCenter - xWidth/2,yCenter),Point(xCenter - xWidth/2 - xLength,yCenter),Scalar(0,255,0),1,8,0);
        line(frame2,Point(xCenter,yCenter + yWidth/2),Point(xCenter,yCenter + yWidth/2 + yLength),Scalar(0,255,0),1,8,0);
        line(frame2,Point(xCenter,yCenter - yWidth/2),Point(xCenter,yCenter - yWidth/2 - yLength),Scalar(0,255,0),1,8,0);

		imshow("camera1",frame1);
		imshow("camera2",frame2);
		waitKey(60);
	}
	
	myCapture1.release();
	myCapture2.release();

	return 0;

}
