#pragma once
#include "P_Node.h"
#include "Frame_Pic.h"

class String_Pic
	: public P_Node
{
	friend class Picture;
public:
	String_Pic(const char* const *, int );
	~String_Pic(void);
	int Height(void) const;
	int Width(void) const;
	void Display(ostream&, int, int) const;
	Picture String_Pic::Reframe(char, char, char);

	char** data;
	int size;
};

