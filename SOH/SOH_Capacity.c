#include <stdio.h>

// 임피던스 계산을 통한 SOH 추정 함수
double SOH_Impedance(double initialImpedance, double measuredVoltage, double measuredCurrent) {
    if (measuredCurrent == 0) {
        fprintf(stderr, "Error: Current measurement cannot be zero.\n");
        return -1;  // 전류가 0이면 에러 반환
    }

    double currentImpedance = measuredVoltage / measuredCurrent;
    double impedanceIncrease = (currentImpedance - initialImpedance) / initialImpedance;
    double soh = (1.0 - impedanceIncrease) * 100;

    if (soh < 0) soh = 0;  // SOH가 0보다 작으면 0으로 설정
    return soh;
}
