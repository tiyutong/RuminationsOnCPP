#pragma once
#include "expr_node.h"
#include <string>
#include "ExprHandle.h"

class Binary_node :
	public Expr_node
{
	friend class ExprHandle;
	string op;

	ExprHandle left;
	ExprHandle right;

	Binary_node(const string& a,ExprHandle b, ExprHandle c);
	~Binary_node(void);

	void print(ostream&) const;
	int Eval(void)const;
};
