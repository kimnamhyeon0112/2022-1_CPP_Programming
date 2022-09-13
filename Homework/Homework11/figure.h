#pragma once
#include <bits/stdc++.h>	//자주사용하는 헤더를 모두 포함하는 헤더, 단 vs환경에선 다운받아 적용
							//경로: C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.16.27023\include/bits

using std::pair;		//STL의 pair클래스 사용, pair란 두 객체를 하나의 객체로 취급할 수 있게 묶어주는 클래스, utility헤더에 존재
using std::vector;		//STL의 vector클래스 사용

vector<pair<double, double>> SetPoint(int n);	//vector의 pair타입을 사용하여 선언함으로써 pair 변수를 저장할 수 있게 한다.

class Figure
{
protected:
	vector<pair<double, double>> point;
	double line;
	double area;

public:
	Figure(vector<pair<double, double>> p)
	{
		point = p;
		line = 0;
		area = 0;
	}
	virtual double Area();
	~Figure() {}
	double operator+(Figure shape) { return area + shape.area; }	//연산자 오버로딩 +
	double operator-(Figure shape) { return area - shape.area; }	//연산자 오버로딩 -
	double operator*(Figure shape) { return area * shape.area; }	//연산자 오버로딩 *
	double operator/(Figure shape) { return area / shape.area; }	//연산자 오버로딩 /
};

class Circle : public Figure
{
public:
	Circle(vector<pair<double, double>> p) : Figure(p) {}
	virtual double Area();
	virtual double Line();
	virtual void PrintInfo();
	~Circle() {}
};

class Polygon : public Figure		//다각형클래스
{
public:
	Polygon(vector<pair<double, double>> p) : Figure(p) {}
	virtual void PrintInfo();
	~Polygon() {}
};