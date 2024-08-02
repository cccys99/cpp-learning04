#include <iostream>
using namespace std;
#include <stack>

//stack容器

void test01()
{
	//特点先进后出
	stack<int>s;

	//入栈
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	cout << "栈的大小：" << s.size() << endl;
	//只要栈不为空 就查看栈顶
	while (!s.empty())
	{
		cout << "查看栈顶元素：" << s.top() << endl;

		s.pop();
	}
	cout << "栈的大小：" << s.size() << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}