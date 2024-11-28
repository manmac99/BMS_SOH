#ifndef SOH_H
#define SOH_H

#include "SOH_Recovery.c"
#include "SOH.c"

double SOH_Recovery(double V_recovered, double V_loaded, double V_nominal);
double SOH(double original_Capacity, double current_Capacity);

#endif 
