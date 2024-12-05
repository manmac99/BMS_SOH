#ifndef SOH_H
#define SOH_H

#include "SOH_CC_CV.c"
#include "SOH.c"

void discharge_Battery(double *remain_Capacity, double current, double hours);
void charge_Battery(double *remain_Capacity, double nominal_Capacity, double current, double hours);
double Calc_CV(double esitmated, double original);
void adjust_SOH(double *soh,  double calculated_CV);
double SOH(double original_Capacity, double current_Capacity);

#endif 
