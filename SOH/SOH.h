#ifndef SOH_H
#define SOH_H

#include "SOH_Kalman.c"
#include "SOH.c"

void kalman_init(KalmanFilter* kf, double init_estimate, double init_error_cov, double process_noise, double measurement_noise);
void kalman_update(KalmanFilter* kf, double measurement);
double SOH(double original_Capacity, double current_Capacity);

#endif 
