#pragma once
#include "Vehicle.h"

class VehicleSurrogate
{
public:
	VehicleSurrogate(void);
	VehicleSurrogate(const Vehicle&);
	~VehicleSurrogate(void);

	VehicleSurrogate(const VehicleSurrogate &);
	VehicleSurrogate& operator= (const VehicleSurrogate &);

	double Weight(void) const;
	void Start();

private:
	Vehicle* vp;
};

