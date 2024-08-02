#include <iostream>
using namespace std;
#include <queue>
#include <string>

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

void test01()
{
	//������������
	queue<Person>q;

	//׼������
	Person p1("A", 40);
	Person p2("B", 30);
	Person p3("C", 20);
	Person p4("D", 10);

	//���
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	cout << "���д�СΪ��" << q.size() << endl;

	//�ж�ֻҪ���в�Ϊ�� �鿴��ͷ �鿴��β ����
	while (!q.empty())
	{
		//�鿴��ͷ
		cout << "��ͷԪ�� --- ������" << q.front().m_Name << " ���䣺" << q.front().m_Age << endl;

		//�鿴��β
		cout << "��βԪ�� --- ������" << q.back().m_Name << " ���䣺" << q.back().m_Age << endl;

		//����
		q.pop();
	}
	cout << "���д�СΪ��" << q.size() << endl; 
}

int main()
{
	test01();
	system("pause");
	return 0;
}