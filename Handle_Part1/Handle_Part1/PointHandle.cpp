#include "stdafx.h"
#include "PointHandle.h"


PointHandle::PointHandle(void) : up(new UPoint)
{
}

PointHandle::PointHandle(int x, int y) : up(new UPoint(x,y))
{
}

PointHandle::PointHandle(const Point& p) : up(new UPoint(p))
{
}

PointHandle::PointHandle(const PointHandle& h) : up(h.up)
{
	++up->u;
}

PointHandle& PointHandle::operator=(const PointHandle & h)
{
	++h.up->u;
	if(--up->u == 0)
	{
		delete up;
	}
	up = h.up;
	return *this;
}

int PointHandle::X(void)const
{
	return up->p.X();
}

int PointHandle::Y(void)const
{
	return up->p.Y();
}

PointHandle& PointHandle::X(int x0)
{
	if(up->u != 1)
	{
		--up->u;
		up = new UPoint(up->p);
	}
	up->p.X(x0);

	return *this;
}

PointHandle& PointHandle::Y(int y0)
{
	if(up->u != 1)
	{
		--up->u;
		up = new UPoint(up->p);
	}
	up->p.Y(y0);

	return *this;
}

PointHandle::~PointHandle(void)
{
	if(--up->u == 0)
	{
		delete up;
	}
}
