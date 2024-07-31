#include <iostream>
using namespace std;

#include <vector>

void printVector(vector<int>&v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	cout << "����ǰ�Ĵ�ӡ��" << endl;
	printVector(v1);

	vector<int>v2;
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	printVector(v2);

	cout << "������Ĵ�ӡ��" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
}

//ʵ����;
//��swap���������ڴ�ռ�
void test02()
{
	vector<int>v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}
	cout << "v������Ϊ��" << v.capacity() << endl;//v������Ϊ��138255
	cout << "v�Ĵ�СΪ��" << v.size() << endl; //v�Ĵ�СΪ��100000

	v.resize(3); //����ָ����С
	cout << "v������Ϊ��" << v.capacity() << endl; //v������Ϊ��138255
	cout << "v�Ĵ�СΪ��" << v.size() << endl; //v�Ĵ�СΪ��3

	//��swap������
	vector<int>(v).swap(v);
	cout << "v������Ϊ��" << v.capacity() << endl;
	cout << "v�Ĵ�СΪ��" << v.size() << endl; //��ʱ��С������Ϊ3

	//����vector<int>(v).swap(v)�Ľ��ͣ�
	//vector<int>(v) ����һ�����ÿ������캯�� �������µ� �����Ķ��� 
	//������vĿǰ���õĸ�������ʼ�� Ŀǰ�������������
	//swap��������һ�� ָ��Ľ��� 
	//��������
	//���������v��������С��Ϊ3
	//�������� ��ǰ��ִ����֮�� ϵͳ���Զ������ڴ�
}

void test03()
{
	vector<int>v;

	//����reserveԤ���ռ�
	v.reserve(100000);

	int num = 0; //ͳ�ƿ��ٴ���
	int* p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}
	cout << "num = " << num << endl; 
	//���һ��ʼ��֪������ʮ����������� �Ͳ��÷���������
}

int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}