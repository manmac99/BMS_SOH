#ifndef SOH_H
#define SOH_H

#include "SOH_Capacity.c"
#include "SOH.c"

double SOH_Capacity(double original_Capacity, double charged_Data[]);
double SOH(double original_Capacity, double current_Capacity);

#endif 
