#pragma once
template <class T> class Iterator
{
public:
	virtual int Valid() const = 0;
	virtual T Next() = 0;
	virtual ~Iterator(void)
	{
	}
};

