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

	cout << "互换前的打印：" << endl;
	printVector(v1);

	vector<int>v2;
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	printVector(v2);

	cout << "互换后的打印：" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
}

//实际用途
//用swap可以收缩内存空间
void test02()
{
	vector<int>v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}
	cout << "v的容量为：" << v.capacity() << endl;//v的容量为：138255
	cout << "v的大小为：" << v.size() << endl; //v的大小为：100000

	v.resize(3); //重新指定大小
	cout << "v的容量为：" << v.capacity() << endl; //v的容量为：138255
	cout << "v的大小为：" << v.size() << endl; //v的大小为：3

	//用swap来收缩
	vector<int>(v).swap(v);
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl; //此时大小容量均为3

	//对于vector<int>(v).swap(v)的解释：
	//vector<int>(v) 这是一个利用拷贝构造函数 创建的新的 匿名的对象 
	//会利用v目前所用的个数来初始化 目前匿名的这个对象
	//swap本质类似一个 指针的交换 
	//容器交换
	//所以再输出v的容量大小均为3
	//匿名对象 当前行执行完之后 系统会自动回收内存
}

void test03()
{
	vector<int>v;

	//利用reserve预留空间
	v.reserve(100000);

	int num = 0; //统计开辟次数
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
	//如果一开始就知道了有十万的数据量级 就不用反复开辟了
}

int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}