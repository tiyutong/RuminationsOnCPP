#pragma once
#include "Array_data.h"
#include "Array.h"

template<class T> class Ptr_to_const
{
public:
	//const Array&, 而不是Array&
	Ptr_to_const(const Array<T>& a, unsigned n = 0) :
		ap(a.data), sub(n)
	{
		++ap->use;
	}

	Ptr_to_const(void) : ap(0), sub(0)
	{
	}

	Ptr_to_const(const Ptr_to_const<T>& p) :
		ap(p.ap), sub(p.sub)
	{
		if(ap)
		{
			++ap->use;
		}
	}

	~Ptr_to_const(void)
	{
		if(ap && --ap->use == 0)
		{
			delete ap;
		}
	}

	Ptr_to_const& operator = (const Ptr_to_const<T>& p)
	{
		if(p.ap)
		{
			++ap->use;
		}
		if(ap && --ap->use == 0)
		{
			delete ap;
		}

		ap = p.ap;
		sub = p.sub;
		return *this;
	}

	//const T&, 而不是T&
	const T& operator*() const
	{
		if(ap == 0)
		{
			throw "* of unbound Ptr_to_const";
		}
		return (*ap)[sub];
	}

protected:
	Array_data<T>* ap;
	unsigned sub;
};

