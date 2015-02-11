// Array.cpp : 定义控制台应用程序的入口点。
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

