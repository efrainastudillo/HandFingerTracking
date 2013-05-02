#ifndef LIBRARIES_H
#define LIBRARIES_H

#pragma comment(lib,"OpenNI2.lib")
#pragma comment(lib,"NiTE2.lib")

#pragma comment(lib,"freeglut_static.lib")
#pragma comment(lib,"GLTools.lib")

#include <iostream>
#include <OpenNI.h>
#include <PS1080.h>
#include <NiTE.h>
#include <opencv2\opencv.hpp>

//Status for manager messages
typedef enum{
	STATUS_OK=1,
	STATUS_ERROR=2,
	STATUS_UNKNOWN=3
}STATUS;

/*Pixels format*/
typedef struct
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
} RGBPixel;

typedef struct
{
	unsigned short dist;
} DepthPixel;

#define LOG(msg) (std::cout<<"<Hand_Tracker_CTI> :\t"<<msg<<std::endl);
//OPENCV LIBRARIES
#ifdef _DEBUG
	#pragma comment(lib,"opencv_calib3d243d.lib")
	#pragma comment(lib,"opencv_contrib243d.lib")
	#pragma comment(lib,"opencv_core243d.lib")
	#pragma comment(lib,"opencv_features2d243d.lib")
	#pragma comment(lib,"opencv_flann243d.lib")
	#pragma comment(lib,"opencv_gpu243d.lib")
	#pragma comment(lib,"opencv_haartraining_engined.lib")
	#pragma comment(lib,"opencv_highgui243d.lib")
	#pragma comment(lib,"opencv_imgproc243d.lib")
	#pragma comment(lib,"opencv_legacy243d.lib")
	#pragma comment(lib,"opencv_ml243d.lib")
	#pragma comment(lib,"opencv_nonfree243d.lib")
	#pragma comment(lib,"opencv_objdetect243d.lib")
	#pragma comment(lib,"opencv_photo243d.lib")
	#pragma comment(lib,"opencv_stitching243d.lib")
	#pragma comment(lib,"opencv_ts243d.lib")
	#pragma comment(lib,"opencv_video243d.lib")
	#pragma comment(lib,"opencv_videostab243d.lib")
#else
	#pragma comment(lib,"opencv_calib3d243.lib")
	#pragma comment(lib,"opencv_contrib243.lib")
	#pragma comment(lib,"opencv_core243.lib")
	#pragma comment(lib,"opencv_features2d243.lib")
	#pragma comment(lib,"opencv_flann243.lib")
	#pragma comment(lib,"opencv_gpu243.lib")
	#pragma comment(lib,"opencv_haartraining_engine.lib")
	#pragma comment(lib,"opencv_highgui243.lib")
	#pragma comment(lib,"opencv_imgproc243.lib")
	#pragma comment(lib,"opencv_legacy243.lib")
	#pragma comment(lib,"opencv_ml243.lib")
	#pragma comment(lib,"opencv_nonfree243.lib")
	#pragma comment(lib,"opencv_objdetect243.lib")
	#pragma comment(lib,"opencv_photo243.lib")
	#pragma comment(lib,"opencv_stitching243.lib")
	#pragma comment(lib,"opencv_ts243.lib")
	#pragma comment(lib,"opencv_video243.lib")
	#pragma comment(lib,"opencv_videostab243.lib")
#endif
#endif