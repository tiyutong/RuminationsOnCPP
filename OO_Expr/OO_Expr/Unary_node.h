#pragma once
#include "expr_node.h"
#include <string>
#include "ExprHandle.h"

class Unary_node:
	public Expr_node
{
	friend class ExprHandle;
	string op;
	ExprHandle opnd;

	Unary_node(const string& a, ExprHandle b);
	~Unary_node(void);

	void print(ostream&) const;
	int Eval() const;
};

