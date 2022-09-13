#include <iostream>
#include <array>	//배열헤더
using namespace std;

int main()
{
	array<int, 3> tempArray;	//array 선언법
	array<int, 5> tempArray2 = { 9,2,4,1,7 };
	array<int, 5> tempArray3 = { 9,2,4,1,7 };
	array<int, 5> tempArray4;
	tempArray4 = { 0,1,2,3,4 };
	tempArray4 = { 9,8,7 };

	cout << tempArray4[1] << endl;
	tempArray4[2] = 6;
	tempArray4.at(3) = 2;	//
	tempArray.at(7) = 10;
	return 0;
}	//1번예제

#include <iostream>
#include <array>
using namespace std;

void printLength(const array<double, 5>&myarray)
{
	cout << "size of : " << sizeof(myarray) << endl;
	cout << "length : " << myarray.size() << endl;
}

int main()
{
	array<double, 5>myarray{ 9.0,7.2,5.4,3.6,1.8 };
	cout << "length : " << myarray.size() << endl;
	printLength(myarray);

	for (auto &element : myarray)
		cout << element<< ' ';
	return 0;
}	//2번예제

#include <iostream>
#include <vector>	//array의 size 자동 지정
using namespace std;

int main()
{
	vector<int> array1;
	vector<int> array2 = {9,7,5,3,1};
	vector<int> array3 = {9,7,5,3,1};

	array2 = { 0,1,2,3,4 };
	array3 = { 9,8,7 };

	vector<int> array4 = { 0,1,2,3,4 };
	array4.resize(3);	//array4의 길이를 5에서 3으로 변경, 단 뒤의 값 사라짐
	cout << "The length is : " << array4.size() << endl;
	for (auto const &element : array4)
		cout << element << ' ';
	return 0;
}	//3번예제

#include "test.h"
using namespace std;

int main()
{
	int num = 10;
	num_print(num);
	return 0;
}	//4번예제

#include "Student.h"
using namespace std;

int main()
{
	Student s;
	for (int i = 0; i < 5; i++)
		cout << "count " << i << endl;
	s.speaking();
	return 0;
}	//6번예제

#include "Student.h"
using namespace std;

int main()
{
	Student s("Park", 98765432, 1.1);
	s.speaking();
	s.print_information();
	s.input_information();
	s.print_information();

	return 0;
}	//7번예제

#include "Student.h"
using namespace std;

int main()
{
	Student s("Park", 98765432, 1.1);
	cout << s.park_name() << endl;
	cout << s.park_phone() << endl;
	cout << s.park_score() << endl;
	return 0;
}	//8번예제