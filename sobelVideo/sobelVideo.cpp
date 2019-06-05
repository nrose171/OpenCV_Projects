#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
//using namespace cv; 


int main( int argc, char ** argv )
{

	cv::namedWindow( "Raw Video", cv::WINDOW_AUTOSIZE );
	cv::namedWindow( "Sobel Video", cv::WINDOW_AUTOSIZE );
	cv::VideoCapture cap;
	cap.open( 0 );

	while( true )
	{
		cv::Mat frame, frame_gray;
		cv::Mat grad;
		cap.read( frame );
	
		  int scale = 1;
		  int delta = 0;
		  int ddepth = CV_16S;

		  int c;

		  if( !frame.data )
		  { return -1; }

		  GaussianBlur( frame, frame, cv::Size(3,3), 0, 0, cv::BORDER_DEFAULT );

		  /// Convert it to gray
		  cvtColor( frame, frame_gray, CV_BGR2GRAY );

		  /// Generate grad_x and grad_y
		  cv::Mat grad_x, grad_y;
		  cv::Mat abs_grad_x, abs_grad_y;

		  /// Gradient X
		  //Scharr( src_gray, grad_x, ddepth, 1, 0, scale, delta, BORDER_DEFAULT );
		  Sobel( frame_gray, grad_x, ddepth, 1, 0, 3, scale, delta, cv::BORDER_DEFAULT );
		  convertScaleAbs( grad_x, abs_grad_x );

		  /// Gradient Y
		  //Scharr( src_gray, grad_y, ddepth, 0, 1, scale, delta, BORDER_DEFAULT );
		  Sobel( frame_gray, grad_y, ddepth, 0, 1, 3, scale, delta, cv::BORDER_DEFAULT );
		  cv::convertScaleAbs( grad_y, abs_grad_y );

		  /// Total Gradient (approximate)
		  addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad );

		if( frame.empty() )
		{
			break;
		}
		
		imshow( "Raw Video", frame );
		cv::imshow( "Sobel Video", grad );
		if( cv::waitKey(33) == 27 )
		{
			break;
		}
	}
	cap.release();

return 0;
}
