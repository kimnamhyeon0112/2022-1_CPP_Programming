#pragma once
#include "Homework9_Person.h"
#include <string>

using namespace std;

class Middle : Person
{
private:
	float m_record;
	string m_bestFriend;
	string m_department;
public:
	Middle(const string &name, int age, const string& local, float record, const string& department);
	~Middle();
};