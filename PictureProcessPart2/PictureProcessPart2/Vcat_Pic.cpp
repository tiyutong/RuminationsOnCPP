#include "stdafx.h"
#include "Vcat_Pic.h"
#include "Picture.h"


Vcat_Pic::Vcat_Pic(const Picture& t, const Picture& b) : bottom(b), top(t)
{
}


Vcat_Pic::~Vcat_Pic(void)
{
}

Picture operator &( const Picture& b, const Picture& t)
{
	return new Vcat_Pic(b, t);
}

int Vcat_Pic::Height(void) const
{
	return top.Height() + bottom.Height();
}

int Vcat_Pic::Width(void) const
{
	return Max(top.Width(), bottom.Width());
}

static void Pad(ostream& os, int x, int y)
{
	for( int i = x; i < y; i++)
	{
		os << " ";
	}
}

void Vcat_Pic::Display(ostream& os, int row, int wd) const
{
	//上半部分
	if(row >= 0 && row < top.Height())
	{
		top.Display(os, row, wd);
	}
	else if(row < top.Height() + bottom.Height()) //下半部分
	{
		bottom.Display(os, row - top.Height(), wd);
	}
	else
	{
		Pad(os ,0 , wd);
	}
}

Picture Vcat_Pic::Reframe(char c, char s, char t)
{
	return new Vcat_Pic(
		::Reframe(top, c, s, t),
		::Reframe(bottom, c, s, t));
}
