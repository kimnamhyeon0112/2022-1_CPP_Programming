#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector <int>vec = { 100 };
	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	cout << "vec size ; " << vec.size() << endl;
	cout << "vec[3]" << vec[3] << endl;
	for (auto& itr : vec)
		cout << itr << " ";
	cout << endl;
	return 0;
}	//12주차 실습예제 1

#include <iostream>
#include <deque>
using namespace std;

int main()
{
	deque <int>deq = { 100 };
	for (int i = 0; i < 10; i++)
		deq.push_back(i);
	deq.push_front(99);
	cout << "vec size ; " << deq.size() << endl;
	cout << "vec[3] : " << deq[3] << endl;
	for (auto& itr : deq)
		cout << itr << " ";
	cout << endl;
	return 0;
}	//12주차 실습예제 2

#include <iostream>
#include <list>
#include <iterator>
using namespace std;

int main()
{
	list <int>li = { 100,1,2,2,3,4,3,5,5 };
	li.push_back(10);
	li.push_front(99);
	cout << "vec size ; " << li.size() << endl;
	for (auto& itr : li)
		cout << itr << " ";
	cout << endl;
	li.unique();
	copy(li.begin(), li.end(), ostream_iterator <int>(cout, " "));
	cout << endl;
	return 0;
}	//12주차 실습예제 3

#include <iostream>
#include <iterator>
#include <forward_list>
using namespace std;

int main()
{
	forward_list<int> li = { 100,1,2,3,4,4,5,3 };
	li.push_front(99);
	for (auto& itr : li)
		cout << itr << " ";
	cout << endl;
	li.unique();
	copy(li.begin(), li.end(), ostream_iterator<int>(cout, " "));
	li.remove(3);
	cout << endl;
	copy(li.begin(), li.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}	//12주차 실습예제 4

#include <iostream>
#include <iterator>
#include <string>
#include <set>
using namespace std;

int main()
{
	set<string>strSet = { "Hello" };
	multiset<string>strmSet = { "Hello" };
	strSet.insert("World");
	strSet.insert("Hello");
	strSet.erase("Hello");
	cout << "strSet Size : " << strSet.size() << endl;
	copy(strSet.begin(), strSet.end(), ostream_iterator<string>(cout, " "));
	cout << endl;

	strmSet.insert("World");
	strmSet.insert("Hello");
	cout << "strmSet Size : " << strmSet.size() << endl;
	copy(strmSet.begin(), strmSet.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
	return 0;
}	//12주차 실습예제 5

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	map <string, int> Mp;
	multimap <string, int> mMp;
	Mp.insert(pair<string, int>("map", 10));
	Mp["set"] = 20;
	Mp["map"] = 30;
	cout << "Mp Size : " << Mp.size() << endl;
	cout << "Mp map : " << Mp["map"] << endl;
	for (auto& itr : Mp)
		cout << "Key =" << itr.first << ", Value = " << itr.second << endl;
	cout << endl;
	return 0;
}	//12주차 실습예제 6

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> Stack;
	Stack.push(1);
	Stack.emplace(3);
	Stack.emplace(4);
	cout << "Size : " << Stack.size() << endl;
	cout << Stack.top() << endl;
	Stack.pop();
	cout << Stack.top() << endl;
	return 0;
}	//12주차 실습예제 7

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> que;
	que.push(0);
	que.push(1);

	for (int i = 2; i < 10; i++)
	{
		int temp = que.front();
		cout << temp << " ";
		que.pop();
		que.push(temp + que.front());
	}
	cout << endl;
	cout << "size : " << que.size() << endl;
	return 0;
}	//12주차 실습예제 8

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	priority_queue<int> pq;
	for (const int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
		pq.push(n);
	for (int i = 0; i < 10; ++i)
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
	return 0;
}	//12주차 실습예제 9

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> container;
	for (int i = 0; i < 10; ++i)
		container.push_back(i);

	vector<int>::const_iterator itr;
	itr = container.begin();

	while (itr != container.end())
	{
		cout << *itr << " ";
		++itr;
	}
	cout << endl;
	vector<int>::iterator _itr;
	_itr = container.begin();
	_itr[4] += 1;
	while (_itr != container.end())
	{
		cout << *_itr << " ";
		++_itr;
	}
	cout << endl;
	return 0;
}	//12주차 실습예제 10

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	vector<int>vec = { 8,4,2,3,5,2,1,6,3,5 };
	cout << "find example 1" << endl;
	auto result = find(vec.begin(), vec.end(), 3);
	cout << "3은 " << distance(vec.begin(), result) + 1 << " 번째 원소\n" << endl;
	
	cout << "find example 2" << endl;
	auto current = vec.begin();
	while (true)
	{
		current = find(current, vec.end(), 3);
		if (current == vec.end())break;
		cout << "5sms " << distance(vec.begin(), current) + 1 << " 번째 원소\n" << endl;
		current++;
	}
	return 0;
}	//12주차 실습예제 11

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void print(int n)
{
	cout << n << " ";
}

