#include<stdio.h>

double Current_Capacity_Resistance(double originalResistance, double currentResistance, double originalCapacity) {
    if (originalResistance == 0) {
        return 0;
    }

    double degradationFactor = (currentResistance - originalResistance) / originalResistance;
    double currentCapacity =  (1 - degradationFactor) * 100;

    if (currentCapacity < 0) {
        currentCapacity = 0;
    }
    return currentCapacity;
}
