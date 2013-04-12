#include "Kinect.h"

void printVersionOpenNI(openni::Device &dev);

using namespace std;

typedef uint16_t DepthPixel;

//typedef struct
//	{
//		char r;
//		char g;
//		char b;
//	} RGBPixel;

int main(int argc, char *argv[]){
	if(Kinect::getInstance().Initialize()==STATUS::STATUS_OK){
		Kinect::getInstance().printVersion();
		Kinect::getInstance().run();
	};
	

	/*
	device.setImageRegistrationMode(openni::ImageRegistrationMode::IMAGE_REGISTRATION_DEPTH_TO_COLOR);
	
	printVersionOpenNI(device);

	cv::Mat imagen=cv::imread("woman.jpg");
	cv::namedWindow("Woman");
	cv::imshow("Woman",imagen);

	openni::VideoStream niDepth;
	openni::VideoStream niColor;
	openni::VideoFrameRef niDepthFrame;
	openni::VideoFrameRef niColorFrame;

		
		nite::HandTracker handTracker;
		nite::HandTrackerFrameRef handTrackerVideoRef;
		nite::Point3f position;
		openni::VideoStream* streams[] = {	&niDepth, &niColor};
		int key=-1;
		while((key=(cv::waitKey(5)&0x000000FF))!='q'){
		//Acquire images and camera parameters from shared memory
		openni::VideoFrameRef depthFrame,colorFrame;

		niDepth.readFrame(&depthFrame);
		niColor.readFrame(&colorFrame);
		//colorFrame.
		if(depthFrame.isValid() && colorFrame.isValid()){
			
		//handTracker.create(&device);
		//handTracker.readFrame(&handTrackerVideoRef);
		//nite::HandId *handId=(nite::HandId*)handTrackerVideoRef.getHands()[0].getId();

		//handTracker.startHandTracking(position,handId);
			RGBPixel* colorP = (RGBPixel*)colorFrame.getData();
			RGBPixel* depthP = (RGBPixel*)depthFrame.getData();

			cv::Mat depth(480,640,CV_16UC1,depthP,2*640);
			cv::Mat depthNorm;
			cv::normalize(depth,depthNorm,0,255,CV_MINMAX,CV_8UC1);
			cv::imshow("Depth",depthNorm);

			cv::Mat bgrMat,rgbMat(480,640,CV_8UC3,colorP,3*640);
			cv::cvtColor(rgbMat,bgrMat, CV_RGB2BGR);
			cv::imshow("FORTH 3D HandTracker",bgrMat);
		}
	}
	*/
	//handTracker.create(

	LOG("Hello World I am to the end of the main");
	system("pause");
	return 0;
}

void printVersionOpenNI(openni::Device &device){
	openni::DeviceInfo deviceInfo;
	deviceInfo = device.getDeviceInfo();

	LOG(deviceInfo.getName());
	LOG(deviceInfo.getUri());
	LOG("Vendor: " << deviceInfo.getVendor()
		<<", VendorID: "<<deviceInfo.getUsbVendorId()
		<<", ProductID: "<<deviceInfo.getUsbProductId());
}

void printVersionNite(nite::NiTE device){
	
}