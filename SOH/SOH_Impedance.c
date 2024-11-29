#include <stdio.h>

double SOH_Impedance(double initial_Impedance, double impedance_Measurements[]) {
    if(initial_Impedance == 0) {
        return 0;  // 초기 저항이 0이면 계산 불가
    }

    double Sum = 0.0;
    double weight_Sum = 0.0;
    double weights[] = {0.2, 0.6, 0.2}; // SOC 범위 1-20, 21-80, 81-100에 대한 가중치

    for (int i = 0; i < 3 ; ++i) {
        Sum += ((impedance_Measurements[i] - initial_Impedance) / initial_Impedance) * weights[i];
        weight_Sum += weights[i];
    }

    double current_SOH = (1 - Sum / weight_Sum) * 100;

    if (current_SOH < 0) {
        current_SOH = 0;
    }

    return current_SOH;
}