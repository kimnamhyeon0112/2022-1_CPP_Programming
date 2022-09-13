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
}	//11주차 실습예제 1

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
}	//11주차 실습예제 2

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
}	//11주차 실습예제 3

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
	Point p3 = p1 + p2;		//연산자 오버로딩 x
	//Point p3 = p1.sum(p2);
	p3.pPrint();
	return 0;
}	//11주차 실습예제 4

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
}	//11주차 실습예제 5

#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
	string ssNumber;
protected:
	int age;
	string name;
public:
	Person(string _ssNumber = "", int _age = 0, string _name = "")
		:ssNumber(_ssNumber), age(_age), name(_name) {}
	~Person() {}
	void move();
};

class Student : public Person
{
private:
	string academic;
	string id;
public:
	Student(string _ssNumber = "", int _age = 0, string _name = "", string _academic = "", string _id = "")
		:Person(_ssNumber, _age, _name), academic(_academic), id(_id) {}
	~Student() {}
	void move();
	void study();
};

void Person::move()
{
	cout << this->name << "is going home" << endl;
}
void Student::move()
{
	cout << this->name << "is going" << this->academic << "University" << endl;
}
void Student::study()
{
	cout << "I'm studying c++" << endl;
}

int main()
{
	Person p("00-00", 10, "Kim");
	p.move();

	Student s("00-01", 22, "Lee", "CBNU", "2021020001");
	s.move();
	s.Person::move();
	s.study();
	return 0;
}	//11주차 실습예제 6

#include "Person.h"
using namespace std;

int main()
{
	Person p1;
	Person *p2;
	Student s1;
	Student* s2;
	int i;
	float f;

	f = 10.111;
	i = static_cast<int>(f);
	cout << "int i: " << i << endl;

	f = static_cast<float>(i);
	cout << "float i: " << f << endl;

	//s1 = static_cast<Student>(s1);
	//s1.talk("KIM");

	//p2 = static_cast<Student*>(&p1);
	//p2->talk("PARK");
}	//11주차 실습예제 7

#include <iostream>
using namespace std;

int main()
{
	const int *const_int_ptr = new int(10);
	int *int_ptr;
	cout << *const_int_ptr << endl;
	int_ptr = const_cast<int*>(const_int_ptr);
	*int_ptr = 20;
	cout << *const_int_ptr << endl;
	return 0;
}	//11주차 실습예제 8

#include <iostream>
using namespace std;

int main()
{
	int *int_ptr = new int(10);
	const int *c_int_ptr = new int(15);
	char *char_ptr;
	cout << "Before" << endl;
	cout << "*int_ptr: " << *int_ptr << endl;
	cout << "*c_int_ptr: " << *c_int_ptr << endl;

	char_ptr = reinterpret_cast<char*>(int_ptr);
	*char_ptr = 20;
	cout << "명시적 형변환" << endl;
	cout << "*int_ptr: " << *int_ptr << endl;

	char_ptr = reinterpret_cast<char*>(const_cast<int*>(c_int_ptr));
	*char_ptr = 30;

	cout << "const 지정자 사용시" << endl;
	cout << "*int_ptr: " << *int_ptr << endl;
	cout << "*c_int_ptr: " << *c_int_ptr << endl;
	return 0;
}	//11주차 실습예제 9

#include "Person.h"
using namespace std;

int main()
{
	Person* ptr_p = new Student();
	Student* ptr_s;

	ptr_p->talk("Kim");
	ptr_s = dynamic_cast<Student*>(ptr_p);
	if (ptr_p == nullptr)
	{
		cout << "error compile" << endl;
	}
	ptr_s->talk("Lee");
	delete ptr_p;
	return 0;
}	//11주차 실습예제 10

#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	Person() { cout << "Hello Person" << endl; }
	~Person() { cout << "Bye Person" << endl; }
	void talk() { cout << "Person" << endl; }
};

class Elementary : public Person
{
public:
	Elementary() { cout << "Hello Elementary" << endl; }
	~Elementary() { cout << "Bye Elementary" << endl; }
	void talk() { cout << "Elementary" << endl; }
};

class Middle : public Person
{
public:
	Middle() { cout << "Hello Middle" << endl; }
	~Middle() { cout << "Bye Middle" << endl; }
	void talk() { cout << "Middle" << endl; }
};

