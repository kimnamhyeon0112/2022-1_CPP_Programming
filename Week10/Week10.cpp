#include <iostream>
using namespace std;

int sum(int i)		//함수 오버로딩
{
	return i + 1;
}

int sum(int i, int j)	//함수 오버로딩
{
	return i + j;
}

int sum(int i, int j, int k)	//함수 오버로딩
{
	return i + j + k;
}

int main()
{
	cout << "sum(1) : " << sum(1) << endl;
	cout << "sum(5, 10) : " << sum(5, 10) << endl;
	cout << "sum(10, 20, 30) : " << sum(10, 20, 30) << endl;
	return 0;
}	//10주차 실습예제 1

#include <iostream>
using namespace std;

int sum(int i)
{
	return i + 1;
}

int sum(int i, int j, int k = 10)		//오버로딩 모호성 why? 아래의 함수와 완전 동일, 컴파일러가 구분 불가
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
}	//10주차 실습예제 2

#include <iostream>
using namespace std;

class Point
{
private:
	int x, y;
public:
	Point(int _x, int _y) : x(_x), y(_y) {}
	Point sum(Point t)
	{
		Point temp(x + t.x, y + t.y);
		return temp;
	}
	void pPrint()
	{
		cout << "x : " << x << ", y : " << y << endl;
	}
	~Point() {}
};

int main()
{
	Point p1(10, 20);
	Point p2(20, 30);
	//Point p3 = p1 + p2;		연산자 오버로딩 x
	Point p3 = p1.sum(p2);
	p3.pPrint();
	return 0;
}	//10주차 실습예제 3

#include <iostream>
using namespace std;

class Point
{
private:
	int x, y;
public:
	Point(int _x, int _y) :x(_x), y(_y) {}
	Point sum(Point t)
	{
		Point temp(x + t.x, y + t.y);
		return temp;
	}
	Point operator + (Point t)
	{
		return Point(x + t.x, y + t.y);
	}
	void pPrint()
	{
		cout << "x : " << x << ", y : " << y << endl;
	}
	~Point() {}
};

int main()
{
	Point p1(20, 20);
	Point p2(50, 70);
	Point p3 = p1 + p2;		//연산자 오버로딩 o
	//Point p3 = p1.sum(p2);
	p3.pPrint();
	return 0;
}	//10주차 실습예제 4

#include <iostream>
#include <cmath>
using namespace std;

class Point
{
private:
	int x, y;
public:
	Point(int _x, int _y) :x(_x), y(_y) {}
	
	Point operator + (Point t)
	{
		return Point(x + t.x, y + t.y);
	}

	Point operator - (Point t)
	{
		return Point(x - t.x, y - t.y);
	}

	operator double() const
	{
		return sqrt(x*x + y * y);
	}

	friend std::ostream& operator<<(ostream& out, const Point& p)
	{
		out << " ( " << p.x << " , " << p.y << " ) ";
		return out;
	}
};

int main()
{
	Point p = { 10,20 };
	double l = p;
	cout << l << endl;
	cout << p << endl;

	return 0;
}	//10주차 실습예제 5

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
}	//10주차 실습예제 6

#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	Person() { cout << "Hello Person first" << endl; }
	virtual ~Person() { cout << "Hello Person first" << endl; }
	virtual void talk(string n) { cout << "Hello Person" << n << endl; }
	void move() { cout << "Go to the Home" << endl; }
};

class Elementary :Person
{
public:
	Elementary() { cout<<"Hello Elementary" << endl; }
	~Elementary() { cout<<"Bye Elementary" << endl; }
	void talk(string n)override { cout << "Hello Persn Override " << n << endl; }
	void move() { cout << "Go to the Elementary" << endl; }
};

int main()
{
	Person *pe = (Person*)new Elementary();
	cout << "-시작-" << endl;
	pe->talk("Kim");
	pe->move();
	cout << "-끝-" << endl;
	delete pe;
	return 0;
}	//10주차 실습예제 7, 9주차 과제

#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
public:
	Person() {}
	virtual void talk(string n)
	{
		cout << "hello " << n << endl;
	}
	virtual void move() = 0;
	virtual ~Person() {}
};

class Student : public Person
{
private:
public:
	Student() {}
	void move() 
	{
		cout << "Go to the school" << endl;
	}
	~Student() {}
};

class Worker : public Person
{
private:
public:
	Worker() {}
	void move()
	{
		cout << "Go to the office" << endl;
	}
	~Worker() {}
};

int main(void)
{
	Person *s = new Student();
	s->talk("Kim");
	s->move();
	cout << endl;
	Person *w = new Worker();
	w->talk("Park");
	w->move();

	delete s;
	delete w;
	return 0;
}	//10주차 실습예제 8