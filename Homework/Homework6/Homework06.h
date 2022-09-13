#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person		//부모클래스
{
private:
	string name;	//나의 이름을 string으로 선언
protected:
	int age, id;	//나이와 학번(초, 중, 고는 학년반번호)를 정수로 선언 
	string school, major, score;	//학교, 전공(초, 중, 고는 n학년n반), 학점(중, 고는 내신, 초등학교는 기억이 안나서 100점만점을 지정)
public:
	Person(string _name, int _age, int _id, string _school, string _major, string _score)	//class의 각 항목을 읽어옴 
	{
		this->name = _name;
		this->age = _age;
		this->id = _id;
		this->school = _school;
		this->major = _major;
		this->score = _score;
	}
	void show_info()		//출력
	{
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
		cout << "학번 : " << id << endl;
		cout << "학교 : " << school << endl;
		cout << "학과(or학년반) : " << major << endl;
		cout << "학점 : " << score << endl;
	}
	~Person() {}
	void move();	
	void talk();
	void transportation();
	void goal();
};

class Elementary : public Person		//초등학교 info
{
private:
public:
	Elementary(string _name, int _age, int _id, string _school, string _major, string _score) :Person(_name, _age, _id, _school, _major, _score)
	{

	}
	~Elementary() {}
	void show()
	{
		cout << "초등 정보" << endl;
		show_info();
	}
	void move();
	void talk();
	void transportation();
	void goal();		//추가함수
};

class Middle : public Person		//중학교 info
{
private:
public:
	Middle(string _name, int _age, int _id, string _school, string _major, string _score) :Person(_name, _age, _id, _school, _major, _score)
	{

	}
	~Middle() {}
	void show()
	{
		cout << "중학 정보" << endl;
		show_info();
	}
	void move();
	void talk();
	void transportation();
	void goal();		//추가함수
};

class High : public Person		//고등학교 info
{
private:
public:
	High(string _name, int _age, int _id, string _school, string _major, string _score) :Person(_name, _age, _id, _school, _major, _score)
	{

	}
	~High() {}
	void show()
	{
		cout << "고등 정보" << endl;
		show_info();
	}
	void move();
	void talk();
	void transportation();
	void goal();		//추가함수
};

class University : public Person		//대학교 info
{
private:
	string bestfriend;		//예시에 나와있던 Bestfriend 항목 추가
public:
	University(string _name, int _age, int _id, string _school, string _major, string _score, string _bestfriend) :Person(_name, _age, _id, _school, _major, _score)
	{
		this->bestfriend = _bestfriend;
	}
	void show()
	{
		cout << "대학 정보" << endl;
		show_info();
		cout << "베프 : " << this->bestfriend << endl;
	}
	~University() {}
	void move();
	void transportation();
	void talk();
	void goal();		//추가함수
};