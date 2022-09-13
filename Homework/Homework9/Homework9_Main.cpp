#include "Homework9_Elementary.h"
#include "Homework9_Middle.h"
#include <iostream>
using namespace std;

int main()
{
	Person *pe =(Person*) new Elementary("짱구", 8, "새싹", 1.f, "새싹반");	//upcast
	Person *pm =(Person*) new Middle("훈이", 14, "연두", 1.f, "연두학과");	//upcast
		
	Elementary *pStud = (Elementary*)pe;	//downcast
	Middle *pStud2 = (Middle*)pm;			//downcast
	cout << "-끝-" << endl;

	delete pStud2;	//Person class를 상속받는 Middle class를 downcast했기 때문에 pm을 메모리 해제해줄 필요가 없음
	delete pStud;	//Person class를 상속받는 Elementary class를 downcast했기 때문에 pe를 메모리 해제해줄 필요가 없음
	return 0;
}