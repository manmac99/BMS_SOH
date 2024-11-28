#include "SOH/SOH.h"
#include <stdio.h>

int main() {
    double V_loaded = 3.2;       // 부하 적용 중의 전압 (Volts)
    double V_recovered = 3.8;    // 부하 제거 후 회복된 전압 (Volts)
    double V_nominal = 4.0;      // 부하가 없을 때의 정상 전압 (Volts)

    double SOH_Rec = SOH_Recovery(V_recovered, V_loaded, V_nominal);
    printf("Recovery Based SOH: %.2f%%\n", SOH_Rec);
    return 0;
}
