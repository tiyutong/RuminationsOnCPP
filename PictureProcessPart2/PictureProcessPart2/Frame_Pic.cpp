#include "stdafx.h"
#include "Frame_Pic.h"

Frame_Pic::Frame_Pic(const Picture& pic, char c, char s, char t): 
	p(pic), corner(c), sideBorder(s), topBorder(t)
{
}


Frame_Pic::~Frame_Pic(void)
{
}

Picture Frame(const Picture& pic)
{
	return new Frame_Pic(pic);
}

int Frame_Pic::Height(void)const
{
	return p.Height() + 2;
}

int Frame_Pic::Width(void) const
{
	return p.Width() + 2;
}


static void Pad(ostream& os, int x, int y)
{
	for( int i = x; i < y; i++)
	{
		os << " ";
	}
}


void Frame_Pic::Display(ostream& os, int row, int wd) const
{
	if(row < 0 ||  row > Height())
	{
		Pad(os, 0, wd);
	}
	else
	{
		if(row == 0 || row == Height() -1)
		{
			//顶部和底框
			os << corner;
			int i = p.Width();
			while(-- i >= 0)
			{
				os << topBorder;
			}
			os << corner;
		}
		else
		{
			//内部行
			os << sideBorder;
			p.Display(os, row - 1, p.Width());
			os << sideBorder;
		}
		Pad(os, Width(), wd);
	}
}

Picture Frame_Pic::Reframe(char c, char s, char t)
{
	return new Frame_Pic(::Reframe(p, c, s, t), c, s, t);
}
