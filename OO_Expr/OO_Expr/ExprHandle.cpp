#include "stdafx.h"
#include "ExprHandle.h"
#include "Int_node.h"
#include "Unary_node.h"
#include "Binary_node.h"

ExprHandle::ExprHandle(int n)
{
	p = new Int_node(n);
}

ExprHandle::ExprHandle(const string& op, ExprHandle t)
{
	p = new Unary_node(op, t);
}

ExprHandle::ExprHandle(const string& op, ExprHandle left, ExprHandle right)
{
	p = new Binary_node(op, left, right);
}

ExprHandle::ExprHandle(const ExprHandle& t)
{
	p = t.p;
	++p->use;
}

ExprHandle& ExprHandle::operator= (const ExprHandle& rhs)
{
	rhs.p->use++;
	if(--p->use == 0)
	{
		delete p;
	}
	p = rhs.p;
	return *this;
}

ostream& operator << (ostream& o, const ExprHandle& t)
{
	t.p->print(o);
	return o;
}
ExprHandle::~ExprHandle(void)
{
	if(--p->use == 0)
	{
		delete p;
	}
}
