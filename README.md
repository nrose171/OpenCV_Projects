# OpenCV_Projects
This is a compilation of all my basic projects using OpenCV.

# Required Components
Need to have openCV installed and g++ version 5.4 or greater.

# To Compile
All files will use this format if you have OpenCV installed correctly:
<br />g++ <filename> -o \<executable filename\> \`pkg-config --cflags --libs\`
<br />//Replace <executable filename> with whatever you want to name your executable//
<br />EX) g++ basicImage.cpp -o img \`pkg-config --cflags --libs\`

# To Run
./\<executable filename\>
<br />EX) ./img

# Program List
**basicImage** - basicImage.cpp takes an image using a computers webcam and saves it with a given file name.
<br />**basicVideo** - The basicVideo.cpp file is used to capture a continuous stream of frames from a user's webcam and plays it back for them.
<br />**smoothVideo** - smoothVideo.cpp file captures a stream of frames from the user's webcam and smooths them out. Plays back the raw video stream and the stream that is slightly smoothed out.
<br />**sobelImage** - Uses the sobel method to take derivatives in the x and y directions of the image to get the edges. Then saves the image as a gray-scale image.
<br />**sobelVideo** - sobelVideo.cpp file captures a stream of frames from a user's webcam and converts them to sobel images. Plays back the raw video capture and the sobel conversion video.

#
Thank you,
#
Nathaniel Rose
