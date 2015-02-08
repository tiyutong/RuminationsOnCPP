#pragma once
#include "P_Node.h"
#include "Picture.h"

class HCat_Pic
	: public P_Node
{
	friend Picture operator |(const Picture&, const Picture& );

public:
	HCat_Pic(const Picture&, const Picture& );
	~HCat_Pic(void);
	int Height(void) const;
	int Width(void) const;
	void Display(ostream&, int, int) const;
	Picture Reframe(char, char ,char);;

	Picture left, right;
};

