#pragma once

class Vector3{
public:
	Vector3(): _x(0),_y(0),_z(0){/*not implement*/} ;
	Vector3(int x,int y, int z):_x(x),_y(y),_z(z){/*not implement*/};
	Vector3(const Vector3& vec);
	~Vector3();
	//overwrite operators
	Vector3 operator+(Vector3);
	Vector3 operator+(float value);
	Vector3 operator-(Vector3);
	Vector3 operator-(float value);
	Vector3 operator=(Vector3);
	Vector3 operator*(Vector3);
	Vector3 operator*(float value);
	Vector3 operator/(Vector3);
	Vector3 operator/(float value);
	static Vector3 zero();
	static Vector3 one();
private:
	int _x;
	int _y;
	int _z;
};