#include "stdafx.h"
#include "P_Node.h"


P_Node::P_Node(void) : use(1)
{
}


int P_Node::Max(int x, int y)
{
	return x > y ? x : y;
}

P_Node::~P_Node(void)
{
}
