// Seq.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Seq.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Seq<int>* sp = new Seq<int>;
	*sp = Seq<int>(3, *sp);
	*sp = Seq<int>(4, *sp);
	*sp = Seq<int>(5, *sp);
	*sp = cons(6, *sp);
	sp->insert(7);

	int a = sp->hd();

	return 0;
}

