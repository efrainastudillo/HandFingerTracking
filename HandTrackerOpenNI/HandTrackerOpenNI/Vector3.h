#ifndef VEC3_H
#define VEC3_H
#pragma once
#include <iostream>
#include <exception>

class Vec3{
public:
	Vec3(): _x(0),_y(0),_z(0){/*not implement*/} ;
	Vec3(int x,int y, int z):_x(x),_y(y),_z(z){/*not implement*/};
	Vec3(Vec3& vec);
	~Vec3();
	
	//overwrite operators
	Vec3 operator+(Vec3);
	Vec3 operator+(float value);
	Vec3 operator-(Vec3);
	Vec3 operator-(float value);
	void operator=(Vec3);
	Vec3 operator*(Vec3);
	Vec3 operator*(float value);
	Vec3 operator/(Vec3);
	Vec3 operator/(float value);

	//getters & setters
	void setX(int x);
	void setY(int y);
	void setZ(int z);

	int getX();
	int getY();
	int getZ();

	static Vec3 zero();
	static Vec3 one();

	friend std::ostream& operator<<(std::ostream &strm, const Vec3 &a) {
		return strm << "VEC3("<< a._x << ", "<<a._y<<", "<<a._z<<")";
	};
private:
	int _x;
	int _y;
	int _z;
};
#endif