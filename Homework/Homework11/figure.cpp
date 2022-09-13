#include "figure.h"

vector<pair<double, double>> SetPoint(int n)
{
	vector<pair<double, double>> v;

	static int ShapeCounter = 0;	//main에서 입력받은 point의 갯수로 n각형 만큼의 점 입력
	double Temp1 = 0;
	double Temp2 = 0;

	std::cout << "Shape " << ++ShapeCounter << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cout << "Enter X" << i + 1 << " : ";
		std::cin >> Temp1;
		std::cout << "Enter Y" << i + 1 << " : ";
		std::cin >> Temp2;
		v.push_back(std::make_pair(Temp1, Temp2));	//pair 타입을 저장하는 vector이므로 make_pair을 사용해 주어서 값을 저장하고 있다.
	}
	std::cout << std::endl;
	return v;
}

double Figure::Area()
{
	if (area != 0)
		return area;

	double Temp1 = 0.0;
	double Temp2 = 0.0;

	for (int i = 0; i < point.size(); i++)
	{
		int j = (i + 1) % point.size();
		Temp1 += point[i].first * point[j].second;	//신발끈공식
		Temp2 += point[j].first * point[i].second;	//신발끈공식
	}

	area = abs(Temp1 - Temp2) * 0.5;
	return area;
}

double Circle::Line()
{
	if (line == 0)
		line = sqrt(pow(point[0].first - point[1].first, 2) + pow(point[0].second - point[1].second, 2));
	return line;
}

double Circle::Area()
{
	if (area != 0)
		return area;
	if (line == 0)
		area = pow(Circle::Line(), 2) * 3.14;
	else
		area = pow(line, 2) * 3.14;
	return area;
}

void Circle::PrintInfo()
{
	std::cout << "Coord : ";
	for (int i = 0; i < 2; i++)
		std::cout << "(" << point[i].first << ", " << point[i].second << ") ";
	std::cout << "\nRadius : " << Circle::Line() << std::endl;
	std::cout << "Area : " << Circle::Area() << std::endl;
}

void Polygon::PrintInfo()
{
	std::cout << "Coord : ";
	for (int i = 0; i < point.size(); i++)
	{
		std::cout << "(" << point[i].first << ", " << point[i].second << ") ";
	}
	std::cout << "\nArea : " << Area() << std::endl;
}