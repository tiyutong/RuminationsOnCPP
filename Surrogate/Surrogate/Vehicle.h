#pragma once
class Vehicle
{
public:
	Vehicle(void);
	virtual ~Vehicle(void);

	virtual double Weight(void) const = 0;
	virtual void Start(void) = 0;
	virtual Vehicle* Copy(void) const  = 0;
};

