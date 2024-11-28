#include "SOH/SOH.h"
#include <stdio.h>

int main() {
    int max_Cycles = 1000; // 예시 최대 충전/방전 사이클 수
    int current_Cycles = 300; // 현재 사이클 수

    double soh = SOH_Cycle(max_Cycles, current_Cycles);
    printf("Cycle Based SOH: %.2f%%\n", soh);
    return 0;
}
