#pragma once
#include "Point.h"
#include "UseCount.h"

class PointHandle
{
public:
	PointHandle(void);
	PointHandle(int,int);
	PointHandle(const Point&);
	PointHandle(const PointHandle&);
	PointHandle& operator=(const PointHandle&);

	~PointHandle(void);
	int X()const;
	PointHandle& X(int);

	int Y()const;
	PointHandle& Y(int);

private:
	Point* p;
	UseCount u;
};

