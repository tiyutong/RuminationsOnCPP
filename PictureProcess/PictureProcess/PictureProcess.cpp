// PictureProcess.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Picture.h"
#include <iostream>

char* init[] = {"Paris", "in the", "Spring"}; 

int _tmain(int argc, _TCHAR* argv[])
{
	Picture p(init, 3);
	cout << p << endl;

	Picture q = frame(p);
	cout << q << endl;

	Picture r = p | q;
	cout << r << endl;

	Picture s = p & q;
	cout << s << endl;

	return 0;
}

