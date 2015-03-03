// IteratorTemplate.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Iterator.h"
#include "Array_iterator.h"
#include <iostream>
#include "Reader.h"
using namespace std;

template<class T, class Iter>
void sum2(T& result, Iter ir)
{
	result = 0;
	while(ir.Valid())
	{
		result += ir.Next();
	}
}

//template<class T> T sum(Iterator<T>& ir)
//{
//	T result = 0;
//	while(ir.Valid())
//	{
//		result += ir.Next();
//	}
//	return result;
//}

template<class T> T sum(T* p, int n)
{
	T r = 0;
	sum2(r, Array_iterator<T>(p, n));
	return r;
}


int _tmain(int argc, _TCHAR* argv[])
{
#if 0
	int x[10];

	for(int i = 0; i < 10; i++)
	{
		x[i] = i;
	}

	//Array_iterator<int> it(x,10);
	//cout << sum(it) << endl;
	cout << sum(x, 10) << endl;
#endif

	cout << "Enter numbers: "<< endl;
	double r = 0;
	sum2(r, Reader<double>(cin));
	cout << r << endl;
	return 0;
}

