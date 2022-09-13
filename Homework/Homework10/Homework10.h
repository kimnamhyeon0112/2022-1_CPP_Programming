#pragma once
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int sel;
int select(int sel)
{
	cout << "---원하는 연산을 선택하세요---" << endl;
	cout << "1. 곱셉" << endl;
	cout << "2. 나눗셈" << endl;
	cout << "3. 나머지" << endl;
	cout << "4. 제곱" << endl;
	cout << "5. 초과" << endl;
	cout << "6. 미만" << endl;
	cout << "7. 이상" << endl;
	cout << "8. 이하" << endl;
	cout << "9. 같다" << endl;
	cout << "10. 같지않다" << endl;
	cout << "입력: ";
	cin >> sel;
	return sel;
}
int Select = select(sel);

class Point	
{
private:
	int x, y;
public:
	Point(int _x, int _y) :x(_x), y(_y) {}

	Point operator * (Point t)				//1. 곱셈
	{
		return Point(x * t.x, y * t.y);
	}

	Point operator / (Point t)				//2. 나눗셈
	{
		return Point(x / t.x, y / t.y);
	}

	Point operator % (Point t)				//3. 나머지
	{
		return Point(x % t.x, y % t.y);
	}

	Point operator ^ (Point t)				//4. 제곱
	{
		return Point(x * t.x, y * t.y);
	}

	Point operator > (Point t)				//5. 초과
	{
		return Point(x ^ t.x, y ^ t.y);
	}

	Point operator < (Point t)				//6. 미만	
	{
		return Point(x > t.x, y > t.y);
	}

	Point operator >= (Point t)				//7. 이상
	{
		return Point(x < t.x, y < t.y);
	}

	Point operator <= (Point t)				//8. 이하
	{
		return Point(x >= t.x, y >= t.y);
	}

	Point operator == (Point t)				//9. 같다
	{	
		return Point(x <= t.x, y <= t.y);
	}

	Point operator != (Point t)				//10. 같지않다
	{
		return Point(x == t.x, y == t.y);
	}

	operator double() const
	{
		if (Select == 1)
			return (x * y);
		else if (Select == 2)
			return (x / y);
		else if (Select == 3)
			return (x % y);
		else if (Select == 4)
			return pow((x, 2), (y, 2));
		else if (Select == 5)
			return (x > y);
		else if (Select == 6)
			return (x < y);
		else if (Select == 7)
			return (x >= y);
		else if (Select == 8)
			return (x <= y);
		else if (Select == 9)
			return (x == y);
		else if (Select == 10)
			return (x != y);
	}

	friend std::ostream& operator <<(ostream& out, const Point& p)
	{
		out << " ( " << p.x << " , " << p.y << " ) ";
		return out;
	}
};