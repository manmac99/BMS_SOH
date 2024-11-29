#include <stdio.h>

double SOH_Impedance(double initial_Impedance, double impedance_Measurements[]) {
    double Sum = 0.0;
    double total_Weight = 0.0;
    double weights[] = {0.2, 0.6, 0.2}; // SOC 범위 1-20, 21-80, 81-100에 대한 가중치

    for (int i = 0; i < 3 ; ++i) {
        Sum += ((impedance_Measurements[i] - initial_Impedance) / initial_Impedance) * weights[i];
        total_Weight += weights[i];
    }

    double soh = (1.0 - Sum / total_Weight) * 100;

    if (soh < 0) soh = 0;  // 보정: SOH가 0보다 작으면 0으로 설정
    return soh;
}