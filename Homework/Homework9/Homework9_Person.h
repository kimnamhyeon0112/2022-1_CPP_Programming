#pragma once
#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
	int m_ssNumber;
protected:
	string m_name;
	int m_age;
	string m_local;

public:
	Person();
	~Person();
	void createSsNumber();
	int getSsNumber() const { return m_ssNumber; }
};