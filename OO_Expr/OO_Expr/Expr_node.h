#pragma once
#include <ostream>
using namespace std;
//#include "ExprHandle.h"

class ExprHandle;

class Expr_node
{
	friend ostream& operator << (ostream&, const ExprHandle&);
	friend class ExprHandle;

	int use;

protected:
	Expr_node(void) : use(1)
	{
	}
	virtual void print(ostream& ) const = 0;
	virtual ~Expr_node(void);

	virtual int Eval(void) const = 0;
};

