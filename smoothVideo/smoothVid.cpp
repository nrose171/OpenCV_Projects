#include "opencv2/opencv.hpp"
#include <iostream>
#include <string>

int main( int argc, char ** argv )
{
	cv::namedWindow( "raw image", cv::WINDOW_AUTOSIZE );
	cv::namedWindow( "smooth image", cv::WINDOW_AUTOSIZE );
	cv::VideoCapture cap;
	cap.open( 0 );

	while( true )
	{
		cv::Mat normal;
		cap.read( normal );
		if( normal.empty() )
		{
			break;
		}
	
		cv::Mat smooth;
		cap.read( smooth );
		
		cv::imshow( "raw image", normal );
		cv::GaussianBlur( normal, smooth, cv::Size(5,5), 3, 3 );
		cv::GaussianBlur( smooth, smooth, cv::Size(5,5), 3, 3 );
		cv::imshow( "smooth image", smooth );
		if( cv::waitKey(33) == 27 )
		{
			break;
		}
	}
	cap.release();

	return 0;
}
