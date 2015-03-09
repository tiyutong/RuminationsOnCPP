// IteratorTemplate2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Constant_iterator.h"
#include "ostream_iterator.h"
#include "istream_iterator.h"
using namespace std;


template<class In, class Out>
Out Copy(In start, In end, Out dest)
{
	while(start != end)
	{
		*dest++ = *start++;
	}
	return dest;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char* hello = "Hello ";
	char* world = "world";
	char message[15];
	char* p = message;

	p = Copy(hello, hello + 6, p);
	p = Copy(world, world + 5, p);
	*p = '\0';

	cout << message << endl;


	int x[100];

	Constant_iterator c(10);

	Copy(c, c + 100, x);

	ostream_iterator<int> oi(cout, " \n");
	Constant_iterator d(42);

	Copy(d, d + 10, oi);


	ostream_iterator<int> output(cout,  " \n");
	istream_iterator<int> input(cin);
	istream_iterator<int> eof;

	Copy(input, eof, output);
	return 0;
}

