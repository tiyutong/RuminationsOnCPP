#pragma once
template <class T> class Array;
template <class T> class Pointer;

template<class T> class Array_data
{
	friend class Array<T>;
	friend class Pointer<T>;
public:
	Array_data(unsigned size = 0) :
		data(new T[size]), sz(size), use(1){ }
	~Array_data(void)
	{
		delete [] data;
	}

	const T& operator[](unsigned n)const
	{
		if( n >= sz)
		{
			throw "Array subscript out of range";
		}
		return data[n];
	}

	T& operator[](unsigned n)
	{
		if( n >= sz)
		{
			throw "Array subscript out of range";
		}
		return data[n];
	}

	void Resize(unsigned n)
	{
		if(n == sz)
		{
			return;
		}

		T* odata = data;
		data = new T[n];
		copy(odata, sz > n ? n : sz);
		delete[] odata;
		sz = n;
	}

	void Copy(T* arr, unsigned n);
	void Grow(unsigned new_sz);

	void Clone(const Array_data& a, unsigned n);

	//没有实现，不允许复制操作
	Array_data(const Array_data&);
	Array_data& operator = (const Array_data&);

	T* data;
	unsigned sz;
	int use;
};

