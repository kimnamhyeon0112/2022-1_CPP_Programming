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
	void talk();
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
}; //6주차 실습예제 6,9, 10주차 실습예제 6