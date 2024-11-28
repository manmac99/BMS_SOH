#include <stdio.h>

// SOC 범위에 따른 저항값을 받아 이를 통합하여 SOH를 계산하는 함수
double SOH_Resistance(double original_Resistance, double current_Resistance[]) {
    if (original_Resistance == 0) {
        return 0;  // 초기 저항이 0이면 계산 불가
    }

    double Sum = 0.0;
    double weight_Sum = 0.0;
    double weights[] = {0.2, 0.6, 0.2}; // SOC 범위 1-20, 21-80, 81-100에 대한 가중치

    for (int i = 0; i < 3; ++i) {
        Sum += ((current_Resistance[i] - original_Resistance) / original_Resistance) * weights[i];
        weight_Sum += weights[i];
    }

    double average_Degradation = Sum / weight_Sum;
    double current_SOH = (1 - average_Degradation) * 100;

    if (current_SOH < 0) {
        current_SOH = 0;
    }

    return current_SOH;
}
