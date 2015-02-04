#pragma once
class Point
{
public:
	Point(void);
	~Point(void);

	Point(int x, int y);
	int X(void) const;
	int Y(void) const;

	Point& X(int);
	Point& Y(int);


private:
	int xVal;
	int yVal;
};

