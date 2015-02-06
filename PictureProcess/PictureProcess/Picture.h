#pragma once
#include <ostream>
using namespace std;

class Picture
{
	friend ostream& operator << (ostream&, const Picture&);
	friend Picture frame(const Picture&);
	friend Picture operator&(const Picture&, const Picture&);
	friend Picture operator|(const Picture&, const Picture&);
public:
	Picture(void);
	Picture(const char* const *, int);
	Picture(const Picture&);
	~Picture(void);

	Picture& operator = (const Picture&);

private:
	int height, width;
	char * data;
	void CopyBlock(int, int, const Picture&);
	char& Position(int ,int);
	char Position(int, int)const;
	void Clear(int, int, int, int);
	void Init(int, int);
	static int Max(int, int);
};

