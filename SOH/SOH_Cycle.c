#include <stdio.h>

// 충전/방전 사이클 수를 기반으로 SOH 계산
double SOH_Cycle(int max_Cycles, int current_Cycles) {
    double soh = ((double)max_Cycles - (double)current_Cycles) / max_Cycles * 100;
    return soh;
}