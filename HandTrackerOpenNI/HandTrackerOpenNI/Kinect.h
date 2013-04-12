
#pragma once
#include "libraries.h"
//#include <xnlib.h>

class Kinect{
public:
	//Initialize libraries OpenNI and NITE and open device
	STATUS Initialize();
	//print version of OpenNI
	void printVersion();
	//Singleton Instance
	static Kinect& getInstance();
	//show a image give it a Matrix cv::Mat (Image)
	void showImage(cv::Mat &imagen,std::string namewindow);
	//show image give it the name of the file
	void showImage(cv::string namefile);
	//
	void addOne();
	//
	STATUS createStreams();
	//
	void run();
	//destructor
	~Kinect();
	void printPixelFormat(openni::PixelFormat);
private:
	Kinect();
	Kinect(const Kinect&);
	Kinect& operator=(const Kinect&);

	static openni::Device device;
	static bool isOK;
	static int estado;

	openni::VideoStream		niDepthS;
	openni::VideoStream		niColorS;
	openni::VideoFrameRef	niDepthFrameR;
	openni::VideoFrameRef	niColorFrameR;
};