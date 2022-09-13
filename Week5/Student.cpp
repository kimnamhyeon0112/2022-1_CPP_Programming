#include "Student.h"
void Student::speaking()
{
	std::cout << "Hello Now Student!!" << std::endl;
}	//5주차 실습예제6

#include "Student.h"

void Student::speaking()
{
	std::cout << "Hello Now Student!" << std::endl;
}

void Student::input_information()
{
	this->name = "Kim";
	this->phone_number = 12345678;
	this->score = 2.5;
}

void Student::print_information()
{
	std::cout << this->name << std::endl;
	std::cout << this->phone_number<< std::endl;
	std::cout << this->score << std::endl;
}	//5주차 실습예제7

#include "Student.h"
using namespace std;

string Student::park_name()
{
	return this->name;
}
int Student::park_phone()
{
	return this->phone_number;
}
double Student::park_score()
{
	return this->score;
}	//5주차 실습예제8