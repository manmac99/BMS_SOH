#include <stdio.h>

// 전압 복구 테스트 기반 SOH 계산 함수
double SOH_Recovery(double V_recovered, double V_loaded, double V_nominal) {
    if (V_nominal == V_loaded) {
        fprintf(stderr, "Error: V_nominal and V_loaded cannot be the same to avoid division by zero.\n");
        return -1;
    }

    double soh = ((V_recovered - V_loaded) / (V_nominal - V_loaded)) * 100;

    if (soh > 100) soh = 100;  // SOH가 100%를 초과하지 않도록 조정
    if (soh < 0) soh = 0;      // SOH가 0% 미만이 되지 않도록 조정

    return soh;
}