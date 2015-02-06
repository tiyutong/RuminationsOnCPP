#include "stdafx.h"
#include "Picture.h"


Picture::Picture(void) : height(0), width(0), data(0)
{
}

Picture::Picture(const char* const* array, int n)
{
	int w = 0;
	int i = 0;

	for(i = 0; i < n; i++)
	{
		w = Picture::Max(w, strlen(array[i]));
	}

	Init(n, w);

	for(i = 0; i < n; i++)
	{
		const char* src = array[i];
		int len = strlen(src);
		int j = 0;
		
		while(j < len)
		{
			Position(i, j) = src[j];
			++j;
		}
		while(j < width)
		{
			Position(i, j) = ' ';
			++j;
		}

	}
}

Picture::Picture(const Picture& p) :
	height(p.height), width(p.width),
	data(new char[p.height * p.width])
{
	CopyBlock(0, 0, p);
}

Picture& Picture:: operator= (const Picture& p)
{
	if(this != &p)
	{
		delete[] data;
		Init(p.height, p.width);
		CopyBlock(0, 0, p);
	}
	return *this;
}

ostream& operator<<(ostream& o, const Picture& p)
{
	for(int i = 0; i < p.height; ++i)
	{
		for(int j = 0; j < p.width; ++j)
		{
			o << p.Position(i, j);
		}
		o << endl;
	}
	return o;
}

Picture operator& (const Picture& p, const Picture& q)
{
	Picture r;
	r.Init(p.height + q.height, Picture::Max(p.width, q.width));

	r.Clear(0, p.width, p.height, r.width);
	r.Clear(p.height, p.width, r.height, r.width);

	r.CopyBlock(0, 0, p);
	r.CopyBlock(p.height, 0, q);

	return r;
}

Picture operator| (const Picture& p, const Picture& q)
{
	Picture r;
	r.Init(Picture::Max(p.height, q.height),p.width + q.width );

	r.Clear(p.height, 0, r.height, r.width);
	r.Clear(q.height, p.width, r.height, r.width);

	r.CopyBlock(0, 0, p);
	r.CopyBlock(0, p.width, q);

	return r;
}

char& Picture::Position(int row, int col)
{
	return data[row * width + col];
}

char Picture::Position(int row, int col) const
{
	return data[row * width + col];
}

void Picture::CopyBlock(int row, int col, const Picture& p)
{
	for(int i = 0; i < p.height; ++i)
	{
		for(int j = 0; j < p.width; ++j)
		{
			Position(i + row, j + col) = p.Position(i, j);
		}
	}
}

Picture frame(const Picture& p)
{
	Picture r;

	r.Init(p.height + 2, p.width +2);

	for(int i = 1; i < r.height - 1; i++)
	{
		r.Position(i, 0) = '|';
		r.Position(i, r.width - 1) = '|';
	}

	for(int j = 1; j < r.width; j++)
	{
		r.Position(0, j) = '|';
		r.Position(r.height - 1, j) = '|';
	}

	r.Position(0, 0) = '+';
	r.Position(0, r.width - 1)  = '+';
	r.Position(r.height - 1, 0)  = '+';
	r.Position(r.height - 1, r.width - 1)  = '+';

	r.CopyBlock( 1, 1, p);
	return r;

}

int Picture::Max(int m, int n)
{
	return m > n ? m : n;
}

void Picture::Init(int h, int w)
{
	height = h;
	width = w;
	data = new char[height * width];
}

void Picture::Clear(int r1, int c1, int r2, int c2)
{
	for(int r = r1; r < r2; ++r)
	{
		for(int c = c1; c < c2; ++c)
		{
			Position(r, c) = ' ';
		}
	}
}

Picture::~Picture(void)
{
	delete [] data;
}
