#include "Kinect.h"
#include "Vector3.h"
#include "ViewerGL.h"

void printVersionOpenNI(openni::Device &dev);

using namespace std;

int main(int argc, char *argv[]){
	if(Kinect::getInstance().Initialize()!=STATUS::STATUS_OK){
		LOG("Failed Initialized");
		return 1;
	};
	Kinect::getInstance().printVersion();
	//Kinect::getInstance().run();
	
	if(!ViewerGL::getInstance().setup(argc,argv)){
		LOG("No se pudo iniacilzar GLEW");
		return 1;
	}
	ViewerGL::getInstance().initialize();
	ViewerGL::getInstance().run();
	LOG("Hello World I am to the end of the main");
	//system("pause");
	return 0;
}