/*
 *  Created on: 08-Feb-2017
 *      Author: sudeep 
 */

#include <opencv2/opencv.hpp>
using namespace cv;
int main( int argc, char** argv )
{
	Mat image;
	image = imread("/home/student/Pictures/scr.png", 0 );

//	namedWindow( "Display Image", WINDOW_AUTOSIZE );
//	imshow( "Display Image", image );

	int maxx = image.rows;
	int maxy = image.cols;
	int sum, mean;

	for(int i=1;i<maxx;++i){
		for(int j=1;j<maxy;++j){
			sum = 0;
			//Calculate sum of 3x3 matrix
			sum+= image.at<uchar>(i-1,j-1) + image.at<uchar>(i-1,j) + image.at<uchar>(i-1,j+1);
			sum+= image.at<uchar>(i,j-1) + image.at<uchar>(i,j) + image.at<uchar>(i,j+1);
			sum+= image.at<uchar>(i+1,j-1) + image.at<uchar>(i+1,j) + image.at<uchar>(i+1,j+1);

			//Calculate average
			mean = sum/9;

			//Set the value of central pixel
			image.at<uchar>(i,j) = mean;
		}
	}

	namedWindow( "Display Image", WINDOW_AUTOSIZE );
	imshow( "Display Image", image );

	waitKey(0);

	return 0;
}
