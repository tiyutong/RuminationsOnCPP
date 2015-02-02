#pragma once
#include "vehicle.h"
class Truck :
	public Vehicle
{
public:
	Truck(void);
	~Truck(void);

	double Weight(void) const;
	void Start(void);
	Vehicle* Copy(void) const;
};

