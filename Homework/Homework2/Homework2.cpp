#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int x1, x2, y1, y2;	//두 점의 좌표 (x1,y1), (x2,y2) 정수형 변수 선언
	float d;	//공식 d 실수형 변수 선언
	cout << "두점의 좌표를 입력하시오 (x1, y1, x2, y2 순서로 입력)" << endl;	//두 점의 좌표 입력
	cin >> x1 >> y1 >> x2 >> y2;	//각 점의 좌표입력
	d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));	//정수형 변수 d를 root((x1 - x2) ^ 2 + (y1 - y2) ^ 2)로 초기화
	cout << "두점 사이의 거리는 " << d << "입니다" << endl;	//결과값 출력
	return 0;	//종료함수
} //c++과제 1번

#include <iostream>
#include <cmath>
using namespace std;
void calc(int, int, int, int, int, int);	//calc함수의 프로토타입

int main()
{
	int x1, x2, x3, y1, y2, y3;			//세 점의 좌표 (x1,y1),(x2,y2),(x3,y3)를 정수형 변수로 선언
to:	cout << "세 점의 좌표를 입력하시오(x1, y1, x2, y2, x3, y3 순서로 입력)" << endl<<": ";	//안내문구 삽입, goto문의 목적지
	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)		//세 점의 좌표들 중 하나라도 EOF(^Z)가 입력될때 까지 반복
	{
		calc(x1, x2, x3, y1, y2, y3);	//calc함수 호출
		goto to;	//while문의 조건식이 좌표들의 값을 입력받는 cin이므로 안내멘트를 삽입하기 위해 goto문 사용
	}
	return 0;	//종료함수
}

void calc(int x1, int x2, int x3, int y1, int y2, int y3)	//calc 함수, 함수형이 void이므로 return을 하지않는다
{
	float S, s, a, b, c;									//세변의 길이와 수식들을 실수형 변수로 선언
	if ((x1 == x2 == x3 || y1 == y2 == y3) || (x1 == x2 == x3 == y1 == y2 == y3))	//세 점이 일직선에 있는경우 or 모든 점이 동일한 점인 경우 삼각형이 아님
		cout << "삼각형이 아닙니다" << endl;				//삼각형이 아니라는 안내멘트 출력
	else													//세 점이 일직선에 있는경우가 아니거나 모든 점이 동일한 점이 아닌 경우
	{
		a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));			//a를 수식으로 초기화
		b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));			//b를 수식으로 초기화
		c = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));			//c를 수식으로 초기화
		if (a + b <= c)											//만약 가장 긴 변이 나머지 두변의 길이의 합보다 길거나 같은경우 삼각형이 아님
			cout << "삼각형이 아닙니다" << endl;				//삼각형이 아니라는 안내멘트 출력
		else													//가장 긴 변이 나머지 두변의 길이의 합보다 길지 않을때
		{
			s = (a + b + c) / 2;								//s를 수식으로 초기화
			S = sqrt(s * (s - a) * (s - b) * (s - c));			//S를 수식으로 초기화
			if (S == 0)											//넓이가 0인 경우 삼각형이 아님
				cout << "삼각형이 아닙니다" << endl;			//삼각형이 아니라는 안내멘트 출력
			else												//넓이가 0이 아닌경우 삼각형임
				cout << "삼각형이 맞습니다. 넓이:" << S << endl;//넓이 출력
		}
	}
}	//c++과제 2번