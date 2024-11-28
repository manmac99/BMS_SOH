#include <stdio.h>

// 충전 데이터 배열을 사용하여 최종 충전량을 계산하고 SOH 계산
double SOH_Capacity(double original_Capacity, double charged_Data[]) {
    double accumulated_Capacity = 0.0;

    for (int i = 0; i < 100; ++i) {
        accumulated_Capacity += charged_Data[i];
    }

    return accumulated_Capacity;
}
