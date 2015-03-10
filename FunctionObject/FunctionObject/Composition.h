#pragma once
#include "Comp_base.h"
#include "Comp.h"

template<class X, class Y>
class Composition
{
public:
	template<class F, class G>Composition(F, G);
	Composition(const Composition&);
	Composition& operator=(const Composition&);
	~Composition(void);
	Y operator()(X)const;

private:
	Comp_base<X, Y>* p;
};

template<class X, class Y>
	template<class F, class G>
Composition<X, Y>::Composition(F f, G g): p(new Comp<F, G, X ,Y>(f,g))
{
}

template<class X, class Y>
Composition<X, Y>::~Composition()
{
	delete p;
}

template<class X, class Y>
Composition<X, Y>::Composition(const Composition& c) : p(c.p->clone())
{
}

template<class X, class Y>
Composition<X, Y>& Composition<X, Y>::operator=(const Composition&)
{
	if(this != &c)
	{
		delete p;
		p = c.p->clone();
	}
	return *this;
}

template<class X, class Y>
Y Composition<X, Y>::operator()(X x) const
{
	return (*p)(x);
}