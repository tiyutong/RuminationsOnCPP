#pragma once
#include <istream>
using namespace std;

template<class T> class Reader
{
public:
	Reader(istream& is) : i(is) 
	{
		Advance();
	}

	int Valid() const
	{
		return status;
	}

	T Next()
	{
		T result = data;
		Advance();
		return result;
	}

	~Reader()
	{
	}

private:
	istream& i;
	int status;
	T data;

	void Advance()
	{
		i >> data;
		status = i != 0;
	}
};

