#include "SOH/SOH.h"
#include <stdio.h>

int main() {
    KalmanFilter kf;
    double initial_estimate = 100.0;  // 예를 들어, 배터리의 초기 SOH를 100%라고 가정
    kalman_init(&kf, initial_estimate, 1.0, 0.1, 0.1);
    printf("Original Kalman Filter Based SOH : %.2f%%\n", kf.estimate);

    double new_measurement = 98.0;  // 새로운 측정값
    kalman_update(&kf, new_measurement);
    printf("Updated Kalman Filter Based SOH : %.2f%%\n", kf.estimate);
    return 0;
}
