#pragma once
class Constant_iterator
{
public:
	Constant_iterator(int = 0);
	int operator*() const;

	Constant_iterator& operator++();
	Constant_iterator operator++(int);

	~Constant_iterator(void);

private:
	int n;
	int count;
	friend int operator==(const Constant_iterator&, const Constant_iterator&);
	friend int operator!=(const Constant_iterator&, const Constant_iterator&);
	friend Constant_iterator operator+(const Constant_iterator&, int);
	friend Constant_iterator operator+(int, const Constant_iterator&);


};

