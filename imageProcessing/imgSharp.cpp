/*
 *  Created on: 08-Feb-2017
 *      Author: sudeep
 */

#include <opencv2/opencv.hpp>
using namespace cv;
int main( int argc, char** argv )
{
	Mat image;
	image = imread("/home/student/Pictures/scr.png", 0);

//	namedWindow( "Display Image", WINDOW_AUTOSIZE );
//	imshow( "Display Image", image );

	int maxx = image.rows;
	int maxy = image.cols;
	int sum, mean;

	int mask[3][3] = {{-1,-1,-1},{-1,8,-1},{-1,-1,-1}};

	for(int i=1;i<maxx;++i){
		for(int j=1;j<maxy;++j){
			sum = 0;
			//Calculate sum of 3x3 matrix
			sum+= mask[0][0]*image.at<uchar>(i-1,j-1) + mask[0][1]*image.at<uchar>(i-1,j) + mask[0][2]*image.at<uchar>(i-1,j+1);
			sum+= mask[1][0]*image.at<uchar>(i,j-1) + mask[1][1]*image.at<uchar>(i,j) + mask[1][2]*image.at<uchar>(i,j+1);
			sum+= mask[2][0]*image.at<uchar>(i+1,j-1) + mask[2][1]*image.at<uchar>(i+1,j) + mask[2][2]*image.at<uchar>(i+1,j+1);

			//Set the value of central pixel
			image.at<uchar>(i,j) = saturate_cast<uchar>(sum);
		}
	}

	namedWindow( "Display Image", WINDOW_AUTOSIZE );
	imshow( "Display Image", image );

	waitKey(0);

	return 0;
}
