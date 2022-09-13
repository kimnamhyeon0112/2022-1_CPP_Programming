#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream input;
	ofstream output;
	string s;
	string full_s = "";
	input.open("input.txt");
	if (input.is_open())
	{
		while (!input.eof())
		{
			getline(input, s);
			full_s = full_s + s;
		}
	}
	input.close();
	cout << "before text : " << full_s;
	return 0;
}	//file input

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream in("input.txt");	//input.txt파일 open(이 코드 한줄로 input.txt를 바로 열 수 있음)
	string s;
	string s1 = " ";			//특수문자 공백변경시 필요한 문자열
	string before_full = "";
	string after_full = "";
	string search;
	int select, index, offset, maxidx;
	char max[1000];
	char temp;

	//before txt
	if (in.is_open())						//input.txt가 열려있다면
	{
		while (!in.eof())					//end of file까지
		{
			getline(in, s);					//라인기준으로 하나씩 차례대로 불러옴
			before_full = before_full + s;	//라인들 하나로 합체
		}
	}
	in.close();								//before txt를 출력하면 이미 input은 eof에 가있기 때문에 닫아줌
	cout << "before text : " << before_full << endl;

	//after txt
	ifstream input("input.txt"); // input.txt파일 open
	ofstream output("output.txt"); // output.txt파일 open
	if (input.is_open())
	{
		while (!input.eof())
		{
			getline(input, s);
			for (int i = 0; i < s.size(); i++)
				s[i] = tolower(s[i]);					//대문자 -> 소문자
			//특수문자1
			for (int i = 0; i <= s.size(); i++)
			{
				index = s.find(".");					//find함수를 통해 input.txt에 .이 있는지 find
				if (index != string::npos)				//index가 find함수에 의해 찾아지지 않는다면
					s.replace(index, s1.length(), s1);	//특수문자를 공백으로 대체
			}
			//특수문자2
			for (int i = 0; i <= s.size(); i++)
			{
				index = s.find(",");
				if (index != string::npos)
					s.replace(index, s1.length(), s1);
			}
			//특수문자3
			for (int i = 0; i <= s.size(); i++)
			{
				index = s.find("(");
				if (index != string::npos)
					s.replace(index, s1.length(), s1);
			}
			//특수문자4
			for (int i = 0; i <= s.size(); i++)
			{
				index = s.find(")");
				if (index != string::npos)
					s.replace(index, s1.length(), s1);
			}
			//특수문자5
			for (int i = 0; i <= s.size(); i++)
			{
				index = s.find("[");
				if (index != string::npos)
					s.replace(index, s1.length(), s1);
			}
			//특수문자6
			for (int i = 0; i <= s.size(); i++)
			{
				index = s.find("]");
				if (index != string::npos)
					s.replace(index, s1.length(), s1);
			}
			//특수문자7
			for (int i = 0; i <= s.size(); i++)
			{
				index = s.find("|");
				if (index != string::npos)
					s.replace(index, s1.length(), s1);
			}
			//특수문자8
			for (int i = 0; i <= s.size(); i++)
			{
				index = s.find("\"");
				if (index != string::npos)
					s.replace(index, s1.length(), s1);
			}
			//특수문자9
			for (int i = 0; i <= s.size(); i++)
			{
				index = s.find("\'");
				if (index != string::npos)
					s.replace(index, s1.length(), s1);
			}
			after_full = after_full + s;		//전체문장
		}

		//selection sort upper & lower case(구현 못함)
		cout << "selection sort(1. up / 2. down) : ";
		cin >> select;
		switch (select)
		{
		case 1:		//upper case
				//for (int i = 0; i < after_full.size(); i++)
				//{
				//	string str(max);			//char -> string 형변환 연산자
				//	maxidx = i;
				//	str = after_full[i];
				//	for (int j = i + 1; j < after_full.size(); j++)
				//	{
				//		if (strcmp(str, after_full[j]) < 0)
				//		{
				//			str = after_full[j];
				//			maxidx = j;
				//		}
				//	}
				//	temp = after_full[i];
				//	after_full[i] = after_full[maxidx];
				//	after_full[maxidx] = temp;
				//}
			cout << "after text : " << after_full << endl;
			break;
		case 2:	//lower case
				//for (int i = 0; i < after_full.size(); i++)
				//{
				//	string str(max);			//char -> string 형변환 연산자
				//	maxidx = i;
				//	str = after_full[i];
				//	for (int j = i + 1; j < after_full.size(); j++)
				//	{
				//		if (strcmp(str, after_full[j]) > 0)
				//		{
				//			str = after_full[j];
				//			maxidx = j;
				//		}
				//	}
				//	temp = after_full[i];
				//	after_full[i] = after_full[maxidx];
				//	after_full[maxidx] = temp;
				//}
			cout << "after text : " << after_full << endl;
			break;
		default:
			cout << "Error! Yu have to select 1 or 2" << endl;
			exit(1);	//프로그램 강제종료

		}
		output << after_full; //after_full의 내용을 output.txt에 저장
		cout << "create output.txt" << endl;
		output.close(); //output.txt 파일 close
		input.close();//input.txt 파일 close

		//find and result
		ifstream input("output.txt"); // open original file
		cout << "find : ";
		cin >> search;
		if (input.is_open())
		{
			while (!input.eof())
				getline(input, s);
			if ((offset = s.find(search, 0)) != string::npos)
				cout << "result : " << search << endl;
			else
				cout << "Not found" << endl;
		}
		input.close();
	}
	return 0;
}	//C++ 실습과제 2번