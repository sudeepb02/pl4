#include<iostream>
#include <opencv2/opencv.hpp>
using namespace cv;

void rotateImage(Mat img)
{
	Mat rimg = Mat::zeros(img.size(),img.type());
	int theta = 180;
	//Initialize origin and x' and y'
	int x0 , y0, nx, ny;
	theta=(3.14/180)*theta;
	y0 = img.rows/2;
	x0 = img.cols/2;
	int cost = -1;
	int sint = 0;

	for(int y=0;y<img.rows;y++){
		for(int x=0;x<img.cols;x++){
			Vec3b color = img.at<Vec3b>(Point(x,y));

			nx=cost*(x-x0) - sint*(y-y0) + x0;
			ny=sint*(x-x0) + cost*(y-y0) + y0;

			if(nx<img.cols && ny<img.rows && ny>0 && nx>0)
				rimg.at<Vec3b>(Point(nx,ny)) = color;
		}
	}
	namedWindow("Rotate", CV_WINDOW_AUTOSIZE);
	imshow("Rotate",rimg);
	waitKey(0);
}

int main()
{
	Mat image;
	image = imread("/home/student/Pictures/scr.png", 1);

	rotateImage(image);

	return 0;
}
