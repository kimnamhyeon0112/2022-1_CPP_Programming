#include "Homework05.h"

int main()
{
	int circle_max = 0;
	int x, y, r;

	while (true)
	{
		Circle* pArray = nullptr;		//배열을 가리킬 포인터

		cout << "원의 수: (음수 입력시 종료)" << endl;
		cin >> circle_max;
		if (circle_max < 0)break;
		if (circle_max < 5)
		{
			cout << "최소 5개 이상의 원을 입력하세요." << endl;
			continue;
		}

		pArray = new Circle[circle_max];	//입력 받은 원의 개수 만큼 배열 할당

		cout << "중심 좌표, 반지름: " << endl;

		for (int i = 0; i < circle_max; i++)	//각 배열에 x, y, r값 입력 받아서 넣기
		{
			cin >> x >> y >> r;
			pArray[i].input(x, y, r);
		}
		for (int i = 0; i < circle_max; i++)	//배열의 원소를 조건에 맞게 정렬, i값은 정렬할 배열 범위를 지정
		{
			(*pArray).check_arr(pArray, i, circle_max);
		}

		cout << "\n\n결과값\n\n";

		for (int i = 0; i < circle_max; i++)	//배열 순서대로 출력
		{
			pArray[i].show();
		}
		delete[] pArray;
	}
	return 0;
}