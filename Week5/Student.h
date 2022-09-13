#pragma once
#include <iostream>
using namespace std;

class Student
{
public:
	Student()
	{
		cout << "Hello Student!" << endl;
	}
	~Student()
	{
		cout << "By student!" << endl;
	}
};

int main()
{
	Student s;
	for (int i = 0; i < 5; i++)
		cout << "count " << i << endl;
	return 0;
}	//5주차 실습예제5

#include <iostream>
using namespace std;

class Student
{
public:
	Student()
	{
		cout << "Hello Student!" << endl;
	}
	void speaking();
	~Student()
	{
		cout << "By Student!" << endl;
	}
}; //5주차 실습예제6

#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string name = "";
	int phone_number = 0;
	double score = 0;
public:
	Student(string _name, int _phone_number, double _score)
	{
		this->name = _name;
		this->phone_number = _phone_number;
		this->score = _score;
		cout << "Hello Student!" << endl;
	}

	void speaking();
	void input_information();
	void print_information();
	~Student()
	{
		cout << "By Student" << endl;
	}
}; //5주차 실습예제7

#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string name;
	int phone_number;
	double score;
public:
	Student(string _name, int _phone_number, double _score) :
		name(_name), phone_number(_phone_number), score(_score) 
	{
		cout << "Hello student! " << endl;
	}
	string park_name();
	int park_phone();
	double park_score();
	
	~Student()
	{
		cout << "By Student!" << endl;
	}
}; //5주차 실습예제8