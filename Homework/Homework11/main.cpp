#include <bits/stdc++.h>
#include "figure.h"

using namespace std;
int main()
{
	int n;
	cout << "Enter number of points>> ";
	cin >> n;

	if (n == 2)		//원일 때
	{
		Circle c1(SetPoint(n));
		Circle c2(SetPoint(n));
		c1.PrintInfo();
		c2.PrintInfo();
		std::cout << fixed;	//정수부 고정
		cout.precision(2);	//소수점 2자리까지만표현
		cout << "Circle1 + Circle2 : " << c1 + c2 << endl;
		cout << "Circle1 - Circle2 : " << c1 - c2 << endl;
		cout << "Circle1 * Circle2 : " << c1 * c2 << endl;
		cout << "Circle1 / Circle2 : " << c1 / c2 << endl;
	}
	else if (n > 2)	//원이 아닐때
	{
		Polygon p1(SetPoint(n));
		Polygon p2(SetPoint(n));
		p1.PrintInfo();
		p2.PrintInfo();
		std::cout << fixed;
		cout.precision(2);
		cout << "Polygon1 + Polygon2 : " << p1 + p2 << endl;
		cout << "Polygon1 - Polygon2 : " << p1 - p2 << endl;
		cout << "Polygon1 * Polygon2 : " << p1 * p2 << endl;
		cout << "Polygon1 / Polygon2 : " << p1 / p2 << endl;
	}
	else
		cout << "Points Must Be At Least 2" << endl;

	return 0;
}