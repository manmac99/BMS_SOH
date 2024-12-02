#include <stdio.h>
#include"SOH/SOH.h"

int main() {
    // 배터리 변수
    const double nominal_Capacity = 6.0;  // Ah, 배터리의 명목 전류 용량
    double remain_Capacity = 6.0;           // Ah, 초기 남은 배터리 용량
    double CC_CV_Based_SOH = 100.0;                       // 초기 SOH 100%
    double original_CV = 10.0; //초기 정전압

    // 시뮬레이션 변수
    double dischargeRate = 0.5;  // A, 배터리 방전 전류
    double chargeRate = 0.35;     // A, 배터리 충전 전류
    double charge_Time = 0.0;     // h, 정전압 충전에 걸린 시간
    double estimated_CV = 0.5;   // h, 전체 적산된 시간
        
    // 1시간 동안 방전
    discharge_Battery(&remain_Capacity, dischargeRate, 1.0);
    CC_CV_Based_SOH = SOH(nominal_Capacity, remain_Capacity);
    printf("Updated SOH: %.2f%%\n\n", CC_CV_Based_SOH);

    // 1시간 동안 충전
    charge_Battery(&remain_Capacity, &charge_Time,nominal_Capacity, chargeRate, 1.0);
    CC_CV_Based_SOH = SOH(nominal_Capacity, remain_Capacity);
    printf("Updated SOH: %.2f%%\n\n", CC_CV_Based_SOH);

    // SOH 보정
    adjust_SOH(&CC_CV_Based_SOH, Calc_CV(estimated_CV, original_CV));
    printf("Adjusted SOH after CV charge: %.2f%%\n", CC_CV_Based_SOH);

    return 0;
}
