#include "Vector3.h"

Vec3::~Vec3(){
//nothing yet
}

Vec3::Vec3( Vec3& vec){
	this->_x=vec.getX();
	this->_y=vec.getY();
	this->_z=vec.getZ();
}

Vec3 Vec3::operator+(Vec3 v){
	Vec3 result(
	this->getX()+v.getX(),
	this->getY()+v.getY(),
	this->getZ()+v.getZ());
	return result;
}
Vec3 Vec3::operator+(float value){
	Vec3 result(
	this->getX()+value,
	this->getY()+value,
	this->getZ()+value);
	return result;
}
Vec3 Vec3::operator-(Vec3 v){
	Vec3 result(
	this->getX()-v.getX(),
	this->getY()-v.getY(),
	this->getZ()-v.getZ());
	return result;
}
Vec3 Vec3::operator-(float value){
	Vec3 result(
	this->getX()-value,
	this->getY()-value,
	this->getZ()-value);
	return result;
}
void Vec3::operator=(Vec3 v){
	this->setX(v.getX());
	this->setY(v.getY());
	this->setZ(v.getZ());
}
Vec3 Vec3::operator*(Vec3 v){
	Vec3 result(
	this->getX()*v.getX(),
	this->getY()*v.getY(),
	this->getZ()*v.getZ());
	return result;
}
Vec3 Vec3::operator*(float value){
	Vec3 result(
	this->getX()*value,
	this->getY()*value,
	this->getZ()*value);
	return result;
}
Vec3 Vec3::operator/(Vec3 v){
	if(v.getX()==0 || v.getY()==0 || v.getZ()==0){
		std::cout<<"<Hand_Tracker_CTI> :\t"<<("Can't divide by zero")<<std::endl;
		Vec3 result(
		this->getX(),
		this->getY(),
		this->getZ());
		return result;
	}else{
		Vec3 result(
		this->getX()/v.getX(),
		this->getY()/v.getY(),
		this->getZ()/v.getZ());
		return result;
	}
}
Vec3 Vec3::operator/(float value){
	if(value==0){
		std::cout<<"<Hand_Tracker_CTI> :\t"<<("Can't divide by zero")<<std::endl;
		Vec3 result(
		this->getX(),
		this->getY(),
		this->getZ());
		return result;
	}else{
		Vec3 result(
		this->getX()/value,
		this->getY()/value,
		this->getZ()/value);
		return result;
	}
}

/*getters and setters*/

void Vec3::setX(int x){
	this->_x=x;
};
void Vec3::setY(int y){
	this->_y=y;
};
void Vec3::setZ(int z){
	this->_z=z;
};

int Vec3::getX(){
	return this->_x;
};
int Vec3::getY(){
	return this->_y;
};
int Vec3::getZ(){
	return this->_z;
};
