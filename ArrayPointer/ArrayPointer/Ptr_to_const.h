#pragma once
#include "Array_data.h"
#include "Array.h"

template<class T> class Ptr_to_const
{
	template<class T> friend int operator- (const Ptr_to_const<T>& op1, const Ptr_to_const<T>& op2);

	template<class T> friend Ptr_to_const<T> operator+ (const Ptr_to_const<T>& p, int n);
	template<class T> friend Ptr_to_const<T> operator+ ( int n, const Ptr_to_const<T>& p);
	template<class T> friend Ptr_to_const<T> operator- (const Ptr_to_const<T>& p, int n);
	template<class T> friend Ptr_to_const<T> operator- ( int n, const Ptr_to_const<T>& p);

	template<class T> friend int operator==(const Ptr_to_const<T>& op1, const Ptr_to_const<T>& op2);
	template<class T> friend int operator!=(const Ptr_to_const<T>& op1, const Ptr_to_const<T>& op2);
	template<class T> friend int operator>=(const Ptr_to_const<T>& op1, const Ptr_to_const<T>& op2);
	template<class T> friend int operator<=(const Ptr_to_const<T>& op1, const Ptr_to_const<T>& op2);
	template<class T> friend int operator>(const Ptr_to_const<T>& op1, const Ptr_to_const<T>& op2);
	template<class T> friend int operator<(const Ptr_to_const<T>& op1, const Ptr_to_const<T>& op2);
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

	//前置++
	Ptr_to_const& operator++()
	{
		++sub;
		return *this;
	}
	
	Ptr_to_const& operator--()
	{
		--sub;
		return *this;
	}
	
	//后置++
	Ptr_to_const operator++(int)
	{
		Ptr_to_const ret = *this;
		++sub;

		return ret;
	}

	Ptr_to_const operator--(int)
	{
		Ptr_to_const ret = *this;
		--sub;

		return ret;
	}
	
	Ptr_to_const& operator+=(int n)
	{
		sub += n;
		return *this;
	}

	Ptr_to_const& operator-=(int n)
	{
		sub -= n;
		return *this;
	}

protected:
	Array_data<T>* ap;
	unsigned sub;
};


//指针相减
template <class T>int operator-
	(const Ptr_to_const<T>& op1, const Ptr_to_const<T>& op2)
{
	return (int)op1.sub - (int)op2.sub;
}

template <class T>
Ptr_to_const<T> operator+ (const Ptr_to_const<T>& p, int n)
{
	Ptr_to_const<T> ret = p;
	return ret += n;
}

template <class T>
Ptr_to_const<T> operator+ ( int n, const Ptr_to_const<T>& p)
{
	Ptr_to_const<T> ret = p;
	return ret += n;
}

template <class T>
Ptr_to_const<T> operator- (const Ptr_to_const<T>& p, int n)
{
	Ptr_to_const<T> ret = p;
	return ret -= n;
}

template <class T>
Ptr_to_const<T> operator- ( int n, const Ptr_to_const<T>& p)
{
	Ptr_to_const<T> ret = p;
	return ret -= n;
}

template <class T>int operator==
	(const Ptr_to_const<T>& op1, const Ptr_to_const<T>& op2)
{
	if(op1.ap != op2.ap)
	{
		return 0;
	}
	return (op1.sub == op2.sub);
}

template <class T>int operator!=
	(const Ptr_to_const<T>& op1, const Ptr_to_const<T>& op2)
{
	if(op1.ap != op2.ap)
	{
		return 1;
	}
	return (op1.sub != op2.sub);
}

template <class T>int operator>=
	(const Ptr_to_const<T>& op1, const Ptr_to_const<T>& op2)
{
	if(op1.ap != op2.ap)
	{
		throw ">= on different Arrays";
	}
	return (op1.sub >= op2.sub);
}

template <class T>int operator<=
	(const Ptr_to_const<T>& op1, const Ptr_to_const<T>& op2)
{
	if(op1.ap != op2.ap)
	{
		throw "<= on different Arrays";
	}
	return (op1.sub <= op2.sub);
}

template <class T>int operator>
	(const Ptr_to_const<T>& op1, const Ptr_to_const<T>& op2)
{
	if(op1.ap != op2.ap)
	{
		throw "> on different Arrays";
	}
	return (op1.sub > op2.sub);
}

template <class T>int operator<
	(const Ptr_to_const<T>& op1, const Ptr_to_const<T>& op2)
{
	if(op1.ap != op2.ap)
	{
		throw "< on different Arrays";
	}
	return (op1.sub < op2.sub);
}