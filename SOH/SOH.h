#ifndef SOH_H
#define SOH_H
#include "SOH_Capacity.c"
#include "SOH_Resistance.c"
#include "SOH_Self_Discharge.c"
#include "SOH.c"

double Current_Capacity(double original_Capacity, double *currentMeasurements, int numMeasurements, double measurementInterval);
double Current_Capacity_Resistance(double originalResistance, double currentResistance, double originalCapacity);
double SOH_Self_Discharge(double initialCapacity, double measuredCapacityAfterPeriod, double expectedSelfDischargeRate);
double SOH(double original_Capacity, double current_Capacity);

#endif 