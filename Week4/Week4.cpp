#include <iostream>
using namespace std;

void not_array()
{
	int score1 = 50;
	int score2 = 30;
	int score3 = 90;
	int socre4 = 0;
}

void Array()
{
	int score[30] = { 50,30,90,0,40,27,28 };
}	//1번예제

#include <iostream>
using namespace std;

void Array_Data_types()
{
	int arrayInt[3];
	for (int i = 0; i < sizeof(arrayInt); i++)
		arrayInt[i] = i + 20;
	cout << "arrayInt : " << arrayInt[0] << ", " << arrayInt[1] << ", " << arrayInt[2] << endl;

	double arrayDou[3];
	arrayDou[0] = 2.0;
	arrayDou[1] = 3.0;
	arrayDou[2] = 4.3;
	cout << "arrayDou : ";
	for (double d : arrayDou)
		cout << d << ", ";
	cout << endl;

	char arrayChar[3] = { 'a','b','c' };
	cout << "arrayChar : ";
	for (int i = 0; i < sizeof(arrayChar); i++)
		cout << arrayChar[i] << ", ";
}

int main()
{
	Array_Data_types();
	return 0;
}	//2번예제

#include <iostream>
using namespace std;

int global_num;
static int static_global_num;

int static_local_func()
{
	static int static_local_num = 10;
	global_num = 30;
	return static_local_num;
}

int main()
{
	int local_num;
	global_num = 5;
	static_global_num = 10;
	local_num = 15;

	cout << "Global Num : " << global_num << endl;
	cout << "Local Num : " << local_num<< endl;
	cout << "Static Global Num : " << static_global_num << endl;
	cout << "------------------------------" << endl;

	int static_local_num = static_local_func();
	cout << "Global Num : " << global_num << endl;
	cout << "Local Num : " << local_num << endl;
	cout << "Static Global Num : " << static_global_num << endl;
	cout << "Static Local Num : " << static_local_num << endl;
}	//3번예제

#include <iostream>
using namespace std;

int result = 0;
int sum(int x)
{
	result += x;
	return result;
}
int main()
{
	for (int i = 0; i < 10; i++)
	{
		sum(i);
		cout << "sum : " << result << endl;
	}
	return 0;
}	//4번예제

#include <iostream>
using namespace std;

int sum(int x)
{
	static int result = 0;
	result += x;
	return result;
}

int main()
{
	for (int i = 0; i < 10; i++)
		cout << "Sum : " << sum(i) << endl;
	return 0;
}	//5번예제

#include <iostream>
#define PI 3.14
const int MAX = 100;
using namespace std;

int main()
{
	cout << PI << endl;
	cout << MAX << endl;
}	//6번예제

#include <iostream>
#define PI 3.14
#define STR "Hello STR~"
#define DOUBLE(x) x*x
using namespace std;

int main()
{
	cout << "PI : " << PI << ", type : " << typeid(PI).name() << endl;
	cout << "STR : " << STR << ", type : " << typeid(STR).name() << endl;
	cout << "DOUBLE 2 : " << DOUBLE(2) << endl;
}	//7번예제

#include <iostream>
using namespace std;

int main()
{
	int value = 3, value2 = 7;
	const int*ptr = &value;
	value = 5;
	cout << "value : " << value << ", *ptr : " << *ptr << ", ptr : " << ptr << endl;
	value = 7;
	cout << "value : " << value << ", *ptr : " << *ptr << ", ptr : " << ptr << endl;
}	//8번예제

#include <iostream>
using namespace std;

int main()
{
	int value = 3, value2 = 9;
	int *const ptr = &value;	//주소를 바꿀 수 없느 포인터
	*ptr = 5;
	cout << "value : " << value << ", *ptr : " << *ptr << ", ptr : " << ptr << endl;
	*ptr = 7;
	cout << "value : " << value << ", *ptr : " << *ptr << ", ptr : " << ptr << endl;
	return 0;
}	//9번예제

#include <iostream>
using namespace std;

