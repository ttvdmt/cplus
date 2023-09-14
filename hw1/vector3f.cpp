#include <iostream>
#include <math.h>
#include "complex.h"

struct Vector3f{
	float x;
	float y;
	float z;
};

Vector3f operator+(Vector3f& a, Vector3f& b){
	Vector3f result = a;
	result.x += b.x;
	result.y += b.y;
	result.z += b.z;
	return result;
}

Vector3f operator-(Vector3f& a, Vector3f& b){
	Vector3f result = a;
	result.x -= b.x;
	result.y -= b.y;
	result.z -= b.z;
	return result;
}

Vector3f operator*(Vector3f& a, float n){
	Vector3f result = a;
	result.x * n;
	result.y * n;
	result.z * n;
	return result;
}

Vector3f operator*(float n, Vector3f& a){
	return a * n;
}

float operator*(Vector3f& a, Vector3f& b){
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

Vector3f operator+(Vector3f& a){
	return a;
}

Vector3f operator-(Vector3f& a){
	Vector3f result = a;
	result.x = -a.x;
	result.y = -a.y;
	result.z = -a.z;
	return result;
}

bool operator==(Vector3f& a, Vector3f& b){
	return (a.x == b.x && a.y == b.y && a.z == b.z);
}

bool operator!=(Vector3f& a, Vector3f& b){
	return !(a == b);
}

Vector3f operator+=(Vector3f& a, Vector3f& b){
	Vector3f result = a;
	result.x += b.x;
	result.y += b.y;
	result.z += b.z;
	return result;
}

Vector3f operator-=(Vector3f& a, Vector3f& b){
	Vector3f result = a;
	result.x -= b.x;
	result.y -= b.y;
	result.z -= b.z;
	return result;
}

Vector3f operator*=(Vector3f& a, float n){
	Vector3f result = a;
	result.x *= n;
	result.y *= n;
	result.z *= n;
	return result;
}

Vector3f operator/=(Vector3f& a, float n){
	Vector3f result = a;
	result.x /= n;
	result.y /= n;
	result.z /= n;
	return result;
}

std::ostream& operator<<(std::ostream& out, Vector3f& a){
	out << "(" << a.x << "," << a.y << "," << a.z << ")";
	return out;
}

std::ostream& operator>>(std::ostream& in, Vector3f& a){
	in >> a.x >> a.y >> a.z;
	return in;
}

float squaredNorm(const Vector3f& a){
	return a.x*a.x + a.y*a.y + a.z*a.z;
}

float norm(const Vector3f& a){
	return sqrt(squaredNorm(a));
}

void normalize(Vector3f& a){
	float len = norm(a);
	a.x /= len;
	a.y /= len;
	a.z /= len;
}

