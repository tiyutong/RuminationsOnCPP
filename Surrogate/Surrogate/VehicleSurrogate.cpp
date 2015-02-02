#include "stdafx.h"
#include "VehicleSurrogate.h"


VehicleSurrogate::VehicleSurrogate(void) : vp(0)
{

}

VehicleSurrogate::VehicleSurrogate(const Vehicle& v) : vp(v.Copy())
{
}

VehicleSurrogate::~VehicleSurrogate(void)
{
	delete vp;
}

VehicleSurrogate::VehicleSurrogate(const VehicleSurrogate& v) : vp(v.vp ? v.vp->Copy() : 0)
{

}

VehicleSurrogate& VehicleSurrogate::operator= (const VehicleSurrogate& v)
{
	if(this != &v)
	{
		delete vp;
		vp = (v.vp ? v.vp->Copy() : 0);
	}
	return *this;
}

double VehicleSurrogate::Weight() const
{
	if(vp == 0)
	{
		printf("empty VehicleSurrogate.Weight()\n");
	}
	else
	{
		return vp->Weight();
	}
}

void VehicleSurrogate::Start(void)
{
	if(vp == 0)
	{
		printf("empty VehicleSurrogate.Start()\n");
	}
	else
	{
		vp->Start();
	}
}