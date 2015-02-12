// ArrayPointer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Array.h"
#include "Pointer.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Array<int>* ap = new Array<int> (10);
	Pointer<int> p(*ap, 5);

	delete ap;
	*p = 42;

	return 0;
}

