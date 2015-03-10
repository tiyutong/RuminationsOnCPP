#pragma once

template<class It, class T> 
class Rev
{
	template<class It, class T> friend bool operator==(const Rev<It, T>&, const Rev<It, T>&);
	template<class It, class T> friend bool operator!=(const Rev<It, T>&, const Rev<It, T>&);

public:
	Rev(void)
	{
	}

	Rev(It i) : it(i) { }
	operator It() { return it; }
	~Rev(void)
	{
	}

	//将参数迭代器反向
	Rev<It,T>& operator++()
	{
		--it;
		return *this;
	}

	Rev<It,T>& operator--()
	{
		++it;
		return *this;
	}

	Rev<It,T>& operator++(int)
	{
		Rev<It, T> r = *this;
		--it;
		return r;
	}

	Rev<It,T>& operator--(int)
	{
		Rev<It, T> r = *this;
		++it;
		return r;
	}

	T& operator*()
	{
		It i = it;
		--i;
		return *i;
	}


private:
	It it;
};

template<class It, class T>
bool operator==(const Rev<It, T>& x, const Rev<It, T>& y)
{
	return x.it == y.it;
}

template<class It, class T>
bool operator!=(const Rev<It, T>& x, const Rev<It, T>& y)
{
	return x.it != y.it;
}