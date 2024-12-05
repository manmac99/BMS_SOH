#include <stdio.h>
#include"SOH/SOH.h"

int main() {
    // 배터리 변수
    const double nominal_Capacity = 385.0;  // Ah, 배터리의 명목 전류 용량
    double remain_Capacity = 385.0; // Ah, 초기 남은 배터리 용량
    double CC_CV_Based_SOH = 100.0; // 초기 SOH 100%
    double original_CV_Period = 10.0; //정전압이 유지되는 시간, 초기값


    // 시뮬레이션 변수
    double discharge_Rate = 12; // A, 배터리 방전 전류
    double charge_Rate = 9.06; // A, 배터리 충전 전류, 시간이 지난 후.
    double estimated_CV_Period = 9.54; //측정된 정전압이 유지되는 시간
    const double charge_per_hour = 10; // 1시간당 충전되는 배터리 전류, 배터리 초기 설정값
        
    // 1시간 동안 방전
    discharge_Battery(&remain_Capacity, discharge_Rate, 1.0);
    printf("Discharged SOC: %.2f%%\n\n", SOH(nominal_Capacity, remain_Capacity));

    // 1시간 동안 충전 후 SOH계산
    double prev_Capacity = remain_Capacity+charge_per_hour; //정상적으로 1시간 충전이 되었다면 나올 Capacity
    charge_Battery(&remain_Capacity,nominal_Capacity, charge_Rate, 1.0); 
    double updated_Capacity = remain_Capacity; //현재 충전량으로 계산된 Capacity

    printf("Discharged SOC: %.2f%%\n\n", SOH(nominal_Capacity, remain_Capacity));
    CC_CV_Based_SOH = (1 - (prev_Capacity-updated_Capacity)/updated_Capacity)*100;

    printf("First esimated SOH: %.2f%%\n\n", CC_CV_Based_SOH);

    //정전압이 돌아온 시간을 기준으로 다시 한번 계산
    adjust_SOH(&CC_CV_Based_SOH, Calc_CV(estimated_CV_Period, original_CV_Period));
    printf("Adjusted SOH after CV charge: %.2f%%\n", CC_CV_Based_SOH);

    return 0;
}
