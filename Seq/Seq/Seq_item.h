#pragma once

template <class T> class Seq_item
{
	template<class T> friend class Seq;

	int use;
	const T data;
	Seq_item* next;

public:
	Seq_item(const T& t, Seq_item* s);
	Seq_item(const T& t);  
	~Seq_item(void)
	{
	}
};

template <class T> 
Seq_item<T>::Seq_item(const T& t, Seq_item<T> *s) : 
	use(1),data(t),next(s)
{
	if(s)
	{
		s->use++;
	}
}

template <typename T>  
Seq_item<T>::Seq_item(const T& t):
	use(1), data(t), next(0) { }  
