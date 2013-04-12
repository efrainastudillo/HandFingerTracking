#include "Kinect.h"

int Kinect::estado=0;
openni::Device Kinect::device;
bool Kinect::isOK=false;

/*Singleton pattern for get one and only one instance 
 trough app lifetime*/
Kinect& Kinect::getInstance(){
	static Kinect kinect;
	return kinect;
}
//Iniatilize libraries and open device
STATUS Kinect::Initialize(){
	//initialize the libraries OPENNI
	if(openni::OpenNI::initialize()!=openni::STATUS_OK){
		LOG(openni::OpenNI::getExtendedError());
		isOK=false;
		return STATUS::STATUS_ERROR;//error
	}
	//NITE
	if(nite::NiTE::initialize()!=nite::STATUS_OK){
		LOG("Nite couldn'n initialize");
		isOK=false;
		return STATUS::STATUS_ERROR;//error
	}
	//open device
	if(device.open(openni::ANY_DEVICE)!=openni::STATUS_OK){
		LOG(openni::OpenNI::getExtendedError());
		isOK=false;
		return STATUS::STATUS_ERROR;//error
	}
	//mode registration mode
	if(!device.isImageRegistrationModeSupported(openni::ImageRegistrationMode::IMAGE_REGISTRATION_DEPTH_TO_COLOR)){
		LOG("This device not support IMAGE_REGISTRATION");
	}else{
		device.setImageRegistrationMode(openni::ImageRegistrationMode::IMAGE_REGISTRATION_DEPTH_TO_COLOR);
	}
	//create strems of the DEPTH and COLOR images
	if(this->createStreams()!=STATUS::STATUS_OK){
		LOG("Couldn't create Streams");
		isOK=false;
		return STATUS::STATUS_ERROR;//error
	}
	isOK=true;
	return STATUS::STATUS_OK;
}
//show image give it a name of file
void Kinect::showImage(cv::string namefile){
	cv::Mat imagen=cv::imread(namefile);
	cv::namedWindow(namefile);
	cv::imshow(namefile,imagen);
}
//show the image give it a cv::Mat
void Kinect::showImage(cv::Mat &imagen,std::string namewindow){
	cv::namedWindow(namewindow,CV_WINDOW_AUTOSIZE);
	cv::imshow(namewindow,imagen);
}

void Kinect::run(){
	//Acquire images and camera parameters from shared memory
	int key=-1;

	//loop until press 'q' key
	while((key=(cv::waitKey(5)&0x000000FF))!='q'){
		openni::VideoFrameRef depthFrame,colorFrame;
		niDepthS.readFrame(&depthFrame);
		niColorS.readFrame(&colorFrame);
		if(depthFrame.isValid() && colorFrame.isValid()){
			//
			openni::VideoMode vm= colorFrame.getVideoMode();
			openni::PixelFormat pf=vm.getPixelFormat();
			printPixelFormat(pf);
			vm= depthFrame.getVideoMode();
			pf=vm.getPixelFormat();
			printPixelFormat(pf);
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
	cv::destroyAllWindows();
}

void Kinect::printPixelFormat(openni::PixelFormat px){
	switch(px){
	case openni::PIXEL_FORMAT_JPEG:
			LOG("PIXEL FORMAT JPG");
		break;
	case openni::PIXEL_FORMAT_RGB888:
			LOG("PIXEL FORMAT RGB888");
		break;
	case openni::PIXEL_FORMAT_DEPTH_100_UM:
			LOG("PIXEL_FORMAT_DEPTH_100_UM");
		break;
	case openni::PIXEL_FORMAT_DEPTH_1_MM:
			LOG("PIXEL_FORMAT_DEPTH_1_MM");
		break;
	case openni::PIXEL_FORMAT_GRAY16:
			LOG("PIXEL_FORMAT_GRAY16");
		break;
	case openni::PIXEL_FORMAT_GRAY8:
			LOG("PIXEL_FORMAT_GRAY8");
		break;
	case openni::PIXEL_FORMAT_SHIFT_9_2:
			LOG("PIXEL_FORMAT_SHIFT_9_2");
		break;
	case openni::PIXEL_FORMAT_SHIFT_9_3:
			LOG("PIXEL_FORMAT_SHIFT_9_3");
		break;
	case openni::PIXEL_FORMAT_YUV422:
			LOG("PIXEL_FORMAT_YUV422");
		break;
	default:
			LOG("UNKNOWN");
		break;
	}
}
//create strems of the DEPTH and COLOR images
STATUS Kinect::createStreams(){
	bool status =false;

	//create a depth sensor
	if (device.getSensorInfo(openni::SENSOR_DEPTH) != NULL)
	{
		openni::Status rc = niDepthS.create(device, openni::SENSOR_DEPTH);
		if (rc == openni::STATUS_OK)
		{			
			if(niDepthS.start()!= openni::STATUS_OK)
			{
				LOG(std::string("Couldn't start the color stream: ")+ openni::OpenNI::getExtendedError());
				return STATUS::STATUS_ERROR;
			}
		}
		else
		{
			LOG(std::string("Couldn't create depth stream: ")+ openni::OpenNI::getExtendedError());
			return STATUS::STATUS_ERROR;
		}
	}
	//create a sensor color
	if (device.getSensorInfo(openni::SENSOR_COLOR) != NULL)
	{
		openni::Status rc = niColorS.create(device, openni::SENSOR_COLOR);
		if (rc == openni::STATUS_OK)
		{
			if(niColorS.start() != openni::STATUS_OK)
			{
				LOG(std::string("Couldn't start the color stream")+ openni::OpenNI::getExtendedError());
				return STATUS::STATUS_ERROR;
			}
		}
		else
		{
			LOG(std::string("Couldn't create color stream")+ openni::OpenNI::getExtendedError());
			return STATUS::STATUS_ERROR;
		}
	}
	return STATUS::STATUS_OK;
}
/*Print Version Of Library and of the Device attached USB way*/
void Kinect::printVersion(){
	openni::DeviceInfo deviceInfo;
	if(!isOK){
		LOG("Can't printVersion, Kinect haven't initialized succesfull"); 
		return;
	}
	deviceInfo = device.getDeviceInfo();
	LOG("Name: "<<deviceInfo.getName());
	LOG("URI: "<<deviceInfo.getUri());
	LOG(  "Vendor: " << deviceInfo.getVendor()
		<<", VendorID: "<<deviceInfo.getUsbVendorId()
		<<", ProductID: "<<deviceInfo.getUsbProductId());
}

void Kinect::addOne(){
	estado++;
}

//destructor
Kinect::~Kinect(){}

//private section dont implement
Kinect::Kinect(){}
Kinect::Kinect(const Kinect&){}
Kinect& Kinect::operator=(const Kinect&){ 
	return this->getInstance();
}