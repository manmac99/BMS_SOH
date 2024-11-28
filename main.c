#include "SOH\SOH_Capacity.c"
#include"SOH\SOH_Resistance.c"
#include"SOH\SOH.c"
#include"SOH\SOH_Self_Discharge.c"
#include<stdio.h>

int main() {
    double originalCapacity = 100.0; // 배터리의 원래 용량 (예: 100 Ah)
    double currentMeasurements[] = {10.0, -5.0, 10.0, -5.0}; // 전류 측정값 (A), 충전과 방전
    int numMeasurements = sizeof(currentMeasurements) / sizeof(currentMeasurements[0]);
    double measurementInterval = 3600; // 측정 간격 (초), 예: 1시간

    double currentCapacity = Current_Capacity(originalCapacity, currentMeasurements, numMeasurements, measurementInterval);
    double soh = SOH(originalCapacity, currentCapacity);

    //저항 기반
    double originalResistance = 20; // 옴에서 측정
    double currentResistance = 21; // 옴에서 측정

    double currentCapacityByResistance = Current_Capacity_Resistance(originalResistance, currentResistance, originalCapacity);
    double sohByResistance = SOH(originalCapacity, currentCapacityByResistance);

    //자기 방전
    double measuredCapacityAfterPeriod = 98.0; // 일정 기간 후 측정된 용량, 예를 들어 98 Ah
    double expectedSelfDischargeRate = 5.0; // 새 배터리의 예상 자기방전율, 예를 들어 5%

    double self_discharge = SOH_Self_Discharge(originalCapacity, measuredCapacityAfterPeriod, expectedSelfDischargeRate);

    printf("SOH (Capacity-Based): %.2f%%\n", soh);
    printf("SOH (Resistance-Based): %.2f%%\n", currentCapacityByResistance);
    printf("The State of Health (SOH) based on self-discharge is: %.2f%%\n", self_discharge);

    return 0;
}
