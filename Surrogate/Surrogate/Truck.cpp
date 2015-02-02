#include "stdafx.h"
#include "Truck.h"


Truck::Truck(void)
{
}


Truck::~Truck(void)
{
}

Vehicle* Truck::Copy(void) const
{
	return new Truck(*this);
}

void Truck::Start(void)
{
	printf("In Truck::Start(void)\n");
}

double Truck::Weight(void) const
{
	printf("In Truck::Weight(void)\n");
	return 0;
}