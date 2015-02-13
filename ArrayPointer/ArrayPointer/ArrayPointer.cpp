// ArrayPointer.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Array.h"
#include "Pointer.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Array<int>* ap = new Array<int> (10);
	Pointer<int> p(*ap, 0);

	delete ap;
	*p = 42;

	Pointer<int> end = p + 10;
	while (p != end)
	{
		*p++ = end - p;
	}

	Ptr_to_const<int> pc(*ap, 0);
	
	Ptr_to_const<int> pcEnd = pc + 10;

	return 0;
}

