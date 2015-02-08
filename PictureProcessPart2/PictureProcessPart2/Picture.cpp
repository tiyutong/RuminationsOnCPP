#include "stdafx.h"
#include "Picture.h"
#include "String_Pic.h"

Picture::Picture(P_Node* p_node) : p(p_node)
{

}

Picture::Picture(const char* const* str, int n) :
	p(new String_Pic(str, n))
{
}

Picture::Picture(const Picture& orig) : p(orig.p)
{
	orig.p->use++;
}

Picture::~Picture(void)
{
	if(--p->use == 0)
	{
		delete p;
	}
}

Picture frame(const Picture& pic)
{
	return new Frame_Pic(pic);
}


Picture& Picture:: operator= (const Picture& orig)
{
	orig.p->use++;
	if(--p->use == 0)
	{
		delete p;
		p = orig.p;
	}
	return *this;
}

int Picture::Height(void)const
{
	return p->Height();
}

int Picture::Width(void) const
{
	return p->Width();
}

void Picture::Display(ostream& o, int x, int y) const
{
	p->Display(o, x, y);
}

ostream& operator << (ostream& os, const Picture& picture)
{
	int ht = picture.Height();

	for(int i = 0; i < ht; i++)
	{
		picture.Display(os,i,0);
		os <<endl;
	}
	return os;

}

Picture Reframe(const Picture& pic, char c, char s, char t)
{
	return pic.p->Reframe(c, s, t);
}