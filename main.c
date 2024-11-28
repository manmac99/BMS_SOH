#include "SOH/SOH.h"
#include <stdio.h>

int main() {
    //용량 기반 로직
    //--------------------------------------------------------------------
    printf("1. 용량 기반 로직\n");
    printf("--------------------------------------------------------------------\n");
    double original_Capacity = 38500.0;  // 배터리의 원래 총 용량 설정
    double charged_Data[100];             // 1%부터 100%까지의 충전 데이터 저장 배열
    double charged_Rate = 384;  // 각 1%당 충전되는 양

    //용량 기반 계산
    // 충전 데이터 배열 채우기, 임의의 값 384로 채우기
    for (int i = 0; i < 100; i++) {charged_Data[i] = charged_Rate;}

    // 현재 총 Capacity 계산
    double Current_Capacity = SOH_Capacity(original_Capacity, charged_Data);

    //SOH 계산
    double SOH_Capa = SOH(original_Capacity, Current_Capacity);

    //총 Capacity 출력
    printf("Final Accumulated Capacity: %.2f Ah\n", Current_Capacity);

    //용량 기반 SOH 출력
    printf("SOH (Capacity-Based): %.2f%%\n", SOH_Capa);
    printf("--------------------------------------------------------------------\n\n");
    //--------------------------------------------------------------------

    //저항 기반 로직
    //--------------------------------------------------------------------
    printf("2. 저항 기반 로직\n");
    printf("--------------------------------------------------------------------\n");
    double originalResistance = 0.005;  // 초기 저항값
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

    double initial_Impedance = 0.010; // 초기 임피던스, Ohms
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
    printf("4. Recovery 기반 로직\n");
    printf("--------------------------------------------------------------------\n");

    double V_loaded = 3.2;       // 부하 적용 중의 전압 (Volts)
    double V_recovered = 3.8;    // 부하 제거 후 회복된 전압 (Volts)
    double V_nominal = 4.0;      // 부하가 없을 때의 정상 전압 (Volts)

    double SOH_Rec = SOH_Recovery(V_recovered, V_loaded, V_nominal);
    printf("Recovery Based SOH: %.2f%%\n", SOH_Rec);

    printf("--------------------------------------------------------------------\n\n");
    //--------------------------------------------------------------------

    return 0;
}
