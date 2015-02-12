#include "stdafx.h"
#include "Array_data.h"


template<class T>
void Array_data<T>::Copy(T* arr, unsigned n)
{
	for(int i = 0; i < n; i++)
	{
		data[i] = arr[i];
	}
}

template<class T>
void Array_data<T>::Grow(unsigned new_sz)
{
	unsigned nsz = sz;
	if(nsz == 0)
	{
		nsz = 1;
	}
	while (nsz <= new_sz)
	{
		nsz *= 2;
	}
	Resize(nsz);
}

template<class T>
void Array_data<T>:: Clone(const Array_data& a, unsigned n)
{
	delete data[];
	data = new T[sz = a.sz];
	Copy(a.data, sz);
}