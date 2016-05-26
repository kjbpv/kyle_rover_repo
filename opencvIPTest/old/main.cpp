#include<opencv2/opencv.hpp>
#include<stdio.h>
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	cout << "Hello World" << endl;
	VideoCapture myCapture;
	myCapture.open("http://169.254.185.12/mjpg/video.mjpg");

	if(!myCapture.isOpened())
	{
		cout << "cannot open video cam" << endl;
		return -1;
	}

	Mat frame;
	
	double dWidth = myCapture.get(CV_CAP_PROP_FRAME_WIDTH);
	double dHeight = myCapture.get(CV_CAP_PROP_FRAME_HEIGHT);

	cout << "Frame Size: " << dWidth << " x " << dHeight << endl;

	namedWindow("MyVideo", CV_WINDOW_AUTOSIZE);

	while(1)
	{
		myCapture.read(frame);
		imshow("MyVideo",frame);
		waitKey(30);
	}
	
	myCapture.release();

	return 0;

}
