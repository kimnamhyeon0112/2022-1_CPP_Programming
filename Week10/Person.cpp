#pragma once
#include "Person.h"

void Person::move()
{
	cout << this->name << "is going home" << endl;
}

void Person::talk()
{
	cout << "I am " << this->age << "years old" << endl;
}

void Student::move()
{
	cout << this->name << "is going " << this->academic << "University" << endl;
}

void Student::study()
{
	cout << "I am studying CPP" << endl;
}	//6주차 실습예제 6,9, 10주차 실습예제 6
