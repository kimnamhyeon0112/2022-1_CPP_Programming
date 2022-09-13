#include <iostream>
#include <string>
using namespace std;

int main()
{
	int i, j;
	char c, d;
	string s;

	std::cout << "Input" << std::endl;
	std::cout << "i : ";
	std::cin >> i;
	std::cout << "j : ";
	std::cin >> j;
	std::cout << "c : ";
	std::cin >> c;
	std::cout << "d: ";
	std::cin >> d;
	std::cout << "s : ";
	std::cin >> s;

	std::cout << "Output" << std::endl;
	std::cout << "i : " << i << ", j : " << j << ", c : " << c << ", d : " << d << std::endl;
	std::cout << "s : " << s << std::endl;
}	//예제1

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int i, j;
	string s;
	
	cout << "Input " << endl;
	cout << "i :";
	cin >> i;
	cout << "j :";
	cin >> j;
	cout << "s :";
	getline(cin, s);
	cout << "Output " << endl;
	cout << "i : " << i << ", j : " << j << endl;
	cout << "s : " << s << endl;
	return 0;
}	//예제2

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int i, j;
	string s;

	cout << "Input " << endl;
	cout << "i :";
	cin >> i;
	cout << "j :";
	cin >> j;
	cin.ignore(1, '\n');
	cout << "s :";
	getline(cin, s);
	cout << "Output " << endl;
	cout << "i : " << i << ", j : " << j << endl;
	cout << "s : " << s << endl;
	return 0;
}	//예제3

#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string name, phone_num, ID;
	int age;
	bool gender;
public:
	void study();
};

int main()
{
	Student Kim, Park, Lee;
	return 0;
}	//예제 4,5

#include "Person.h"

int main()
{
	Person p("00-00", 10, "Kim");
	p.move();
	p.talk();

	Student s("00-01", 22, "Lee", "CBNU", "2021020001");
	s.move();
	s.Person::move();
	s.talk();
	s.study();

	return 0;
}	//예제6

#include <iostream>
using namespace std;

int sum(int i)
{
	return i + 1;
}
int sum(int i, int j)
{
	return i + j;
}
int sum(int i, int j, int k)
{
	return i + j + k;
}

int main()
{
	cout << "sum(1) : " << sum(1) << endl;
	cout << "sum(5, 10) : " << sum(5, 10) << endl;
	cout << "sum(10, 20, 30) : " << sum(10, 20, 30) << endl;
	return 0;
}	//예제7

#include <iostream>
using namespace std;

int sum(int i)
{
	return i + 1;
}
int sum(int i, int j, int k = 10)
{
	return i + j + k;
}
int sum(int i, int j, int k)
{
	return i + j + k;
}

int main()
{
	cout << "sum(1) : " << sum(1) << endl;
	cout << "sum(5, 10) : " << sum(5, 10) << endl;
	cout << "sum(10, 20, 30) : " << sum(10, 20, 30) << endl;
	return 0;
}	//예제8

#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string name = "";
	int phone_num = 0;
	double score = 0;
public:
	Student(string _name, int _phone_num, double _score)
	{
		this->name = _name;
		this->phone_num = _phone_num;
		this->score = _score;
		cout << "Hello Student!" << endl;
	}
	void speaking();
	void input_information();
	void print_information();
	~Student()
	{
		cout << "By Student!" << endl;
	}
}; //예제10

#include "circle.h"
using namespace std;
int main()
{
	Circle c;
	cout << "Coordinate X, Y : " << c.getX() << ", " << c.getY() << endl;
	cout << "Radius : " << c.getR() << ", Area : " << c.getArea();
}	//예제11

#include "circle.h"
using namespace std;

void PrintCircleInfor(Circle c)
{
	cout << "Coordinate X, Y : " << c.getX() << ", " << c.getY() << endl;
	cout << "Radius : " << c.getR() << ", Area : " << c.getArea();
}

int main()
{
	Circle c1;
	PrintCircleInfor(c1);
	cout << endl << endl;

	Circle c2(0, 0, 0);
	PrintCircleInfor(c2);
	return 0;
}	//예제12

#include "circle.h"
using namespace std;

void PrintCircleInfor(Circle c)
{
	cout << "Coordinate X, Y : " << c.getX() << ", " << c.getY() << endl;
	cout << "Radius : " << c.getR() << ", Area : " << c.getArea() << endl;
}

int main()
{
	Circle c1;
	PrintCircleInfor(c1);
	cout << endl;

	Circle c2(1, 1, 1, 1);
	PrintCircleInfor(c2);
	cout << endl;

	Circle c3 = { 2,2,2 };
	PrintCircleInfor(c3);
	cout << endl;

	Circle c4 = Circle(3, 3);
	PrintCircleInfor(c4);
	cout << endl;

	Circle c5 = 4;
	PrintCircleInfor(c5);
	return 0;
}	//예제13

#include "circle.h"
using namespace std;

void PrintCircleInfor(Circle &c)
{
	cout << "Call by Reference" << endl;
	cout << "Coordinate X, Y : " << c.getX() << ", " << c.getY() << endl;
	cout << "Radius : " << c.getR() << ", Area : " << c.getArea() << endl;
}

void PrintCircleInfor(Circle *c)
{
	cout << "Call by Pointer" << endl;
	cout << "Coordinate X, Y : " << c->getX() << ", " << c->getY() << endl;
	cout << "Radius : " << c->getR() << ", Area : " << c->getArea() << endl;
}

int main()
{
	Circle c1;
	PrintCircleInfor(&c1);
	cout << endl;

	Circle c2(1, 1, 1, 1);
	PrintCircleInfor(c2);
	cout << endl;

	Circle *c3 = new Circle{ 2,2,2,2 };
	PrintCircleInfor(c3);
	cout << endl;
	
	delete c3;
	return 0;
}	//예제14