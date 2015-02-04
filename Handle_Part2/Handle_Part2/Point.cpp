#include "stdafx.h"
#include "Point.h"


Point::Point(void): xVal(0), yVal(0)
{
}

Point::Point(int x, int y): xVal(x), yVal(y)
{

}

int Point::X(void) const
{
	return xVal;
}

int Point::Y(void) const
{
	return yVal;
}

Point& Point::X(int xv)
{
	xVal = xv;
	return *this;
}

Point& Point::Y(int yv)
{
	yVal = yv;
	return *this;
}

Point::~Point(void)
{
}
