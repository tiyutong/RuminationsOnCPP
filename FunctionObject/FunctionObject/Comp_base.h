#pragma once
template<class X, class Y>
class Comp_base
{
public:
	virtual Y operator()(X) const = 0;
	virtual Comp_base* clone() const = 0;
	virtual ~Comp_base(void){ }
};

