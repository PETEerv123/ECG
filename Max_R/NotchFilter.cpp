#include "NotchFilter.h"

NotchFilter::NotchFilter(double f0, double fs, double Q) {
    double w0 = 2 * M_PI * f0 / fs;
    double alpha = sin(w0) / (2 * Q);
    
    // Tính hệ số
    b0 = 1.0;
    b1 = -2 * cos(w0);
    b2 = 1.0;
    
    double a0 = 1 + alpha;
    a1 = -2 * cos(w0) / a0;
    a2 = (1 - alpha) / a0;
    
    // Chuẩn hóa hệ số
    b0 /= a0;
    b1 /= a0;
    b2 /= a0;
}

double NotchFilter::process(double x) {
    double y = b0 * x + b1 * x1 + b2 * x2 - a1 * y1 - a2 * y2;
    x2 = x1;
    x1 = x;
    y2 = y1;
    y1 = y;
    return y;
}