int main()
{
	cout << "Upcasting Declare" << endl;
	Person *pe = (Person*)new Elementary();
	cout << "Downcasting Declare" << endl;
	Middle *mp = (Middle*)new Person();

	cout << "------strat------" << endl;
	pe->talk();
	mp->talk();
	cout << "------end------" << endl;

	cout << "Upcasting Delete" << endl;
	delete pe;
	cout << "Downcasting Delete" << endl;
	delete mp;
	return 0;
}	//11주차 실습예제 11

#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	Person() { cout << "Hello Person" << endl; }
	virtual ~Person() { cout << "Bye Person" << endl; }
	void talk() { cout << "Person" << endl; }
};

class Elementary : public Person
{
public:
	Elementary() { cout << "Hello Elementary" << endl; }
	~Elementary() { cout << "Bye Elementary" << endl; }
	void talk() { cout << "Elementary" << endl; }
};

class Middle : public Person
{
public:
	Middle() { cout << "Hello Middle" << endl; }
	~Middle() { cout << "Bye Middle" << endl; }
	void talk() { cout << "Middle" << endl; }
};

int main()
{
	cout << "Upcasting Declare" << endl;
	Person *pe = (Person*)new Elementary();
	cout << "Downcasting Declare" << endl;
	Middle *mp = (Middle*)new Person();

	cout << "------strat------" << endl;
	pe->talk();
	mp->talk();
	cout << "------end------" << endl;

	cout << "Upcasting Delete" << endl;
	delete pe;
	cout << "Downcasting Delete" << endl;
	delete mp;
	return 0;
}	//11주차 실습예제 12

#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	Person(){ cout << "Hello Person first" << endl; }
	virtual ~Person() { cout << "Bye Person" << endl; }
};

class Elementary : public Person
{
public:
	Elementary() { cout << "Hello Elementary" << endl; }
	~Elementary() { cout << "Bye Elementary" << endl; }
};

class Middle : public Person
{
public:
	Middle() { cout << "Hello Middle" << endl; }
	virtual ~Middle() { cout << "Bye Middle" << endl; }
};

int main()
{
	Elementary e;
	Middle m;
	cout << "-끝-" << endl;
	return 0;
}	//11주차 실습예제 13

#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	Person() { cout << "Hello Person first" << endl; }
	virtual ~Person() { cout << "Bye Person" << endl; }
	virtual void talk(string n) { cout << "Hello Person" << n << endl; }
	void move() { cout << "Go to the Home" << endl; }
};

class Elementary : public Person
{
public:
	Elementary() { cout << "Hello Elementary" << endl; }
	~Elementary() { cout << "Bye Elementary" << endl; }
	void talk(string n) { cout << "Hello Person Override " << n << endl; }
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
}	//11주차 실습예제 14

#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	Person() {}
	virtual ~Person() {}
	virtual void talk(string n) { cout << "My name is " << n << endl; }
	virtual void move() = 0;
};

class Student : public Person
{
public:
	Student() {}
	~Student() {}
	void talk(string s)override { cout << s << ", I am studying" << endl; }
	void move() override { cout << "Go to the school" << endl; }
};

class Employeer : public Person
{
public:
	Employeer() {}
	~Employeer() {}
	void talk() { cout << ", I am working" << endl; }
	void move() { cout << "Go to the office" << endl; }
};

int main()
{
	Person *s = new Student();
	s->move();
	s->talk("Kim");

	Person *e = new Employeer();
	e->move();
	e->talk("Tim");

	delete s;
	delete e;
	return 0;
}	//11주차 실습예제 15

#include <iostream>
using namespace std;

int main()
{
	auto a = 10;
	auto b = 1.1;
	auto c = 'c';
	auto d = "string";

	cout << "Type of a : " << typeid(a).name() << endl;
	cout << "Type of b : " << typeid(b).name() << endl;
	cout << "Type of c : " << typeid(c).name() << endl;
	cout << "Type of d : " << typeid(d).name() << endl;
}	//11주차 실습예제 16

#include <iostream>
using namespace std;

int main()
{
	auto a;
	return 0;
}   //11주차 실습예제 17

#include <iostream>
using namespace std;

int main()
{
	auto a = 10;
	auto cpy_a = a;

	cout << "a : " << a << ", type of a : " << typeid(a).name() << endl;
	cout << "cpy_a : " << cpy_a << ", type of cpy_a : " << typeid(cpy_a).name() << endl;
	return 0;
}	//11주차 실습예제 18

#include <iostream>
using namespace std;

