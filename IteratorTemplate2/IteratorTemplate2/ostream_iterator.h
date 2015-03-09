#pragma once
#include <ostream>
using namespace std;
template<class T>
class ostream_iterator
{
public:
	ostream_iterator(ostream& os, const char* s) :
		strm(&os), str(s){}

	ostream_iterator& operator++()
	{
		return *this;
	}
	ostream_iterator& operator++(int)
	{
		return *this;
	}
	ostream_iterator& operator*() 
	{
		return *this;
	}

	ostream_iterator& operator=(const T& t)
	{
		*strm << t << str;
		return *this;
	}

	template<class T> friend int operator==(const ostream_iterator<T>& p, const ostream_iterator<T>& q);

	template<class T> friend int operator!=(const ostream_iterator<T>& p, const ostream_iterator<T>& q);

	~ostream_iterator(void)
	{
	}

private:
	ostream* strm;
	const char* str;
};

template<class T>
int operator == (const ostream_iterator<T>& p, const ostream_iterator<T>& q)
{
	return *(p.strm) == *(q.strm) && *(p.str) == *(q.str);
}

template<class T>
int operator != (const ostream_iterator<T>& p, const ostream_iterator<T>& q)
{
	return !(p == q);
}