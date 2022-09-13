#pragma once
#include "Homework9_Person.h"
#include <string>

using namespace std;

class Elementary : Person
{
private:
	float m_record;
	string m_bestFriend;
	string m_department;
public:
	Elementary(const string &name, int age, const string& local, float record, const string& department);
	~Elementary();
};