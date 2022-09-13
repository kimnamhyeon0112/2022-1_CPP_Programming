#include <iostream>
using namespace std;

class Person
{
private:
	std::string name;
protected:
	std::string local;
public:
	int age;
};
class Student : public Person
{
public:
	void print()
	{
		cout << local << endl;
		cout << age << endl;
	}
};

int main()
{
	Person p;
	p.age;
	Student s;
	s.age;
	return 0;
}	//9주차 실습예제 1

#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
	std::string name;
protected:
	std::string local;
public:
	int age;
};
class Student : private Person
{
public:
	void print()
	{
		cout << local << endl;
		cout << age << endl;
	}
};

int main()
{
	Person p;
	p.age;
	Student s;
	//s.age;	상속이 private이기 때문에 age는 접근 불가
	return 0;
}	//9주차 실습예제 2

#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
	string name;
protected:
	string local;
public:
	int age;
};
class Student : protected Person
{
public:
	void print()
	{
		cout << local << endl;
		cout << age << endl;
	}
};

int main()
{
	Person p;
	p.age;
	Student s;
	//s.age;	'Person::age'에 액세스할 수 없습니다. 이는 'Student'이(가) 'protected'을(를) 사용하여 'Person'에서 상속하기 때문입니다.
	return 0;
}	//9주차 실습예제 3

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person
{
private: 
	int rrn;
protected:
	int money;
public:
	std::string name;
	void setRrn(int _rrn);
	void setMoney(int _money);
	void setName(std::string _name);
	int getRrn();
	int getMoney();
	std::string getName();
};

class Student : protected Person
{
private:
	int pinm;
protected:
	int grades;
public:
	string grade;
	void pModify(int r, int m, string n);
	void setPinm(int p);
	int getPinm();
	void setGrades(int g);
	int getGrades();
	void Sprint();
	void Pprint();
};

class University : public Student
{
private:
	int password;
public:
	string ID;
	void sModify(int p, int gs, string g);
	void setPassword(int pw);
	int getPassword();
	void uPrint();
	void sPrint();
	void pPrint();
};

class Employee :protected Person
{
private:
protected:
	int salary;
public:
	string rank;
	void pModify(int r, int m, string n);
	void setSalary(int s);
	int getSalary();
	void ePrint();
	void pPrint();
};

class Manager :private Employee
{
private:
	int bonus;
public:
	void setBonus(int b);
	int getBonus();
	void pModify2(int r, int m, string n);
	void eModify(int s, string r);
	void mPrint();
	void ePrint();
	void pPrint();
};

void P()
{
	Person p;
	p.setRrn(990101);
	p.setMoney(1000);
	p.name = "Kim";

	cout << "Case: Person P" << endl;
	cout << p.getRrn() << endl;
	cout << p.getMoney() << endl;
	cout << p.name << endl;
}

void S()
{
	Student s;
	s.pModify(990202, 2000, "Park");
	s.setPinm(5000);
	s.setGrades(60);
	s.grade = "2nd";

	cout << "Case: Stident S" << endl;
	s.Pprint();
	cout << s.getPinm() << endl;
	cout << s.getGrades() << endl;
	cout << s.grade << endl;
}

void U()
{
	University u;
	u.pModify(990303, 3000, "Lee");
	u.setPinm(1000);
	u.setGrades(60);
	u.grade = "3rd";
	u.ID = "20200102001";
	u.setPassword(123456);

	cout << "Case: University U" << endl;
	u.pPrint();
	cout << u.getPinm() << endl;
	cout << u.getGrades() << endl;
	cout << u.grade << endl;
	cout << u.getPassword() << endl;
	cout << u.ID << endl;
}

void E()
{
	Employee e;
	e.pModify(990404, 6000, "Choi");
	e.setSalary(60000);
	e.rank = "employee";

	cout << "Case: Employee E" << endl;
	e.pPrint();
	cout << e.getSalary() << endl;
	cout << e.rank << endl;
}

void M()
{
	Manager m;
	m.pModify2(990505, 10000, "Nam");
	m.eModify(50000, "Manager");
	m.setBonus(5000);

	cout << "Case: Manager M" << endl;
	m.pPrint();
	m.ePrint();
	m.mPrint();
}	//9주차 실습예제 4

#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
	int rrn;
protected:
	int money;
public:
	Person(int r, int m, string n) :rrn(r), money(m), name(n) {}
	~Person() {}
	string name;
	friend class Friend;
};

