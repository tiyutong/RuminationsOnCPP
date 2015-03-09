#pragma once
#include <istream>
#include "assert.h"
using namespace std;

template<class T>
class istream_iterator
{
	template<class T> friend int operator==(istream_iterator<T>&p, istream_iterator<T>& q);
	template<class T> friend int operator!=(istream_iterator<T>&p, istream_iterator<T>& q);
public:
	istream_iterator(istream& is) :
		strm(&is), full(0), eof(0){}

	istream_iterator():
		strm(0), full(0), eof(1){}
	~istream_iterator(void)
	{
	}

	istream_iterator& operator++()
	{
		full = 0;
		return *this;
	}

	istream_iterator operator++(int)
	{
		istream_iterator r = *this;
		full = 0;
		return r;
	}

	T operator*()
	{
		fill();
		assert(full);
		return buffer;
	}


private:
	T buffer;
	istream* strm;
	int full;
	int eof;

	void fill()
	{
		if(!full && !eof)
		{
			if(*strm >> buffer)
			{
				full = 1;
			}
			else
			{
				eof = 1;
			}
		}
	}
};

template<class T>
int operator==(istream_iterator<T>& p, istream_iterator<T>& q)
{
	if(p.eof && q.eof)
	{
		return 1;
	}

	if(!p.eof && !q.eof)
	{
		return &p == &q;
	}
	q.fill();
	q.fill();
	return p.eof == q.eof;
}

template<class T>
int operator!=(istream_iterator<T>& p, istream_iterator<T>& q)
{
	return !(p == q);
}

