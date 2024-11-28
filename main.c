#include "SOH/SOH.h"
#include <stdio.h>

int main() {
    double initial_Impedance = 0.010; // 초기 임피던스, Ohms
    double impedance_Measurements[3] = {0.011, 0.012, 0.013}; // 구간별 임피던스 측정값, Ohms
    double weights[3] = {0.2, 0.6, 0.2}; // 각 구간별 가중치

    double soh = SOH_Impedance(initial_Impedance, impedance_Measurements, weights);
    printf("Impedence Based SOH: %.2f%%\n", soh);
    return 0;
}
