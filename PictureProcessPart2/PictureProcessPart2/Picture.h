#pragma once
#include <ostream>
using namespace std;

class P_Node;

class Picture
{
	friend ostream& operator << (ostream&, const Picture&);
	friend Picture frame(const Picture&);
	friend Picture Reframe(const Picture& , char, char, char);
	friend Picture operator&(const Picture&, const Picture&);
	friend Picture operator|(const Picture&, const Picture&);
	friend class String_Pic;
	friend class Vcat_Pic;
	friend class HCat_Pic;
	friend class Frame_Pic;

public:
	Picture(P_Node *);
	Picture(const char* const *, int);
	Picture(const Picture&);
	~Picture(void);
	Picture& operator = (const Picture&);

private:
	P_Node* p;
	int Height(void) const;
	int Width(void) const;
	void Display(ostream&, int, int) const;
};

