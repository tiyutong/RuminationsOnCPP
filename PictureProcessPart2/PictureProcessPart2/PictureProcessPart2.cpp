// PictureProcessPart2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>
#include "Picture.h"
#include "P_Node.h"
#include <iostream>
using namespace std;

char* init[] = {"Paris", "in the", "Spring"}; 

int _tmain(int argc, _TCHAR* argv[])
{
	int a[3] = { 1,2,3};
	int* pd = a;

	int ss= sizeof(pd);

	int b = sizeof(a);
	int c = sizeof(&a);

	char str[10] = "3322222";
	int d = strlen(str);
	int e = sizeof(str);

	Picture p(init, 3);
	cout << p << endl;

	Picture q = frame(p);
	cout << q << endl;

	Picture r = p | q;
	cout << r << endl;

	Picture s = p & q;
	cout << s << endl;

	Picture sr = Reframe(s, '!', '@' ,'#');
	cout << sr << endl;


	return 0;
}

