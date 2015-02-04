#include "stdafx.h"
#include "PointHandle.h"


PointHandle::PointHandle(void) : p(new Point)
{
}

PointHandle::PointHandle(int x, int y) : p(new Point(x,y))
{
}

PointHandle::PointHandle(const Point& p0) : p(new Point(p0))
{
}

PointHandle::PointHandle(const PointHandle& h) : p(h.p), u(h.u)
{

}

PointHandle& PointHandle::operator=(const PointHandle & h)
{
	if(u.Reattach(h.u))
	{
		delete p;
	}
	p = h.p;
	return *this;
}

int PointHandle::X(void)const
{
	return p->X();
}

int PointHandle::Y(void)const
{
	return p->Y();
}

PointHandle& PointHandle::X(int x0)
{
	if(u.MakeOnly())
	{
		p = new Point(*p);
	}
	p->X(x0);

	return *this;
}

PointHandle& PointHandle::Y(int y0)
{
	if(u.MakeOnly())
	{
		p = new Point(*p);
	}
	p->Y(y0);

	return *this;
}

PointHandle::~PointHandle(void)
{
	if(u.Only())
	{
		delete p;
	}
}
