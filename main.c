#include <stdio.h>

// 배터리 관련 상수
const float nominalTotalCapacity = 6.0;  // Ah, 배터리의 명목 전류 용량
float remainingCapacity = 6.0;           // Ah, 초기 남은 배터리 용량
float soh = 100.0;                       // 초기 SOH 100%

// 시뮬레이션 변수
float dischargeRate = 0.5;  // A, 배터리 방전 전류
float chargeRate = 0.5;     // A, 배터리 충전 전류
float chargeTime = 0.0;     // h, 정전압 충전에 걸린 시간
float elapsedHours = 0.0;   // h, 전체 적산된 시간

void updateSOH() {
    soh = (remainingCapacity / nominalTotalCapacity) * 100.0;
    printf("Updated SOH: %.2f%%\n", soh);
}

void dischargeBattery(float current, float hours) {
    float discharged = current * hours;
    if (remainingCapacity > discharged) {
        remainingCapacity -= discharged;
        printf("Discharged: %.2fAh, Remaining Capacity: %.2fAh\n", discharged, remainingCapacity);
    } else {
        printf("Battery fully discharged.\n");
        remainingCapacity = 0;
    }
    updateSOH();
}

void chargeBattery(float current, float hours) {
    float charged = current * hours;
    if (remainingCapacity + charged <= nominalTotalCapacity) {
        remainingCapacity += charged;
        printf("Charged: %.2fAh, Remaining Capacity: %.2fAh\n", charged, remainingCapacity);
    } else {
        printf("Battery fully charged.\n");
        remainingCapacity = nominalTotalCapacity;
    }
    updateSOH();
    chargeTime += hours;  // 정전압 충전 시간을 충전 시간으로 간주
}

void adjustSOHBasedOnChargeTime() {
    // 정전압 충전 시간에 따른 SOH 감소를 조정
    float sohDecrease = chargeTime * 2.0;  // 가정: 충전 시간에 비례하여 SOH가 감소
    soh -= sohDecrease;
    if (soh < 0) soh = 0;
    printf("Adjusted SOH after CV charge: %.2f%%\n", soh);
    chargeTime = 0.0;  // 충전 시간 초기화
}

int main() {
    for (int i = 0; i < 3; i++) {
        printf("\nCycle %d:\n", i + 1);
        
        // 1시간 동안 방전
        dischargeBattery(dischargeRate, 1.0);
        
        // 1시간 동안 충전
        chargeBattery(chargeRate, 1.0);
        
        // SOH 보정
        adjustSOHBasedOnChargeTime();
    }

    return 0;
}
