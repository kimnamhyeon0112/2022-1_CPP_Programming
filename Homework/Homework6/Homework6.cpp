#include "Homework06.h"
using namespace std;

void Person::move()
{
	cout << "사는곳 : ";
}
void Person::talk()
{
	cout << "하고싶은말 : ";
}
void Person::transportation()
{
	cout << "교통수단 : ";
}
void Person::goal()
{
	cout << "목표 : ";
}

void Elementary::move()
{
	cout << "경기도 광명시 소하동" << endl;
}
void Elementary::talk()
{
	cout << "초등학교 6학년" << endl;
}
void Elementary::transportation()
{
	cout << "도보" << endl;
}
void Elementary::goal()
{
	cout << "반장하기" << endl << endl;
}

void Middle::move()
{
	cout << "경기도 광명시 소하동" << endl;
}
void Middle::talk()
{
	cout << "중학교 3학년" << endl;
}
void Middle::transportation()
{
	cout << "도보 or 자전거" << endl;
}
void Middle::goal()
{
	cout << "운동해서 살빼기" << endl << endl;
}

void High::move()
{
	cout << "경기도 광명시 일직동" << endl;
}
void High::talk()
{
	cout << "고등학교 3학년" << endl;
}
void High::transportation()
{
	cout << "버스 + 도보" << endl;
}
void High::goal()
{
	cout << "좋은 대학 가기" << endl << endl;
}

void University::move()
{
	cout << "충청북도 청주시 개신동" << endl;
}
void University::talk()
{
	cout << "대학교 2학년" << endl;
}
void University::transportation()
{
	cout << "ktx + 버스" << endl;
}
void University::goal()
{
	cout << "과탑하기" << endl << endl;
}