int main()
{
	int value = 3, value2 = 9;
	const int *const ptr = &value;
	value = 5;
	cout << "value : " << value << ", *ptr : " << *ptr << ", ptr : " << ptr << endl;
	value = value2;
	cout << "value : " << value << ", *ptr : " << *ptr << ", ptr : " << ptr << endl;
}	//10번예제

#include <iostream>
using namespace std;

int main()
{
	int value = 5;
	const int*ptr1 = &value;		//ptr1으로 value값 수정 불가(상수), 주소값 변경 가능
	int*const ptr2 = &value;		//ptr2으로 value값 수정 가능, 주소값 변경 불가능(상수포인터)
	const int*const ptr3 = &value;	//ptr3으로 value값 수정 불가(상수), 주소값 변경 불가(상수 포인터)
}	//11번예제

#include <iostream>
using namespace std;

int main()
{
	int num = 100;
	int *ptr = &num;

	cout << "num : " << num << ", num address : " << &num << endl;
	cout << "*ptr : " << *ptr << ", ptr :  " << ptr << ", ptr address : " << &ptr << endl;
	return 0;
}	//12번예제

#include <iostream>
using namespace std;

int main()
{
	int int_num = 10;
	int float_num = 2.4f;
	char char_c = 'a';
	cout << "int_num Memory location : " << &int_num << endl;
	cout << "int_num Memory size : " << sizeof(int_num) << endl << endl;

	cout << "float_num Memory location : " << &float_num << endl;
	cout << "float_num Memory size : " << sizeof(float_num) << endl << endl;

	cout << "char_c Memory location : " << &char_c << endl;
	cout << "char_c Memory size : " << sizeof(char_c) << endl;
	return 0;
}	//13번예제

#include <iostream>
using namespace std;

int main()
{
	int int_num = 1;
	float float_num = 2.4f;
	char char_c = 'a';

	int *ptr_int = &int_num;
	float *ptr_float = &float_num;
	char *ptr_c = &char_c;

	cout << "*ptr_int : " << *ptr_int << ", ptr_int : " << ptr_int << endl;
	cout << "*ptr_float : " << *ptr_float << ", ptr_float ; " << ptr_float << endl;
	cout << "*ptr_c : " << *ptr_c << ", ptr_c : " << ptr_c << endl;
	return 0;
}	//14번예제

#include <iostream>
using namespace std;

int main()
{
	int num = 100, *ptr = &num;
	cout << "num : " << num << ", num address : " << &num << endl;
	cout << "*ptr : " << *ptr << ", ptr : " << ptr << ", ptr address : " << &ptr << endl;

	num = 50;
	cout << "num : " << num << ", num address : " << &num << endl;
	cout << "*ptr : " << *ptr << ", ptr : " << ptr << ", ptr address : " << &ptr << endl;

	*ptr = 20;
	cout << "num : " << num << ", num address : " << &num << endl;
	cout << "*ptr : " << *ptr << ", ptr : " << ptr << ", ptr address : " << &ptr << endl;

	int num2 = 33;
	ptr = &num2;
	cout << "num : " << num << ", num address : " << &num << endl;
	cout << "*ptr : " << *ptr << ", ptr : " << ptr << ", ptr address : " << &ptr << endl;
}	//15번예제

#include <iostream>
using namespace std;

int main()
{
	char c = 'a';
	char *ptr_c = &c;
	cout << "c : " << c << ", c address : " << &c << endl;
	cout << "*ptr_c : " << *ptr_c << ", ptr_int : " << ptr_c << ", ptr_c address : " << &ptr_c << endl;

	c = 'b';
	cout << "c : " << c << ", c address : " << &c << endl;
	cout << "*ptr_c : " << *ptr_c << ", ptr_int : " << ptr_c << ", ptr_c address : " << &ptr_c << endl;

	*ptr_c = 'c';
	cout << "c : " << c << ", c address : " << &c << endl;
	cout << "*ptr_c : " << *ptr_c << ", ptr_int : " << ptr_c << ", ptr_c address : " << &ptr_c << endl;

	char c2 = 'k';
	ptr_c = &c2;
	cout << "c : " << c << ", c address : " << &c << endl;
	cout << "*ptr_c : " << *ptr_c << ", ptr_int : " << ptr_c << ", ptr_c address : " << &ptr_c << endl;
	return 0;
}	//16번예제

