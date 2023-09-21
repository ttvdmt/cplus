#include <iostream>
#include <math.h>
#include "point.h"
#include "point.cpp"

using namespace std;

class Circle
{
private:
	Point mCenter;
	float mRadius;

public:
	Circle(const Point& acenter, float aradius)
	{
		mCenter = acenter;
		mRadius = aradius;
	}
	Circle()
	{
		mCenter = {0, 0};
		mRadius = 1;
	}
	Circle(const Circle& circle)
	{
		mCenter = circle.mCenter;
		mRadius = circle.mRadius;
	}
	void setCenter(Point point)
	{
		mCenter = point;
	}
	void setRadius(float radius)
	{	
		if (radius <= 0)
		{
			mRadius = 0;
		}
		else
		{
			mRadius = radius;
		}
	}
	Point getCenter() const
	{
		return mCenter;
	}
	float getRadius() const
	{
		return mRadius;
	}
	float getArea() const
	{
		return 3,14*mRadius*mRadius;
	}
	float getDistance(const Point& p) const
	{
		float dist = sqrt(pow(p.getX() - getCenter().getX(), 2) + pow(p.getY() - getCenter().getY(), 2));
		if (dist <= mRadius)
		{
			return getRadius() - dist;
		}
		else
		{
			return dist - getRadius();
		}
	}
	bool isColliding(const Circle& c)
	{
		float dist = sqrt(pow(c.getCenter().getX() - getCenter().getX(), 2) + pow(c.getCenter().getY() - getCenter().getY(), 2));
		return (dist <= getRadius() + c.getRadius());
	}
	void move(const Point& p)
	{
		mCenter = mCenter + p;
	}
};

int main()
{
	Point p = {7, -1};
	Point q = {-4, 2};
	cout << "Point p = " << p << endl;
	cout << "Point q = " << q << endl;
	cout << "p + q = " << p + q << endl;

	Circle a {{4, 1}, 3};
	Circle b;

	cout << "Circle a: center: " << a.getCenter() << " radius: " << a.getRadius() << endl; 
	cout << "Circle b: center: " << b.getCenter() << " radius: " << b.getRadius() << endl;

	cout << "Area of a = " << a.getArea() << endl;
	cout << "Distance from point p to circle a = " << a.getDistance(p) << endl;



	cout << "Collisions:" << endl;
	if (a.isColliding(b))
		cout << "Yes, a is colliding b" << endl;
	else
		cout << "No, a isn't colliding b" << endl;



	cout << "Moving b by {1, 1}:" << endl;
	b.move({1, 1});
	if (a.isColliding(b))
		cout << "Yes, a is colliding b" << endl;
	else
		cout << "No, a isn't colliding b" << endl;
}