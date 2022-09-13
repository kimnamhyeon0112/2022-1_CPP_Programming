#pragma once
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int sel;
int select(int sel)
{
	cout << "---���ϴ� ������ �����ϼ���---" << endl;
	cout << "1. ����" << endl;
	cout << "2. ������" << endl;
	cout << "3. ������" << endl;
	cout << "4. ����" << endl;
	cout << "5. �ʰ�" << endl;
	cout << "6. �̸�" << endl;
	cout << "7. �̻�" << endl;
	cout << "8. ����" << endl;
	cout << "9. ����" << endl;
	cout << "10. �����ʴ�" << endl;
	cout << "�Է�: ";
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

	Point operator * (Point t)				//1. ����
	{
		return Point(x * t.x, y * t.y);
	}

	Point operator / (Point t)				//2. ������
	{
		return Point(x / t.x, y / t.y);
	}

	Point operator % (Point t)				//3. ������
	{
		return Point(x % t.x, y % t.y);
	}

	Point operator ^ (Point t)				//4. ����
	{
		return Point(x * t.x, y * t.y);
	}

	Point operator > (Point t)				//5. �ʰ�
	{
		return Point(x ^ t.x, y ^ t.y);
	}

	Point operator < (Point t)				//6. �̸�	
	{
		return Point(x > t.x, y > t.y);
	}

	Point operator >= (Point t)				//7. �̻�
	{
		return Point(x < t.x, y < t.y);
	}

	Point operator <= (Point t)				//8. ����
	{
		return Point(x >= t.x, y >= t.y);
	}

	Point operator == (Point t)				//9. ����
	{	
		return Point(x <= t.x, y <= t.y);
	}

	Point operator != (Point t)				//10. �����ʴ�
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