#pragma once
#include "Point.h"
class UPoint
{
	UPoint(void) : u(1){}
	~UPoint(void);

	UPoint(int x, int y): p(x,y), u(1){}
	UPoint(const Point& p0) : p(p0), u(1){}

	friend class PointHandle;

	Point p;
	int u;

	
};

