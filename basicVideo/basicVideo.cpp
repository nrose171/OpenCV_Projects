
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/opencv.hpp"
#include <iostream>
#include <string>

int main( int argc, char ** argv )
{
	cv::namedWindow( "Example3", cv::WINDOW_AUTOSIZE );
	cv::VideoCapture cap;
	cap.open( 0 );

	while( true )
	{
		cv::Mat frame;
		cap.read( frame );
		if( frame.empty() )
		{
			break;
		}
		
		cv::imshow( "Example3", frame );
		if( cv::waitKey(33) == 27 )
		{
			break;
		}
	}
	cap.release();

	return 0;
}
