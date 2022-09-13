#include <iostream>
#define PI 3.14
using namespace std;

typedef struct Circle
{
	int x;	//x좌표
	int y;	//y좌표
	int r;	//반지름
}Circle;

int main()
{
	int num_of_circle, temp, temp2, temp3, temp4;	//int형 변수 num_of_circle, temp, temp2, temp3, temp4 선언
	cout << "원의 수 : ";
	cin >> num_of_circle;
	float *area = new float[num_of_circle];		//원의 넓이를 배열에 저장하기 위해 동적할당으로 크기지정
	Circle *ptr = new Circle[num_of_circle];	//입력 받은 만큼 x,y,r를 각각 배열로 저장해야하므로 동적할당
	if (num_of_circle < 5)
	{
		cout << "원의 갯수는 5개이상 입력해야 합니다." << endl;
		exit(1);
	}											//5개미만입력시 종료조건
	cout << "중심좌표, 반지름 : " << endl;
	for (int i = 0; i < num_of_circle; i++)
		cin >> ptr[i].x >> ptr[i].y >> ptr[i].r;

	cout << endl << endl;

	for (int i = 0; i < num_of_circle; i++)
		area[i] = PI * ptr[i].r * ptr[i].r;		//원의 넓이 공식 area= pi*r^2

	for (int i = 1; i <= num_of_circle; i++)
	{
		for (int j = 0; j <= num_of_circle - 1; j++)	//bubblesort 사용
		{
			if (area[j] < area[j - 1])		//area 값 비교후
			{
				temp = area[j];
				area[j] = area[j - 1];
				area[j - 1] = temp;			//area temp

				temp2 = ptr[j].x;
				ptr[j].x = ptr[j - 1].x;
				ptr[j - 1].x = temp2;		//x좌표 temp

				temp3 = ptr[j].y;
				ptr[j].y = ptr[j - 1].y;
				ptr[j - 1].y = temp3;		//y좌표 temp

				temp4 = ptr[j].r;
				ptr[j].r = ptr[j - 1].r;
				ptr[j - 1].r = temp4;		//반지름 temp
			}
			else if (area[j] == area[j - 1])	//면적이 같은경우
			{
				if (ptr[j].x < ptr[j - 1].x || ptr[j].y < ptr[j - 1].y)	//x좌표와 y좌표 비교
				{
					temp = area[j];
					area[j] = area[j - 1];
					area[j - 1] = temp;		//area temp

					temp2 = ptr[j].x;
					ptr[j].x = ptr[j - 1].x;
					ptr[j - 1].x = temp2;	//x좌표 temp

					temp3 = ptr[j].y;
					ptr[j].y = ptr[j - 1].y;
					ptr[j - 1].y = temp3;	//y좌표 temp

					temp4 = ptr[j].r;
					ptr[j].r = ptr[j - 1].r;
					ptr[j - 1].r = temp4;	//반지름 temp
				}
			}
		}
	}
	for (int i = 0; i < num_of_circle; i++)
		cout << "(" << ptr[i].x << "," << ptr[i].y << "), " << ptr[i].r << endl;	//결과값 출력

	delete[] ptr;		//동적할당 메모리 ㅎ제
	delete[] area;		//동적할당 메모리 해제
	return 0;			//프로그램 종료
}	//4주차 실습과제