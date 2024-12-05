#include<stdio.h>

double SOH_Capacity(double original_Capacity, double current_Capacity) {
    if (original_Capacity == 0) {
        return 100.0; // 원래 용량이 0이면, 계산 불가
    }
    double soh = (current_Capacity / original_Capacity) * 100.0;
    return soh;
}
