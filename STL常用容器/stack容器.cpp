#include <iostream>
using namespace std;
#include <stack>

//stack����

void test01()
{
	//�ص��Ƚ����
	stack<int>s;

	//��ջ
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	cout << "ջ�Ĵ�С��" << s.size() << endl;
	//ֻҪջ��Ϊ�� �Ͳ鿴ջ��
	while (!s.empty())
	{
		cout << "�鿴ջ��Ԫ�أ�" << s.top() << endl;

		s.pop();
	}
	cout << "ջ�Ĵ�С��" << s.size() << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}