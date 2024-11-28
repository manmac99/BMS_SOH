#include "SOH\SOH_Capacity.c"
#include"SOH\SOH_Resistance.c"
#include"SOH\SOH.c"
#include<stdio.h>

int main() {
    double originalCapacity = 100.0; // 배터리의 원래 용량 (예: 100 Ah)
    double currentMeasurements[] = {10.0, -5.0, 10.0, -5.0}; // 전류 측정값 (A), 충전과 방전
    int numMeasurements = sizeof(currentMeasurements) / sizeof(currentMeasurements[0]);
    double measurementInterval = 3600; // 측정 간격 (초), 예: 1시간

    double currentCapacity = Current_Capacity(originalCapacity, currentMeasurements, numMeasurements, measurementInterval);
    double soh = SOH(originalCapacity, currentCapacity);

    double originalResistance = 20; // 옴에서 측정
    double currentResistance = 21; // 옴에서 측정

    double currentCapacityByResistance = Current_Capacity_Resistance(originalResistance, currentResistance, originalCapacity);
    double sohByResistance = SOH(originalCapacity, currentCapacityByResistance);

    printf("SOH (Capacity-Based): %.2f%%\n", soh);
    printf("SOH (Resistance-Based): %.2f%%\n", currentCapacityByResistance*100);

    return 0;
}
