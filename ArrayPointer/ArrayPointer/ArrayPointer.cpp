// ArrayPointer.cpp : �������̨Ӧ�ó������ڵ㡣
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

