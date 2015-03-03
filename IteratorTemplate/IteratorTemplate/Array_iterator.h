#pragma once
#include "iterator.h"

template<class T> class Array_iterator :
	public Iterator<T>
{
public:
	Array_iterator(T* p, int c) : data(p), len(c)
	{
	}

	~Array_iterator(void)
	{
	}

	int Valid() const
	{
		return len > 0;
	}

	T Next()
	{
		--len;
		return *data++;
	}

private:
	T* data;
	int len;
};

