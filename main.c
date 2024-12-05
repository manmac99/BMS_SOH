#include "SOH/SOH.h"
#include <stdio.h>

int main() {
    //용량 기반 로직
    //--------------------------------------------------------------------
    printf("1. 용량 기반 로직\n");
    printf("--------------------------------------------------------------------\n");
    double charge_Ampere = 500.0; //Ah
    double battery_Capacity = 38500.0; //Ah
    double original_Charge_Time = battery_Capacity/charge_Ampere; //77

    double estimated_Charge_Time = 75;
    double current_Capacity = charge_Ampere * estimated_Charge_Time;

    double SOH_Capa = SOH_Capacity(battery_Capacity, current_Capacity);

    //용량 기반 SOH 출력
    printf("SOH (Capacity-Based): %.2f%%\n", SOH_Capa);
    printf("--------------------------------------------------------------------\n\n");
    //--------------------------------------------------------------------

    //저항 기반 로직
    //--------------------------------------------------------------------
    printf("2. 저항 기반 로직\n");
    printf("--------------------------------------------------------------------\n");
    double originalResistance[3] = {0.005, 0.005, 0.0065};  // 초기 저항값
    double currentResistances[3] = {0.0055, 0.006, 0.007};  // SOC 범위별 현재 저항값

    // 개선된 저항 기반 SOH 계산
    double SOH_Resis = SOH_Resistance(originalResistance, currentResistances);

    printf("Resistance Based SOH : %.2f%%\n", SOH_Resis);
    printf("--------------------------------------------------------------------\n\n");
    //--------------------------------------------------------------------

    //내부 임피던스 기반 로직
    //--------------------------------------------------------------------
    printf("3. 내부 임피던스 기반 로직\n");
    printf("--------------------------------------------------------------------\n");

    double initial_Impedance[3] = {0.010, 0.012, 0.012}; // 초기 임피던스, Ohms
    double impedance_Measurements[3] = {0.011, 0.012, 0.013}; // 구간별 임피던스 측정값, Ohms
    double weights[3] = {0.2, 0.6, 0.2}; // 각 구간별 가중치

    double SOH_Impe = SOH_Impedance(initial_Impedance, impedance_Measurements, weights);
    printf("Impedence Based SOH: %.2f%%\n", SOH_Impe);

    printf("--------------------------------------------------------------------\n\n");
    //--------------------------------------------------------------------

    //Cycle 임피던스 기반 로직
    //--------------------------------------------------------------------
    printf("4. Cycle 기반 로직\n");
    printf("--------------------------------------------------------------------\n");

    int max_Cycles = 1000; // 예시 최대 충전/방전 사이클 수
    int current_Cycles = 300; // 현재 사이클 수

    double SOH_Cy = SOH_Cycle(max_Cycles, current_Cycles);
    printf("Cycle Based SOH: %.2f%%\n", SOH_Cy);

    printf("--------------------------------------------------------------------\n\n");
    //--------------------------------------------------------------------

    //복구 임피던스 기반 로직
    //--------------------------------------------------------------------
    printf("5. Recovery 기반 로직\n");
    printf("--------------------------------------------------------------------\n");

    double V_loaded = 3.2;       // 부하 적용 중의 전압 (Volts)
    double V_recovered = 3.8;    // 부하 제거 후 회복된 전압 (Volts)
    double V_nominal = 4.0;      // 부하가 없을 때의 정상 전압 (Volts)

    double SOH_Rec = SOH_Recovery(V_recovered, V_loaded, V_nominal);
    printf("Recovery Based SOH: %.2f%%\n", SOH_Rec);

    printf("--------------------------------------------------------------------\n\n");
    //--------------------------------------------------------------------

    //CC-CV 임피던스 기반 로직
    //--------------------------------------------------------------------

    printf("6. CC-CV 기반 로직\n");
    printf("--------------------------------------------------------------------\n");

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

    printf("--------------------------------------------------------------------\n\n");
    //--------------------------------------------------------------------

    return 0;
}
