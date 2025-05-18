// NotchFilter.h
#ifndef _NOTCH_FILTER_H
#define _NOTCH_FILTER_H
#include <Arduino.h>
class NotchFilter {
public:
    NotchFilter(double f0, double fs, double Q = 30.0); // Constructor
    double process(double x); // Xử lý một mẫu

private:
    double b0, b1, b2, a1, a2;
    double x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0;
};

#endif