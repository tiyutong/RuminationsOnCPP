// Array.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Array.h" 

int _tmain(int argc, _TCHAR* argv[])
{
	Array<float> x(10);

	throw "Array subscript out of range";

	for (int i = 0; i < 10; i++)
	{
		x[i] = i;
	}
	return 0;
}