#include <iostream>
using namespace std;

int main()
{
	const char *c_ptr = "hello";
	cout << "*c_ptr : " << *c_ptr << ", c_ptr : " << c_ptr << ", c_ptr address : " << &c_ptr << endl;
	return 0;
}	//17번예제

#include <iostream>
using namespace std;

int main()
{
	const char *ptr_arr[3];
	ptr_arr[0] = "Hello";
	ptr_arr[1] = "C";
	ptr_arr[2] = "word";

	for (int i = 0; i < 3; i++)
		cout << "*ptr_arr[" << i << "] : " << *ptr_arr[i] << ", ptr_arr[" << i << "] : " << ptr_arr[i] << ", ptr_arr[" << i << "] address : " << &ptr_arr << endl;
	return 0;
}	//18번예제

#include <iostream>
using namespace std;

int main()
{
	char(*arr_ptr)[3];
	char temp1[3] = { 'a','b','c' };
	char temp2[3] = { 'd','e','f' };

	cout << "temp1 address : " << &temp1 << endl;
	cout << "temp2 address : " << &temp2 << endl;

	arr_ptr = &temp1;
	cout << "arr_ptr : " << arr_ptr << " arr_ptr address : " << &arr_ptr << endl;
	for (int i = 0; i < 3; i++)
		cout << (*arr_ptr)[i];
	cout << endl;

	arr_ptr = &temp2;
	cout << "arr_ptr : " << arr_ptr << " arr_ptr address : " << &arr_ptr << endl;
	for (int i = 0; i < 3; i++)
		cout << (*arr_ptr)[i];
	cout << endl;
	return 0;
}	//19번예제

#include <iostream>
using namespace std;

int main()
{
	int *ptr;
	int n = 100;
	ptr = &n;
	cout << &n << endl;
	cout << ptr << endl;
	cout << *ptr << endl;
	return 0;
}	//20번예제

#include <iostream>
using namespace std;

void swap1(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swap2(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int a = 10, b = 20;
	cout << "before : " << a << " " << b << endl;
	swap1(a, b);	//call by value
	cout << "after : " << a << " " << b << endl;

	cout << "before : " << a << " " << b << endl;
	swap2(&a, &b);	//call by reference
	cout << "after : " << a << " " << b << endl;
	return 0;
}	//21번예제

#include <iostream>
using namespace std;

int main()
{
	int num_01 = 10, num_02 = 20, num_03 = 30;
	int *arr[3] = { &num_01,&num_02,&num_03 };
	for (int i = 0; i < 3; i++)
	{
		cout << arr[i] << endl;
		cout << *arr[i] << endl;
	}
	return 0;
}	//22번예제

#include <iostream>
using namespace std;

int main()
{
	int array[] = { 1,2,3,4,5 };
	for (int data : array)
		data = data * 5;
	for (int i = 0; i < 5; i++)
		cout << array[i] << endl;
	cout << "----------" << endl;

	for (int &data : array)
		data = data * 5;
	for (int i = 0; i < 5; i++)
		cout << array[i] << endl;
	return 0;
}	//23번예제

#include <iostream>
using namespace std;

int main()
{
	int value = 5;
	int *ptr = &value;
	int **ptrptr = &ptr;
	int *nptr = nullptr;
	int **nptrptr = nullptr;

	cout << "*ptr : " << *ptr << endl;
	cout << "**ptr : " << **ptrptr << endl;
	cout << "nptr : " << nptr << endl;
	cout << "nptrptr : " << nptrptr << endl;
	return 0;
}	//24번예제

#include <iostream>
using namespace std;

void swap(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 5, b = 10;
	cout << "before a : " << a << endl;
	cout << "before b : " << b << endl;
	cout << "----------" << endl;
	swap(a, b);
	cout << "after a : " << a << endl;
	cout << "after b : " << b << endl;
	return 0;
}	//25번예제

#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int a = 5, b = 10;
	cout << "before a : " << a << endl;
	cout << "before b : " << b << endl;
	cout << "----------" << endl;
	swap(&a, &b);
	cout << "after a : " << a << endl;
	cout << "after b : " << b << endl;
	return 0;
}	//26번예제

