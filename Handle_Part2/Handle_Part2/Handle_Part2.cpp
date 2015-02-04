// Handle_Part2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "PointHandle.h"

int _tmain(int argc, _TCHAR* argv[])
{
	PointHandle h(33,39);
	printf("h.x = %d\n",  h.X());
	printf("h.y = %d\n",  h.Y());

	Point p(34, 35);
	PointHandle h2(p);
	
	printf("h2.x = %d\n",  h2.X());
	printf("h2.y = %d\n",  h2.Y());

	PointHandle h3 = h;
	h3.X(100);
	h3.Y(100);

	printf("h3.x = %d\n",  h3.X());
	printf("h3.y = %d\n",  h3.Y());

	
	printf("h.x = %d\n",  h.X());
	printf("h.y = %d\n",  h.Y());

	return 0;
}

