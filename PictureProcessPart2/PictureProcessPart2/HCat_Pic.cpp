#include "stdafx.h"
#include "HCat_Pic.h"


HCat_Pic::HCat_Pic(const Picture& l, const Picture& r) : left(l), right(r)
{

}


HCat_Pic::~HCat_Pic(void)
{
}

Picture operator |( const Picture& l, const Picture& r)
{
	return new HCat_Pic(l, r);
}

int HCat_Pic::Height(void)const
{
	return Max(left.Height(), right.Height());
}

int HCat_Pic::Width(void) const
{
	return (left.Width() + right.Width());
}

static void Pad(ostream& os, int x, int y)
{
	for( int i = x; i < y; i++)
	{
		os << " ";
	}
}

void HCat_Pic::Display(ostream& os, int row, int wd) const
{
	left.Display(os, row, left.Width());
	right.Display(os, row, right.Width());
	Pad(os, Width(), wd);
}

Picture HCat_Pic::Reframe( char c, char s, char t)
{
	return new HCat_Pic(::Reframe(left, c, s, t), ::Reframe(left, c, s, t));
}