#include "stdafx.h"
#include "String_Pic.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Picture.h"

String_Pic::String_Pic(const char* const* p, int n):
	data( new char* [n]), size(n)
{
	for(int i = 0; i < n; i++)
	{
		data[i] = new char[strlen(p[i]) + 1];
		strcpy_s(data[i], strlen(p[i]) + 1, p[i]);
	}
}


String_Pic::~String_Pic(void)
{
	for(int i = 0; i < size; i++)
	{
		delete[] data[i];
	}
	delete[] data;
}

int String_Pic::Height(void) const
{
	return size;
}

int String_Pic::Width(void) const
{
	int n = 0;
	for (int i = 0 ; i < size; i++)
	{
		n = Max(n, strlen(data[i]));
	}

	return n;
}

static void Pad(ostream& os, int x, int y)
{
	for( int i = x; i < y; i++)
	{
		os << " ";
	}
}

void String_Pic::Display(ostream& os, int row, int width) const
{
	int start = 0;
	if(row >= 0 && row < Height())
	{
		os << data[row];
		start = strlen(data[row]);
	}
	Pad(os, start, Width());
}

Picture String_Pic::Reframe(char, char, char)
{
	use++;
	return this;
}
