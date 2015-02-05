#include "stdafx.h"
#include "Binary_node.h"


Binary_node::Binary_node(const string& a, ExprHandle b, ExprHandle c) :
	op(a), left(b), right(c)
{
}

void Binary_node::print(ostream& o) const
{
	o << "(" << left << op << right<< ")";
}

int Binary_node::Eval(void) const
{
	int op1 = left.Eval();
	int op2 = right.Eval();

	if(op == "-")
	{
		return op1 - op2;
	}

	if(op == "+")
	{
		return op1 + op2;
	}

	if(op == "*")
	{
		return op1 * op2;
	}

	if(op == "/" && op2 != 0)
	{
		return op1 / op2;
	}

	printf("Error! bad + %s +  in BinaryNode\n", op);

	return -1;
}
Binary_node::~Binary_node(void)
{
}
