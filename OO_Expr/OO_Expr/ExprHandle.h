#pragma once
#include <ostream>
using namespace std;
#include "Expr_node.h"

class ExprHandle
{
		friend ostream& operator << (ostream&, const ExprHandle&);
		
		Expr_node* p;
public:
	ExprHandle(int);
	ExprHandle(const string&, ExprHandle);
	ExprHandle(const string&, ExprHandle, ExprHandle);
	ExprHandle(const ExprHandle&);
	ExprHandle& operator=(const ExprHandle&);

	int Eval(void)const
	{
		return p->Eval();
	}

	~ExprHandle(void);

};

