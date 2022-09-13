#include "Homework05.h"
void Circle::input(int x_point, int y_point, int radius)		//멤버 변수에 값을 넣는 함수
{
	this->x = x_point;
	this->y = y_point;
	this->r = radius;
	this->area = pow(radius, 2) * PI;		//조건: 원의 넓이를 저장
}

void Circle::show()		//멤버 변수의 값을 보여주는 함수. 조건: 원의 넓이는 멤버 함수 이용
{
	cout << "(" << this->x << ", " << this->y << "), " << this->r << " 넓이: " << Area() << endl;
}

double Circle::Area()		//멤버 변수 r값을 통해 원의 넓이 반환
{
	return pow(this->r, 2) * PI;
}

bool Circle::check_distance(Circle* pick, Circle *cmpptr)		//두 좌표값 중 어느 값이 더 원점에서 멀은가 확인
{
	if (sqrt(pow(pick->x, 2) + pow(pick->y, 2)) > sqrt(pow(cmpptr->x, 2) + pow(cmpptr->y, 2)))
		return true;
	else
		return false;
}

int Circle::check_arr(Circle* arr, int start, int end)		//배열을 r값 오름차순, 좌표가 원점에서 가까운 순으로 오름차순 정렬
{
	if (start > end)
		return 0;
	Circle *startptr = arr + start;		//정렬 할 범위의 시작점 설정
	Circle* pick = startptr;		//해당 배열 범위에서 가장 작은 값을 가진 원소 가리키는 포인터

	for (int i = 0; i + start < end; i++)		//가장 작은 원소를 찾는 for문
	{
		if (pick->r > (startptr + i)->r)pick = (startptr + i);
		else if (pick->r == (startptr + i)->r)
		{
			if (check_distance(pick, (startptr + i)))pick = (startptr + i);
			continue;
		}
	}

	Circle* tmp = new Circle;			//가장 작은 값과 정렬할 범위의 시작점 swap
	tmp->input(startptr->x, startptr->y, startptr->r);
	startptr->input(pick->x, pick->y, pick->r);
	pick->input(tmp->x, tmp->y, tmp->r);

	delete tmp;
	tmp = nullptr;
}