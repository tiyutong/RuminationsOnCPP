#pragma once
#include "comp_base.h"
template<class F, class G, class X, class Y>
class Comp :
	public Comp_base<X, Y>
{
public:
	Comp(F f0, G g0) : f(f0), g(g0)
	{
	}
	
	Y operator()(X x) const
	{
		return f(g(x));
	}
	Comp_base<X, Y>* clone() const
	{
		return new Comp(*this);
	}

private:
	F f;
	G g;
};

