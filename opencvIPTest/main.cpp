#include<opencv2/opencv.hpp>
#include<stdio.h>
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	cout << "Hello World" << endl;
	VideoCapture myCapture;
	//myCapture.open("http://169.254.185.12/mjpg/video.mjpg");
    //myCapture.open("http://169.254.179.199/mjpeg/video.mjpg");
    myCapture.open("http://192.168.10.91/mjpg/video.mjpg");
    //myCapture.open("http://192.168.10.91/view/view.shtml?id=36&imagepath=%2Fmjpg%2Fvideo.mjpg&size=1");
    //myCapture.open("http://192.168.10.91/view/view.shtml/video.mjpg");


	if(!myCapture.isOpened())
	{
		cout << "cannot open video cam" << endl;
		return -1;
	}

	double dWidth = myCapture.get(CV_CAP_PROP_FRAME_WIDTH);
	double dHeight = myCapture.get(CV_CAP_PROP_FRAME_HEIGHT);

	cout << "Frame Size: " << dWidth << " x " << dHeight << endl;

    // create map

 // Create map

    int centerX = 383;
    int centerY = 297;
    
    Point center(centerX,centerY);
    
    int diameter = dHeight;
    if (diameter > dWidth)
    {
        diameter = dWidth;
    }
    int dstWidth = 2.2 * diameter * 3.14159 / 2.0;
    int dstHeight = diameter / 2.0;
    
    Mat dst(dstHeight,dstWidth,CV_8UC3,Scalar(0,0,255));
    Mat mapX(dst.rows,dst.cols,CV_32F,Scalar(0,0,0));
    Mat mapY(dst.rows,dst.cols,CV_32F,Scalar(0,0,0));
    
    float xCoord,yCoord;
    int dX,dY;
    float angle,radius;
    
    for (int i = 0; i < dst.cols; i++)
    {
        for (int j = 0; j < dst.rows; j++)
        {
            dX = i;
            dY = j;
            angle = 2.0 * 3.14159 * (1.0 * i) / (1.0 * dst.cols);
            radius = dY;
            
            xCoord = radius * cos(angle);
            yCoord = radius * sin(angle);
            mapX.at<float>(j,i) = center.x + xCoord;
            mapY.at<float>(j,i) = center.y + yCoord;
            //            cout << "X: " << dX << " Y: " << dY << " angle: " << angle << " radius: "<< radius << " xCoord: " << xCoord << " yCoord: " << yCoord << endl;
        }
    }
    
    // remap(radial_image, dst, mapX, mapY, 1);


    Mat frame;	
    //namedWindow("raw", CV_WINDOW_AUTOSIZE);
    namedWindow("unwrapped", CV_WINDOW_AUTOSIZE);
    
	while(1)
	{
		myCapture.read(frame);
        remap(frame, dst, mapX, mapY, 1);
		//imshow("raw",frame);
		imshow("unwrapped",dst);
		waitKey(60);
	}
	
	myCapture.release();

	return 0;

}