int main()
{
	auto a = 10;
	auto& b = a;

	cout << "a : " << a << ", a address : " << &a << endl;
	cout << "b : " << b << ", b address : " << &b << endl;
}	//11주차 실습예제 19

#include <iostream>
using namespace std;

int main()
{
	auto a = 10;
	auto* b = &a;

	cout << "a : " << a << ", a address : " << &a << endl;
	cout << "b : " << b << ", b address : " << &b << endl;
}	//11주차 실습예제 20

#include <iostream>
#include <string>
using namespace std;

void swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swap(double &a, double &b)
{
	double temp = a;
	a = b;
	b = temp;
}

void swap(char &a, char &b)
{
	char temp = a;
	a = b;
	b = temp;
}

void swap(string &a, string &b)
{
	string temp = a;
	a = b;
	b = temp;
}

int main()
{
	int n1 = 10, n2 = 20;
	double d1 = 1.1, d2 = 3.3;
	char c1 = 'a', c2 = 'e';
	string s1 = "Hello", s2 = "Bye";

	cout << "Before" << endl;
	cout << "n1 : " << n1 << ", n2 : " << n2 << endl;
	cout << "d1 : " << d1 << ", d2 : " << d2 << endl;
	cout << "c1 : " << c1 << ", c2 : " << c2 << endl;
	cout << "s1 : " << s1 << ", s2 : " << s2 << endl;

	cout << "\n--------------------" << endl;
	cout << "swap" << endl;
	swap(n1, n2);
	swap(d1, d2);
	swap(c1, c2);
	swap(s1, s2);

	cout << "\n--------------------" << endl;
	cout << "After" << endl;
	cout << "n1 : " << n1 << ", n2 : " << n2 << endl;
	cout << "d1 : " << d1 << ", d2 : " << d2 << endl;
	cout << "c1 : " << c1 << ", c2 : " << c2 << endl;
	cout << "s1 : " << s1 << ", s2 : " << s2 << endl;
	return 0;
}	//11주차 실습예제 21

#include <iostream>
#include <string>
using namespace std;

template<typename T>
void swap(T &a,T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	int n1 = 10, n2 = 20;
	double d1 = 1.1, d2 = 3.3;
	char c1 = 'a', c2 = 'e';
	string s1 = "Hello", s2 = "Bye";

	cout << "Before" << endl;
	cout << "n1 : " << n1 << ", n2 : " << n2 << endl;
	cout << "d1 : " << d1 << ", d2 : " << d2 << endl;
	cout << "c1 : " << c1 << ", c2 : " << c2 << endl;
	cout << "s1 : " << s1 << ", s2 : " << s2 << endl;

	cout << "\n--------------------" << endl;
	cout << "swap" << endl;
	
	//swap(n1, n2);	//string 빼고 안됨
	//swap(d1, d2);
	//swap(c1, c2);
	swap(s1, s2);

	cout << "\n--------------------" << endl;
	cout << "After" << endl;
	cout << "n1 : " << n1 << ", n2 : " << n2 << endl;
	cout << "d1 : " << d1 << ", d2 : " << d2 << endl;
	cout << "c1 : " << c1 << ", c2 : " << c2 << endl;
	cout << "s1 : " << s1 << ", s2 : " << s2 << endl;
	return 0;
}	//11주차 실습예제 22

#include <iostream>
#include <string>
using namespace std;

int sum(int a,int b)
{
	return a + b;
}
double sum(int a, double b)
{
	return a + b;
}
double sum(double a, int b)
{
	return a + b;
}
double sum(double a, double b)
{
	return a + b;
}

int main()
{
	cout << "int sum(1, 2)" << endl;
	cout << sum(1, 2) << endl;
	cout << "double sum(1, 2.2)" << endl;
	cout << sum(1, 2.2) << endl;
	cout << "double sum(2.2, 2)" << endl;
	cout << sum(2.2, 2) << endl;
	cout << "double sum(2.2, 4.4)" << endl;
	cout << sum(2.2, 4.4) << endl;
	return 0;
}	//11주차 실습예제 23

#include <iostream>
#include <string>
using namespace std;

template<typename A,typename B>
auto sum(A a, B b)
{
	return a + b;
}

int main()
{
	cout << "int sum(1, 2)" << endl;
	cout << sum(1, 2) << endl;
	cout << "double sum(1, 2.2)" << endl;
	cout << sum(1, 2.2) << endl;
	cout << "double sum(2.2, 2)" << endl;
	cout << sum(2.2, 2) << endl;
	cout << "double sum(2.2, 4.4)" << endl;
	cout << sum(2.2, 4.4) << endl;
	return 0;
}	//11주차 실습예제 24

