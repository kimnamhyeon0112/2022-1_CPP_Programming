#pragma once
#include<iostream>
#include<cmath>
#define PI 3.14

using namespace std;
class Circle
{
private:
	int x;
	int y;
	int r;
	double area;

public:
	Circle()
	{
		x = 0; y = 0; r = 0; area = 0;
	}
	void input(int x_point, int y_point, int radius);
	void show();
	double Area();
	bool check_distance(Circle* pick, Circle* cmpptr);
	int check_arr(Circle* arr, int start, int end);
	~Circle() {  }
};