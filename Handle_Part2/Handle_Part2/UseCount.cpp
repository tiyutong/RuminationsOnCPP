#include "stdafx.h"
#include "UseCount.h"


UseCount::UseCount(void) : p(new int(1))
{
}

UseCount::UseCount(const UseCount& u) : p(u.p)
{
	++*p;
}

bool UseCount::Reattach(const UseCount& u)
{
	++*u.p;
	if(--*p == 0)
	{
		delete p;
		p = u.p;
		return true;
	}
	p = u.p;
	return false;
}

bool UseCount::MakeOnly(void)
{
	if(*p == 1)
	{
		return false;
	}
	else
	{
		--*p;
		p = new int(1);
		return true;
	}
}

bool UseCount::Only(void)
{
	return (*p == 1);
}

UseCount::~UseCount(void)
{
	if(--*p == 0)
	{
		delete p;
	}
}
