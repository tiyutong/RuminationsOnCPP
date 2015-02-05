#include "stdafx.h"
#include "Unary_node.h"


Unary_node::Unary_node(const string& a, ExprHandle b) :
	op(a), opnd(b)
{
}

void Unary_node::print(ostream& o) const
{
	o << "(" << op << opnd << ")";
}

int Unary_node::Eval(void)const
{
	if(op == "-")
		return -opnd.Eval();

	printf("Error! bad + %s +  in BinaryNode\n", op);
	return -1;
}

Unary_node::~Unary_node(void)
{
}
