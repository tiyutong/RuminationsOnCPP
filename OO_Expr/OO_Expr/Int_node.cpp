#include "stdafx.h"
#include "Int_node.h"


Int_node::Int_node(int k) : n(k)
{
}

void Int_node::print(ostream & o) const
{
	o << n;
}

int Int_node::Eval(void) const
{
	return n;
}

Int_node::~Int_node(void)
{
}
