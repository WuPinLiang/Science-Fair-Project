#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

static inline float ReLu(float x) { return (x > 0.0f) ? x : 0.0f; }
void print_bitmap(const uint8_t word[8]);
int argmax_float(const float *arr, int n);

#endif // UTILS_H
