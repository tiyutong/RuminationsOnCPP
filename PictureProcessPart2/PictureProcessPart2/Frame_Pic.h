#pragma once
#include "p_node.h"
#include "Picture.h"

class Frame_Pic :
	public P_Node
{
	friend Picture Frame(const Picture&);
public:
	Frame_Pic(const Picture&, char = '+',  char = '|',  char = '-');
	~Frame_Pic(void);
	int Height(void) const;
	int Width(void) const;
	void Display(ostream&, int, int) const;

	Picture Reframe(char, char ,char);
	Picture p;
	char corner;
	char sideBorder;
	char topBorder;
};

