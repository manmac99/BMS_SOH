#include <stdio.h>

typedef struct {
    double estimate;   // 현재 추정된 상태
    double error_cov;  // 오류 공분산
    double process_noise;  // 과정 잡음
    double measurement_noise;  // 측정 잡음
    double gain; //조정
} KalmanFilter;


// 칼만 필터 초기화 함수
void kalman_init(KalmanFilter* kf, double init_estimate, double init_error_cov, double process_noise, double measurement_noise) {
    kf->estimate = init_estimate;
    kf->error_cov = init_error_cov;
    kf->process_noise = process_noise;
    kf->measurement_noise = measurement_noise;
}

// 칼만 필터 업데이트 함수
void kalman_update(KalmanFilter* kf, double measurement) {
    // 예측 업데이트
    kf->error_cov += kf->process_noise;

    // 칼만 조정 계산
    kf->gain = kf->error_cov / (kf->error_cov + kf->measurement_noise);

    // 측정 업데이트
    kf->estimate += kf->gain * (measurement - kf->estimate);
    kf->error_cov *= (1 - kf->gain);
}