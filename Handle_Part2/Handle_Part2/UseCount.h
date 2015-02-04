#pragma once
class UseCount
{
public:
	UseCount(void);
	UseCount(const UseCount&);
	~UseCount(void);

	bool Reattach(const UseCount&);
	bool MakeOnly(void);
	bool Only(void);

private:
	int* p;
	UseCount& operator = (const UseCount&);
};

