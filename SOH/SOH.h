#ifndef SOH_H
#define SOH_H

#include "SOH_Impedance.c"
#include "SOH.c"

double SOH_Impedance(double initial_Impedance[], double impedance_Measurements[], double weights[]);
double SOH(double original_Capacity, double current_Capacity);

#endif 
