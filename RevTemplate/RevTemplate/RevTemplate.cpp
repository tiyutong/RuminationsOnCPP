// RevTemplate.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Rev.h"

template<class T, class X>
T find(T start, T beyond, const X& x)
{
	while(start != beyond && *start != x)
	{
		++start;
	}
	return start;
}


int _tmain(int argc, _TCHAR* argv[])
{
	typedef Rev<int *, int> R;

	int x[100];

	for(int i = 0; i < 100; i++)
	{
		x[i] = i;
	}

	int* p = find(x, x+100, 42);

	R r = find(R(x + 100), R(x), 42);

	return 0;
}

