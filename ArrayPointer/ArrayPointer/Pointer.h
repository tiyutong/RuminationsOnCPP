#pragma once
#include "Ptr_to_const.h"

template<class T> class Pointer :
	public Ptr_to_const<T>
{
public:
	Pointer(Array<T>& a, unsigned n = 0) :
		Ptr_to_const(a, n)
	{
	}
	Pointer(void)
	{

	}

	T& operator*() const
	{
		if(ap == 0)
		{
			throw "* of unbound Ptr_to_const";
		}
		return (*ap)[sub];
	}
};

