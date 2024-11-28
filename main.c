#include "SOH/SOH.h"
#include <stdio.h>

int main() {
    double originalResistance = 0.005;  // 초기 저항값
    double currentResistances[3] = {0.0055, 0.006, 0.007};  // SOC 범위별 현재 저항값

    // 개선된 저항 기반 SOH 계산
    double soh = SOH_Resistance(originalResistance, currentResistances);

    printf("Resistance Based SOH : %.2f%%\n", soh);

    return 0;
}
