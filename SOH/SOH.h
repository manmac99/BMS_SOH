#ifndef SOH_H
#define SOH_H

#include "SOH_Capacity.c"
#include "SOH_Resistance.c"
#include "SOH_Self_Discharge.c"
#include "SOH.c"

double SOH_Capacity(double original_Capacity, double charged_Data[]);
double SOH_Resistance(double original_Resistance, double current_Resistance[]);
double SOH_Self_Discharge(double initialCapacity, double measuredCapacityAfterPeriod, double expectedSelfDischargeRate);
double SOH(double original_Capacity, double current_Capacity);

#endif 
