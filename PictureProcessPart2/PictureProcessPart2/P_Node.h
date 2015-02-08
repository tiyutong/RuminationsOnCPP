#pragma once
#include <ostream>
using namespace std;

class P_Node
{
	friend class Picture;
	friend Picture Reframe(const Picture& pic,char, char, char);

protected:
	P_Node(void);
	virtual ~P_Node(void);
	virtual int Height(void) const = 0;
	virtual int Width(void) const = 0;
	virtual void Display(ostream&, int, int) const = 0;
	virtual Picture Reframe(char, char, char) = 0;

	static int Max(int , int );
//private: 
	int use;
};

