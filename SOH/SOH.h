#ifndef SOH_H
#define SOH_H

#include "SOH_Capacity.c"
#include "SOH_Resistance.c"
#include "SOH_Impedance.c"
#include "SOH_Cycle.c"
#include "SOH_Recovery.c"
//#include "SOH_Self_Discharge.c"
#include "SOH_CC_CV.c"
#include "SOH.c"

double SOH_Capacity(double original_Capacity, double current_Capacity);
double SOH_Resistance(double original_Resistance[], double current_Resistance[]);
double SOH_Impedance(double initial_Impedance[], double impedance_Measurements[], double weights[]);
double SOH_Cycle(int max_Cycles, int current_Cycles);
double SOH_Recovery(double V_recovered, double V_loaded, double V_nominal);
//double SOH_Self_Discharge(double initialCapacity, double measuredCapacityAfterPeriod, double expectedSelfDischargeRate);
void discharge_Battery(double *remain_Capacity, double current, double hours);
void charge_Battery(double *remain_Capacity, double nominal_Capacity, double current, double hours);
double Calc_CV(double esitmated, double original);
void adjust_SOH(double *soh,  double calculated_CV);
double SOH(double original_Capacity, double current_Capacity);

#endif 
