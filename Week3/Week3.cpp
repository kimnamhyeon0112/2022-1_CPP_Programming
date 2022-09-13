#include <iostream>
using namespace std;

int main()
{
	char i = 97;
	char j = 'a';
	cout << "char values" << endl;
	cout << "i: " << i << endl;
	cout << "j: " << j << endl;
	cout << "integer values" << endl;
	cout << "i: " << static_cast<int>(i) << endl;
	cout << "j: " << static_cast<int>(j) << endl;
	return 0;
}	//1번예제(char)

#include <iostream>
#include <string>
using namespace std;

int main()
{
	char C_string_1[] = "Hello CBNU 1";
	char C_string_2[20] = "Hello CBNU 2";
	char *C_string_3 = "Hello CBNU 3";
	cout << "C style" << endl;
	cout << "type 1: " << C_string_1 << endl;
	cout << "type 2: " << C_string_2 << endl;
	cout << "type 3: " << C_string_3 << endl;

	string s = "Hell CBNU string type";	//string 헤더 포함해야 동작
	cout << "string values" << endl;
	cout << "s: " << s << endl;
	return 0;
}	//2번예제(Char string & string define)

#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

int main()
{
	// C Style Code
	char c_string[] = "Hello CBNU C Style";
	cout << "text : " << c_string << endl;
	cout << "type : " << typeid(c_string).name() << endl;	//typeid => 배열의 타입과 크기 확인 == char [19]
	cout << "long : " << sizeof(c_string) << endl;
	for (int i = 0; i < sizeof(c_string); i++)
		if (c_string[i] == '\0')
			cout << "have NULL" << endl;
		else if (i == sizeof(c_string) - 1)
			cout << "Not have NULL" << endl;

	// C++ Style Code
	string cpp_string = "Hello CBNU CPP Style";
	cout << "text : " << cpp_string << endl;
	cout << "type : " << typeid(cpp_string).name() << endl;
	cout << "long : " << cpp_string.size() << endl;		//sizeof가 아닌 string name뒤에.size()를 붙인다.
	for (int i = 0; i < cpp_string.size(); i++)
		if (cpp_string[i] == '\0')
			cout << "have NULL" << endl;
		else if (i == cpp_string.size() - 1)
			cout << "Not have NULL" << endl;
	return 0;
}	//3번예제(char String & String s)

#include <iostream>
#include <string>
using namespace std;

int main()
{
	// C Style I/0
	char c_string[20];
	cout << "C style String input : ";
	cin.getline(c_string, 20);
	//cin >> c_string;	//result: C style String output : Hello, cuz of enter
	cout << "C style String output : " << c_string << endl;

	// C++ Style I/O
	string cpp_string;
	cout << "CPP style String input : ";
	getline(cin,cpp_string);		//string 헤더를 사용해 문자열을 만들면 cin.getline형식이 아닌 getline(cin,strname)이 되어야 한다.
	//cin >> cpp_string;	//result: CPP style String output : Hello, cuz of enter
	cout << "CPP style String output : " << cpp_string << endl;
	return 0;
}	//4번예제(String input / output)

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s = "1";
	string s1 = "Hello ";
	string s2 = "CBNU ";
	string s3 = "CPP ";
	string s4 = "Style";

	//add & change
	s = s1 + s2;
	cout << "string add & change : " << s << endl;

	//insert
	s.insert(2, s3);
	cout << "string insert : " << s << endl;

	//erase
	s.erase(2, 4);
	cout << "string erase : "<< s <<endl;

	//substr
	cout << "string substr : " << s.substr(1, 5) << endl;
	//s.substr(1, 5);									//정상출력이 안되고 s(Hello CBNU)로 출력됨
	//cout << "string substr : " << s << endl;			//따라서 의미없는 코드
	return 0;
}	//5번예제(String class(add, change, insert, erase, substr))

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string word1 = "I like C++ and i love C++ word!";
	string word2 = "C++";
	cout << "length : " << word1.length() << " / size : " << word1.size() << endl;
	//find
	cout << "Find 'i' : " << word1.find("i") << endl;
	cout << "Find word2 string : " << word1.find(word2, 3) << endl;
	cout << "Find 'li' : " << word1.find("li", 5) << endl;
	//compare
	string word3 = "CPP";
	string word4 = "Java";
	cout << "String Compare : " << word3.compare(word4) << endl;
	//replace
	int index = word1.find(word2);						//index로 word1에서 word2의 내용과 동일한 내용을 find
	if (index != string::npos)							//find한 값이 Trash 값이 아니라면
		word1.replace(index, word2.length(), word4);	//word1의 index값을 word4로 대체한다
	cout << "string Replace : " << word1 << endl;
	return 0;
}	//6번예제(String class(find, compare, replace))

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream ifs;
	string s;
	string full_s = "";
	ifs.open("input.txt");
	if (ifs.is_open())
	{
		while (!ifs.eof())
		{
			getline(ifs, s);
			cout << "File read : " << s << endl;
			full_s = full_s + s;
		}
	}
	ifs.close();
	cout << "Full text" << endl;
	cout << full_s;
	return 0;

}	//7번예제(File input)

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ofstream ofs;
	ofs.open("output.txt");
	if (ofs.is_open())
	{
		for (int i = 0; i < 10; i++)
			ofs << i << " ";
		ofs << '\n';

		string s;
		cout << "text input : ";
		getline(cin, s);
		ofs << s;

		string S = "Hello CPP";
		ofs << S;
	}
	ofs.close();
	cout << "file output";
	return 0;
}	//8번예제(File Output)

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	string s1 = ",";
	cout << "Enter the string: ";
	getline(cin, s);

	int index;
	for (int i = 0; i <= s.size(); i++)
	{
		index = s.find(" ");
		if (index != string::npos)
			s.replace(index, s1.length(), s1);
	}
	cout <<endl<< "the result: " << s;
	cout << endl;
	return 0;
}	//연습문제(공백을 콤마로 대체)