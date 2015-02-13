#pragma once
#include "Ptr_to_const.h"

//template<class T> Pointer<T> operator+ (const Pointer<T>& p, int n);
//template<class T> Pointer<T> operator+ ( int n, const Pointer<T>& p);
//template<class T> Pointer<T> operator-  (const Pointer<T>& p, int n);
//template<class T> Pointer<T> operator-  ( int n, const Pointer<T>& p);

template<class T> class Pointer :
	public Ptr_to_const<T>
{
	template<class T> friend Pointer<T> operator+ <T> (const Pointer<T>& p, int n);
	template<class T> friend Pointer<T> operator+ <T>( int n, const Pointer<T>& p);
	template<class T> friend Pointer<T> operator-  <T>(const Pointer<T>& p, int n);
	template<class T> friend Pointer<T> operator-  <T>( int n, const Pointer<T>& p);
	//friend Pointer<T> operator+  <T> (const Pointer<T>& p, int n);
	//friend Pointer<T> operator+ <T>( int n, const Pointer<T>& p);
	//friend Pointer<T> operator-  <T>(const Pointer<T>& p, int n);
	//friend Pointer<T> operator-  <T>( int n, const Pointer<T>& p);

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

	//«∞÷√++
	Pointer& operator++()
	{
		++sub;
		return *this;
	}
	
	Pointer& operator--()
	{
		--sub;
		return *this;
	}
	
	//∫Û÷√++
	Pointer operator++(int)
	{
		Pointer ret = *this;
		++sub;

		return ret;
	}

	Pointer operator--(int)
	{
		Pointer ret = *this;
		--sub;

		return ret;
	}
	
	Pointer& operator+=(int n)
	{
		sub += n;
		return *this;
	}

	Pointer& operator-=(int n)
	{
		sub -= n;
		return *this;
	}


};
	
	
		
template <class T>
Pointer<T> operator+ (const Pointer<T>& p, int n)
{
	Pointer<T> ret = p;
	return ret += n;
}

	
template <class T>
Pointer<T> operator+ ( int n, const Pointer<T>& p)
{
	Pointer<T> ret = p;
	return ret += n;
}

template <class T>
Pointer<T> operator- (const Pointer<T>& p, int n)
{
	Pointer<T> ret = p;
	return ret -= n;
}

template <class T>
Pointer<T> operator- ( int n, const Pointer<T>& p)
{
	Pointer<T> ret = p;
	return ret -= n;
}