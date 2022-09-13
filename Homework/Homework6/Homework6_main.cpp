#include "Homework06.h"
using namespace std;

int main()
{
	string select;		//menu를 입력할 string
	Elementary Ele("김남현", 13, 60603, "소하초등학교", "6학년6반", "100");						//초등학교 class에 들어갈 값
	Middle Mid("김남현", 16, 31305, "소하중학교", "3학년13반", "165");							//중학교 class에 들어갈 값
	High Hi("김남현", 19, 30605, "소하고등학교", "3학년 6반", "2.0");							//고등학교 class에 들어갈 값
	University Uni("김남현", 23, 2019037004, "충북대학교", "컴퓨터공학과", "A+", "홍길동");		//대학교 class에 들어갈 값
	while (true)
	{
		cout << "----Menu----" << endl << "1.초등" << endl << "2.중학" << endl << "3.고등" << endl << "4.대학" << endl << "5.종료" << endl;
		cout << "선택 : ";
		cin >> select;
		cout << endl;
		if (select == "1" || select == "초등")		//menu를 string으로 지정했기 떄문에 1이나 초등입력 가능
		{
			Ele.show();
			Ele.Person::move();					//move함수 오버라이딩
			Ele.move();							//Elementary 클래스의 move함수
			Ele.Person::transportation();
			Ele.transportation();
			Ele.Person::talk();
			Ele.talk();
			Ele.Person::goal();
			Ele.goal();
		}
		else if (select == "2" || select == "중학")
		{
			Mid.show();
			Mid.Person::move();
			Mid.move();
			Mid.Person::transportation();
			Mid.transportation();
			Mid.Person::talk();
			Mid.talk();
			Mid.Person::goal();
			Mid.goal();
		}
		else if (select == "3" || select == "고등")
		{
			Hi.show();
			Hi.Person::move();
			Hi.move();
			Hi.Person::transportation();
			Hi.transportation();
			Hi.Person::talk();
			Hi.talk();
			Hi.Person::goal();
			Hi.goal();
		}
		else if (select == "4" || select == "대학")
		{
			Uni.show();
			Uni.Person::move();
			Uni.move();
			Uni.Person::transportation();
			Uni.transportation();
			Uni.Person::talk();
			Uni.talk();
			Uni.Person::goal();
			Uni.goal();
		}
		else if (select == "5" || select == "종료")
		{
			cout << endl << "-끝-" << endl;
			exit(1);
		}
		else
			cout << select << "은(는) 올바른 입력값이 아닙니다. 1~5까지 숫자를 입력하세요." << endl << endl;		//1~5가 아닌 숫자 입력시 재입력 message
	}
	return 0;
}