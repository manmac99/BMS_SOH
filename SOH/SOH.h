#ifndef SOH_H
#define SOH_H

#include "SOH_Resistance.c"
#include "SOH.c"

double SOH_Resistance(double original_Resistance[], double current_Resistance[]);
double SOH(double original_Capacity, double current_Capacity);

#endif 
