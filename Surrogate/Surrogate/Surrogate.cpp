// Surrogate.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Truck.h"
#include "Vehicle.h"
#include "VehicleSurrogate.h"

int _tmain(int argc, _TCHAR* argv[])
{
	VehicleSurrogate parkingLot[1000];
	int numVehicles = 0;
	Truck t;
	parkingLot[numVehicles++] = t;

	for(int i = 0;i < 10 ;i++ )
	{
		parkingLot[i].Weight();
		parkingLot[i].Start();
	}
	return 0;
}

