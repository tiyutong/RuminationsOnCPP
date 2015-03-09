#include "stdafx.h"
#include "Constant_iterator.h"


Constant_iterator::Constant_iterator(int k) : n(k)
{
}


Constant_iterator::~Constant_iterator(void)
{
}

int Constant_iterator::operator*() const
{
	return n;
}

Constant_iterator& Constant_iterator::operator++()
{
	++count;
	return *this;
}


Constant_iterator Constant_iterator::operator++(int)
{
	Constant_iterator r = *this;
	++count;
	return r;
}

Constant_iterator operator+(const Constant_iterator& p, int n)
{
	Constant_iterator r = p;
	r.count += n;
	return r;
}

Constant_iterator operator+(int n, const Constant_iterator& p)
{
	Constant_iterator r = p;
	r.count += n;
	return r;
}

int operator==(const Constant_iterator&p, const Constant_iterator& q)
{
	return p.count == q.count && p.n == q.n;
}

int operator!=(const Constant_iterator&p, const Constant_iterator& q)
{
	return !(p == q);
}