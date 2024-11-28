#include<stdio.h>

double Current_Capacity(double original_Capacity, double *currentMeasurements, int numMeasurements, double measurementInterval) {
    double dischargedCoulombs = 0.0;

    for (int i = 0; i < numMeasurements; ++i) {
        dischargedCoulombs += currentMeasurements[i] * measurementInterval;
    }

    double currentCapacity = original_Capacity - (dischargedCoulombs / 3600.0); // 쿨롱을 아워로 변환
    if (currentCapacity < 0) {
        currentCapacity = 0;
    }
    return currentCapacity;
}
