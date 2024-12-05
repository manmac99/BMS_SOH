#include "SOH/SOH.h"
#include <stdio.h>

int main() {

    double charge_Ampere = 500.0; //Ah
    double battery_Capacity = 38500.0; //Ah
    double original_Charge_Time = battery_Capacity/charge_Ampere; //77

    double estimated_Charge_Time = 75;
    double current_Capacity = charge_Ampere * estimated_Charge_Time;

    double SOH_Capa = SOH_Capacity(battery_Capacity, current_Capacity);

    //용량 기반 SOH 출력
    printf("SOH (Capacity-Based): %.2f%%\n", SOH_Capa);

    return 0;
}
