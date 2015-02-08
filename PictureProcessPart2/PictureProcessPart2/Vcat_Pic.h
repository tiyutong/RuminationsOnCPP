#pragma once
#include "P_Node.h"
#include "Picture.h"

class Vcat_Pic
	: public P_Node
{
	friend Picture operator &(const Picture&, const Picture& );

public:
	Vcat_Pic(const Picture&, const Picture& );
	~Vcat_Pic(void);
	int Height(void) const;
	int Width(void) const;
	void Display(ostream&, int, int) const;
	Picture Reframe(char, char ,char);

	Picture top, bottom;
};