int main()
{
	vector<int>vec = { 8,4,2,3,5,2,1,6,3,5 };
	cout << "find example 1" << endl;
	for_each(vec.begin(), vec.end(), print);
	cout << "\n" << endl;

	cout << "find example 2" << endl;
	vector<int>::iterator itr = vec.begin();
	
	for_each(itr, itr + vec.size(), [](auto& n)
	{
		cout << n << " ";
	});
	cout << "\n" << endl;
	return 0;
}	//12주차 실습예제 12

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
	vector<int> v = { 0,1,2,3,4,5,6,7,8,9 };
	vector<int> u = { 10,20,30,40,50 };

	copy(u.begin(), u.end(), v.begin() + 3);
	cout << "copy example." << endl;
	vector<int>::iterator itr = v.begin();
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << "\n" << endl;
	return 0;
}	//12주차 실습예제 13

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
	vector<int> v = { 0,1,2,3,4,5,6,7,8,9 };
	vector<int> u = { 10,20,30,40,50 };

	cout << "swap example.1" << endl;
	swap(v, u);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(u.begin(), u.end(), ostream_iterator<int>(cout, " "));
	cout << "\n" << endl;

	cout << "copy example.2" << endl;
	swap_ranges(v.begin(), v.begin() + 3, u.begin());
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(u.begin(), u.end(), ostream_iterator<int>(cout, " "));
	cout << "\n" << endl;
	return 0;
}	//12주차 실습예제 14

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
	vector<int> vec = { 0,1,2,3,4,5,6,7,8,9 };
	vector<int> vec2(vec.size());

	cout << "transform example.1" << endl;
	cout << "벡터 전체에 1을 더한다" << endl;
	transform(vec.begin(), vec.end(), vec.begin(), [](int i) {return i + 1; });
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
	cout << "\n" << endl;
	
	cout << "transform example.2" << endl;
	cout << "vec 전체에 1을 더한것을 vec2에 저장" << endl;
	transform(vec.begin(), vec.end(), vec2.begin(), [](int i) {return i + 1; });
	copy(vec2.begin(), vec2.end(), ostream_iterator<int>(cout, " "));
	cout << "\n" << endl;
	return 0;
}	//12주차 실습예제 15

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
struct
{
	bool operator()(int a, int b)const
	{
		return a < b;
	}
}customLess;

int main()
{
	vector<int>vec = { 5,7,4,2,8,6,1,9,0,3 };

	cout << "sort example.1" << endl;
	sort(vec.begin(), vec.end());
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "sort example.2" << endl;
	sort(vec.begin(), vec.end(), greater<int>());
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "sort example.3" << endl;
	sort(vec.begin(), vec.end(), customLess);
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "sort example.4" << endl;
	sort(vec.begin(), vec.end(), [](int a, int b)
	{
			return a > b;
	});
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}	//12주차 실습예제 16

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;
struct Employee
{
	int age;
	string name;
};

bool operator<(const Employee& lhs, const Employee& rhs)
{
	return lhs.age < rhs.age;
}

bool cmp(const Employee& lhs, const Employee& rhs)
{
	return lhs.name < rhs.name;
}

int main()
{
	vector<Employee> v = 
	{
		{108,"Arthur"},
		{32,"Ford"},
		{108,"Zaphod"},
	};

	cout << "stable_sort example.1" << endl;
	stable_sort(v.begin(), v.end());
	for (const Employee& e : v)
		cout << e.age << ", " << e.name << endl;
	cout << endl;

	cout << "stable_sort example.2" << endl;
	stable_sort(v.begin(), v.end(), cmp);
	for (const Employee& e : v)
		cout << e.age << ", " << e.name << endl;

	return 0;
}	//12주차 실습예제 17

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

struct Multiplies
{
	int operator()(int total, int n)
	{
		return total * n;
	}
};

int main()
{
	vector<int>vec = { 1,2,3,4,5,6,7,8,9 };

	cout << "accumulate example.1" << endl;
	cout << accumulate(vec.begin(), vec.end(), 100) << "\n" << endl;

	cout << "accumulate example.2" << endl;
	cout << accumulate(vec.begin(), vec.end(), 1, Multiplies()) << "\n" << endl;
	return 0;
}	//12주차 실습예제 18

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

struct Multiplies
{
	int operator()(int total, int n)
	{
		return total + n;
	}
};

struct Plus
{
	int operator()(int total, int n)
	{
		return total * n;
	}
};

int main()
{
	vector<int>vec = { 1,2,3,4 };
	vector<int>vec2 = { 5,6,7,8,9 };

	cout << "inner_product example.1" << endl;
	cout << inner_product(vec.begin(), vec.end(), vec2.begin() + 1, 1) << "\n" << endl;

	cout << "inner_product example.2" << endl;
	cout << inner_product(vec.begin(), vec.end(), vec2.begin() + 1, 1, Plus(), Multiplies()) << "\n" << endl;
	return 0;
}	//12주차 실습예제 19

#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
using namespace std;

struct Plus
{
	int operator()(int total, int n)
	{
		return total * n;
	}
};

int main()
{
	vector<int>vec = { 1,2,3,4,5,6,7,8,9 };
	vector<int>vec2(vec.size());

	cout << "partial_sum example.1" << endl;
	partial_sum(vec.begin(), vec.end(), vec2.begin());
	copy(vec2.begin(), vec2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "partial_sum example.2" << endl;
	partial_sum(vec.begin(), vec.end(), vec2.begin(), Plus());
	copy(vec2.begin(), vec2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}	//12주차 실습예제 20

#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
using namespace std;

struct Plus
{
	int operator()(int total, int n)
	{
		return total * n;
	}
};

int main()
{
	vector<int>vec = { 1,2,3,4,5,6,7,8,9 };
	vector<int>vec2(vec.size());

	cout << "adjacent_difference  example.1" << endl;
	adjacent_difference(vec.begin(), vec.end(), vec2.begin());
	copy(vec2.begin(), vec2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "adjacent_difference example.2" << endl;
	adjacent_difference(vec.begin(), vec.end(), vec2.begin(), Plus());
	copy(vec2.begin(), vec2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}	//12주차 실습예제 21

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int main()
{
	plus<int>add;
	equal_to<int>comp;
	greater_equal<int>ge;

	cout << add(7, 3) << endl;
	cout << comp(7, 3) << endl;
	cout << ge(7, 3) << endl;
	return 0;
}	//12주차 실습예제 22