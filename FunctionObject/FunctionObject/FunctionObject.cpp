// FunctionObject.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Composition.h"
int f(int a)
{
	return a/3 - 3;
}

int g(int a)
{
	return a * 3;
}

int h(int a)
{
	return a + 3;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Composition<int ,int> fg(f, g);
	Composition<int ,int> fgh(fg, h);

	int result = fgh(16);
	return 0;
}

