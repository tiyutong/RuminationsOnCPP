#pragma once
#include "Array_data.h"

template <class T> class Pointer;
template <class T> class Ptr_to_const;

template <class T> class Array
{
	friend class Pointer<T>;
	friend class Ptr_to_const<T>;
public:
	Array(unsigned size) :
		data(new Array_data<T>(size)) {}
	
	Array(const Array& a) : data(new Array_data<T>(a.data->sz))
	{
		data->Copy(a.data, a.data->sz);
	}
	~Array(void)
	{
		if(--data->use == 0)
		{
			delete data;
		}
	}

	const T& operator[](unsigned n)const
	{
		return (*data)[n];
	}

	T& operator[](unsigned n)
	{
		return  (*data)[n];
	}

	void Resize(unsigned n)
	{
		data->Resize(n);
	}

	void Reserve(unsigned new_sz)
	{
		if(new_sz >= data->sz)
		{
			data->Grow(new_sz);
		}
	}

	
	Array& operator = (const Array& a)
	{
		if(this != &a)
		{
			data->Clone(*a.data, a.data->sz);
		}

		return *this;
	}
private:
	Array_data<T>* data;
};

