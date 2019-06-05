//basicImage.cpp takes an image using a computers webcam and saves it with a given file name//


#include "opencv2/opencv.hpp"	//Need to have opencv installed//
using namespace cv;


int main(int argc, char** argv)
{

	VideoCapture cap;
	
	if( !cap.open(0) )
	{
		return 1;
	}

	Mat frame;
	cap >> frame;
	imshow( "", frame );	//Displays image that was taken//
	cap.release();	//Turns off webcam//
	
	imwrite( "basicIMG.jpg", frame );  //Warning: writes over anything that is already in that file.//
	while( true )	//Displays image taken until ESC key is hit//
	{
		if( waitKey(10) == 27 )
		{
			break;
		}
	}

	return 0;
}

/*

To Compile:
g++ basicImage.cpp -o img `pkg-config --cflags --libs opencv`

To Run:
./img

*/
