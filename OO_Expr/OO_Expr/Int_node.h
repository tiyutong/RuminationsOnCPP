#pragma once
#include "expr_node.h"
class Int_node :
	public Expr_node
{
	friend class ExprHandle;

	int n;

	Int_node(int );
	~Int_node(void);

	void print(ostream&) const;

	int Eval(void)const;
};

