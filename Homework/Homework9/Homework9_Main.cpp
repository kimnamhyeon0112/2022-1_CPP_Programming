#include "Homework9_Elementary.h"
#include "Homework9_Middle.h"
#include <iostream>
using namespace std;

int main()
{
	Person *pe =(Person*) new Elementary("¯��", 8, "����", 1.f, "���Ϲ�");	//upcast
	Person *pm =(Person*) new Middle("����", 14, "����", 1.f, "�����а�");	//upcast
		
	Elementary *pStud = (Elementary*)pe;	//downcast
	Middle *pStud2 = (Middle*)pm;			//downcast
	cout << "-��-" << endl;

	delete pStud2;	//Person class�� ��ӹ޴� Middle class�� downcast�߱� ������ pm�� �޸� �������� �ʿ䰡 ����
	delete pStud;	//Person class�� ��ӹ޴� Elementary class�� downcast�߱� ������ pe�� �޸� �������� �ʿ䰡 ����
	return 0;
}