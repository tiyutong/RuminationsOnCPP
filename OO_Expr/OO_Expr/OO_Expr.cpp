// OO_Expr.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "ExprHandle.h"
#include < iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ExprHandle t = ExprHandle("*", ExprHandle( "-", 5), ExprHandle("+", 3, 4)) ;

	cout << t << " = " << t.Eval() << endl;
	 t = ExprHandle("*", t ,t);
	cout << t << " = " << t.Eval() << endl;
	return 0;
}

