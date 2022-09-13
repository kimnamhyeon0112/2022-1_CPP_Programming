#include "Homework9_Person.h"
#include <random>

using namespace std;

Person::Person() : m_ssNumber(0), m_name(""), m_age(0), m_local("")
{
	cout << "Hello Person First" << endl;
}
Person::~Person()
{
	cout << "Bye Person" << endl;
}

void Person::createSsNumber()
{
	if (m_ssNumber > 0)
		return;
	random_device rd;		//난수 생성
	mt19937 gen(rd());
	uniform_int_distribution<int>dis(2020024054, 2020024054);	//정수형 dis라는 닫힌구간 범위안에서 균등한 정수 분포 생성(2020024054에서 난수 생성)

	m_ssNumber = dis(gen);
}