#include <iostream>
using namespace std;

int main()
{
	int a = 1, &b = a;
	cout << "a의 값 : " << a << endl;
	cout << "b의 값 : " << b << endl;

	b = 2;
	cout << "a의 값 : " << a << endl;
	cout << "b의 값 : " << b << endl;

	cout << "a의 주소 : " << &a << endl;
	cout << "b의 주소 : " << &b << endl;
}	//27번예제

#include <iostream>
using namespace std;

void swap_by_value(int a, int b)
{
	int swap;
	swap = a;
	a = b;
	b = swap;
}

void swap_by_pointer(int *a, int *b)
{
	int swap;
	swap = *a;
	*a = *b;
	*b = swap;
}

void swap_by_reference(int &a, int &b)
{
	int swap;
	swap = a;
	a = b;
	b = swap;
}

int main()
{
	int a = 1, b = 2;
	cout << "a의 값 : " << a << endl;
	cout << "b의 값 : " << b << endl;

	swap_by_value(a, b);
	cout << "a의 값 : " << a << endl;
	cout << "b의 값 : " << b << endl;

	swap_by_reference(a, b);
	cout << "a의 값 : " << a << endl;
	cout << "b의 값 : " << b << endl;

	swap_by_pointer(&a, &b);
	cout << "a의 값 : " << a << endl;
	cout << "b의 값 : " << b << endl;
	return 0;
}	//28번예제

#include <iostream>
using namespace std;

int main()
{
	int *ptr1 = new int(10);
	int *ptr2 = new int;
	*ptr2 = 20;
	cout << "ptr1 : " << *ptr1 << ", ptr2 : " << *ptr2 << endl;
	delete ptr1, ptr2;
	return 0;
}	//29번예제

#include <iostream>
using namespace std;

int main()
{
	int *ptr = new int[10];
	ptr[0] = 10;
	ptr[1] = 20;
	ptr[2] = 30;

	cout << ptr[1] << endl;
	cout << ptr[2] << endl;
	delete[] ptr;
	return 0;
}	//30번예제

#include <iostream>
using namespace std;

typedef struct Student
{
	char name[6];
	int age;
	double score;
};

int main()
{
	Student *p = new Student;
	strcpy_s(p->name, "Park");
	p->age = 22;
	p->score = 80.8;
	cout << p->name << endl;
	cout << p->age << endl;
	cout << p->score << endl;
	delete p;
	return 0;
}	//31번예제

#include <iostream>
#include <string>
using namespace std;

typedef struct Employee
{
	string name;
	int Birthday = 19990101;
	int id;
	double scoreDou = 0.0;
	char scoreChar = 'F';
};

int main()
{
	string name = "Kim";
	int birthday = 20000112;
	int id = 2019037004;
	double scoreDou = 3.5;
	char scoreChar = 'B';

	Employee Park;
	Park.name = "Byeongjo";
	Park.id = 2021289001;
	Employee Lee = { "Samsung",19990104,2014040001,2.0,'c' };
	return 0;
}	//32번예제

#include <iostream>
#include <string>
using namespace std;

typedef struct Employee
{
	string name;
	int Birthday = 19990101;
	int id;
	double scoreDou = 0.0;
	char scoreChar = 'F';
};

int main()
{
	Employee Park;
	Park.name = "Byeongjo";
	Park.id = 2021289001;
	Employee Lee = { "Samsung",19990104,2014040001,2.0,'c' };

	Employee *Kim;
	Kim->Birthday = 20000112;
	(*Kim).id = 2019037004;
	return 0;
}	//33번예제