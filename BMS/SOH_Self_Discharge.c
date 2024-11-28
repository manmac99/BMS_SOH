#include <stdio.h>

// 자기방전율을 기반으로 SOH 계산
double SOH_Self_Discharge(double initialCapacity, double measuredCapacityAfterPeriod, double expectedSelfDischargeRate) {
    if (initialCapacity == 0) {
        return 0; // 초기 용량이 0이면 계산 불가
    }

    // 자기방전율 계산
    double actualSelfDischargeRate = ((initialCapacity - measuredCapacityAfterPeriod) / initialCapacity) * 100;

    // SOH 계산
    double soh = (1 - (actualSelfDischargeRate / expectedSelfDischargeRate)) * 100;

    if (soh < 0) {
        soh = 0; // SOH가 0% 미만으로 내려가지 않도록 처리
    }
    return soh;
}
