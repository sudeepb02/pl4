/*
 * imgRotate.cpp
 *
 *  Created on: 08-Feb-2017
 *      Author: student
 */

#include<iostream>
#include<math.h>
#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
	Mat image;
	image = imread("/home/student/Pictures/scr.png", 1);

	int maxx = image.rows;
	int maxy = image.cols;

	int theta = 90;
	int sint = 1;
	int cost = 0;

	//Clone the original image to store rotated image
	Mat newImage = image.clone();

	//Rotate the image;
	for(int i=1;i<maxx;++i){
		for(int j=1;j<maxy;++j){
			int nx = i*cost - j*sint;
			int ny = i*sint + j*cost;
			newImage.at<uchar>(nx,ny) = image.at<uchar>(i,j);
		}
	}

	namedWindow("dimg", WINDOW_AUTOSIZE );
	imshow( "dimg", newImage );
	waitKey(0);

	return 0;
}