class Friend
{
public:
	void showInfo(Person p)
	{
		cout << "rrn: " << p.rrn << endl;
		cout << "money: " << p.money << endl;
		cout << "name: " << p.name << endl;
	}
	void setInfo(Person &p, int m)
	{
		p.money += m;
	}
};

int main()
{
	Person p(991010, 50000, "Kim");
	Friend f;

	f.showInfo(p);
	cout << "\np money change" << endl;
	f.setInfo(p, 2000);
	f.showInfo(p);
}	//9주차 실습예제 5

#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
	int rrn;
protected:
public:
	Person(int r, int m, string n) :rrn(r), money(m), name(n) {}
	~Person() {}
	string name;
	int money;
	friend void showInfo(Person p);
	friend void showInfo(Person &p, int m);
};

void showInfo(Person p)
{
	cout << "rrn: " << p.rrn << endl;
	cout << "money: " << p.money << endl;
	cout << "name: " << p.name << endl;
}

void SetInfo(Person &p, int m)
{
	p.money += m;
}

int main()
{
	Person p(991111, 200000, "Park");

	showInfo(p);
	cout << "\np money change" << endl;
	SetInfo(p, 5000);
	showInfo(p);
}	//9주차 실습예제 6

#pragma once
#include <iostream>
using namespace std;

class A
{
public:
	A() { cout << "Hello A" << endl; }
	void show() { cout << "Show A" << endl; }
	~A() { cout << "Bye A" << endl; }
};

class B
{
public:
	B() { cout << "Hello B" << endl; }
	void show() { cout << "Show B" << endl; }
	~B() { cout << "Bye B" << endl; }
};

class C :public A, public B
{
public:
	C() { cout << "Hello C" << endl; }
	void show() { cout << "Show C" << endl; }
	~C() { cout << "Bye C" << endl; }
};

int main()
{
	C c;
	c.show();
	return 0;
}	//9주차 실습예제 7

#pragma once
#include <iostream>
using namespace std;

class A
{
public:
	A() { cout << "Hello A" << endl; }
	void show() { cout << "Show A" << endl; }
	~A() { cout << "Bye A" << endl; }
};

class B :public A
{
public:
	B() { cout << "Hello B" << endl; }
	void show() { cout << "Show B" << endl; }
	~B() { cout << "Bye B" << endl; }
};

class C :public A
{
public:
	C() { cout << "Hello C" << endl; }
	void show() { cout << "Show C" << endl; }
	~C() { cout << "Bye C" << endl; }
};

class D :public B, public C
{
public:
	D() { cout << "Hello D" << endl; }
	void show() { cout << "Show D" << endl; }
	~D() { cout << "Bye D" << endl; }
};

int main()
{
	D d;
	d.show();
	return 0;
}	//9주차 실습예제 8

#pragma once
#include <iostream>
using namespace std;

class A
{
public:
	A() { cout << "Hello A" << endl; }
	void show() { cout << "Show A" << endl; }
	~A() { cout << "Bye A" << endl; }
};

class B :public A
{
public:
	B() { cout << "Hello B" << endl; }
	void show() { cout << "Show B" << endl; }
	~B() { cout << "Bye B" << endl; }
};

class C :public A
{
public:
	C() { cout << "Hello C" << endl; }
	void show() { cout << "Show C" << endl; }
	~C() { cout << "Bye C" << endl; }
};

class D :public B, public C
{
public:
	D() { cout << "Hello D" << endl; }
	void show() { show(); }
	~D() { cout << "Bye D" << endl; }
};

int main()
{
	D d;
	d.show();
	return 0;
}	//9주차 실습예제 9

#pragma once
#include <iostream>
using namespace std;

class A
{
public:
	A() { cout << "Hello A" << endl; }
	void show() { cout << "Show A" << endl; }
	~A() { cout << "Bye A" << endl; }
};

class B :virtual public A
{
public:
	B() { cout << "Hello B" << endl; }
	void show() { cout << "Show B" << endl; }
	~B() { cout << "Bye B" << endl; }
};

class C :virtual public A
{
public:
	C() { cout << "Hello C" << endl; }
	void show() { cout << "Show C" << endl; }
	~C() { cout << "Bye C" << endl; }
};

class D :public B, public C
{
public:
	D() { cout << "Hello D" << endl; }
	void show() { cout << "Show D" << endl; }
	~D() { cout << "Bye D" << endl; }
};

int main()
{
	D d;
	d.show();
	return 0;
}	//9주차 실습예제 10