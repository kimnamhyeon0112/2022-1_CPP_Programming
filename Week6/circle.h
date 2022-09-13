#pragma once
#include <iostream>

class Circle
{
private:
	int x, y, r;
	double area;
public:
	Circle()
	{
		x = 0;
		y = 0;
		r = 0;
		area = 0.0;
	}
	int getX() { return this->x; }
	int getY() { return this->y; }
	int getR() { return this->r; }
	double getArea() { return this->area; }
}; //6주차 실습예제11

#pragma once
#include <iostream>
#include <cassert>

class Circle
{
private:
	int x, y, r;
	double area;
public:
	Circle()
	{
		x = 0;
		y = 0;
		r = 0;
		area = 0.0;
	}

	Circle(int _x, int _y, int _r, double _area = 1.0)
	{
		assert(_area != 0.0);
		int getX() { return this->x; }
		int getY() { return this->y; }
		int getR() { return this->r; }
		double getArea() { return this->area; }
	}
}; //6주차 실습예제12

#pragma once
#include <iostream>
#include <cassert>
using namespace std;

class Circle
{
private:
	int x, y, r;
	double area;
public:
	Circle(int _x = 0, int _y = 0, int _r = 0, double _area = 1.0)
		:x(_x), y(_y), r(_r), area(_area)
	{
		assert(_area != 0.0);
	}
	int getX() { return this->x; }
	int getY() { return this->y; }
	int getR() { return this->r; }
	double getArea() { return this->area; }
}; //6주차 실습예제13

#pragma once
#include <iostream>
#include <cassert>
using namespace std;

class Circle
{
private:
	int *coordinate, radius;
	double area;
public:
	Circle(int _x = 0, int _y = 0, int _r = 0, double _area = 1.0)
		:radius(_r), area(_area)
	{
		this->coordinate = new int[static_cast<size_t>(2)]{ _x,_y };
		assert(_area != 0.0);
	}
	int getX() { return this->coordinate[0]; }
	int getY() { return this->coordinate[1]; }
	int getR() { return this->radius; }
	double getArea() { return this->area; }
	
	~Circle()
	{
		cout << "by " << this->coordinate[0] << ", " << this->coordinate[1] << endl;
		delete[] coordinate;
	}
}; //6주차 실습예제14