#include <iostream>
#include <string>
using namespace std;

template<typename A, typename B>
auto sum(A a, B b)
{
	return a + b;
}

template<> auto sum<int>(int a, int b) { return a + b ; }

int main()
{
	cout << "int sum(1, 2)" << endl;
	cout << sum(1, 2) << endl;
	cout << "double sum(1, 2.2)" << endl;
	cout << sum(1, 2.2) << endl;
	cout << "double sum(2.2, 2)" << endl;
	cout << sum(2.2, 2) << endl;
	cout << "double sum(2.2, 4.4)" << endl;
	cout << sum(2.2, 4.4) << endl;
	return 0;
}	//11주차 실습예제 25

#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Data
{
private:
	T data;
public:
	Data(T dt) : data(dt) {}
	T get_data() { return this->data; }
};

int main()
{
	Data<string>str_data("C++ 수업");
	Data<int>int_data(12);

	cout << "str_data : " << str_data.get_data() << endl;
	cout << "int_data : " << int_data.get_data() << endl;
	return 0;
}	//11주차 실습예제 26

#include <iostream>
using namespace std;

template<typename T>
T const& find_max(T const& a, T const& b)
{
	if (a > b) { return a; }
	else { return b; }
}

template<typename T>
T const& find_max(T const& a, T const& b, T const& c) { return find_max(find_max(a, b), c); }

int main()
{
	cout << "find_max(10, 20) : " << find_max(10, 20) << endl;
	cout << "find_max(10, 20, 30) : " << find_max(10, 20, 30) << endl;
	cout << "find_max(1.5, 3.4) : " << find_max(1.5, 3.4) << endl;
}	//11주차 실습예제 27

#include <iostream>
#include <memory>
using namespace std;

template<typename T>
class SmartPtr
{
private:
	T* sptr = nullptr;
public:
	SmartPtr(T* sptr) : sptr(sptr) { cout << "sptr type : " << typeid(sptr).name() << endl; }
	~SmartPtr()
	{
		cout << "bye " << typeid(sptr).name() << endl;
		delete sptr;
	}
};

int main()
{
	//SmartPtr<T> a_ptr(new T);
	SmartPtr<int> i_ptr(new int);
	return 0;
}	//11주차 실습예제 28

#include <iostream>
#include <memory>
using namespace std;

template<typename T>
int main()
{
	unique_ptr<int> objPtrA = make_unique<int>(3);
	unique_ptr<int> objPtrB(new int(5));

	cout << objPtrA << ", " << *objPtrA << endl;
	cout << objPtrB << ", " << *objPtrB << endl;

	auto objPtrC = move(objPtrA);
	objPtrB.reset();
	cout << objPtrA << endl;
	cout << objPtrC << ", " << *objPtrC << endl;
	return 0;
}	//11주차 실습예제 29

#include <iostream>
#include <memory>
using namespace std;

template<typename T>
int main()
{
	unique_ptr<int> objPtrA = make_unique<int>(3);
	unique_ptr<int> objPtrB(new int(5));

	cout << objPtrA << ", " << *objPtrA << endl;
	cout << objPtrB << ", " << *objPtrB << endl;

	auto objPtrC = move(objPtrA);
	objPtrB.reset();
	cout << objPtrA << endl;
	cout << objPtrC << ", " << *objPtrC << endl;
	return 0;
}	//11주차 실습예제 30

#include <iostream>
#include <memory>
using namespace std;

template<typename T>
int main()
{
	shared_ptr<int> objPtrA = make_shared<int>(3);
	shared_ptr<int> objPtrB(new int(5));

	cout << objPtrA << ", " << *objPtrA << ", " << objPtrA.use_count() << endl;
	cout << objPtrB << ", " << *objPtrB << ", " << objPtrB.use_count() << endl;
	auto objPtrC = objPtrA;

	cout << objPtrA << ", " << *objPtrA << ", " << objPtrA.use_count() << endl;
	cout << objPtrC << ", " << *objPtrC << ", " << objPtrC.use_count() << endl;

	shared_ptr<int> objPtrD(nullptr);
	objPtrD = move(objPtrB);
	cout << objPtrB << endl;
	cout << objPtrD << ", " << *objPtrD << ", " << objPtrD.use_count() << endl;
	return 0;
}	//11주차 실습예제 31