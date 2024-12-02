#include <stdio.h>

void discharge_Battery(double *remain_Capacity, double current, double hours) {
    double discharged = current * hours;
    if (*remain_Capacity > discharged) {
        *remain_Capacity -= discharged;
        printf("Discharged: %.2fAh, Remaining Capacity: %.2fAh\n", discharged, remain_Capacity);
    } else {
        printf("Battery fully discharged.\n");
        remain_Capacity = 0;
    }
}

void charge_Battery(double *remain_Capacity, double *charge_Time, double nominal_Capacity, double current, double hours) {
    double charged = current * hours;
    if (*remain_Capacity + charged <= nominal_Capacity) {
        *remain_Capacity += charged;
        printf("Charged: %.2fAh, Remaining Capacity: %.2fAh\n", charged, *remain_Capacity);
    } else {
        printf("Battery fully charged.\n");
        *remain_Capacity = nominal_Capacity;
    }
    *charge_Time += hours;  // 정전압 충전 시간을 충전 시간으로 간주
}

double Calc_CV(double esitmated_CV, double original_CV){
    return 1-(original_CV-esitmated_CV)/original_CV;
}

void adjust_SOH(double *soh,  double calculated_CV) {
    // 정전압 충전 시간에 따른 SOH 감소를 조정
    *soh -=  calculated_CV; 
    if (*soh < 0) *soh = 0;
    else if(*soh >=100) *soh = 100.0;
}