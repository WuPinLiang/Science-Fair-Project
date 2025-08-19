#include "utils.h"
#include <stdio.h>

void print_bitmap(const uint8_t word[8]) {
    for (int r = 0; r < 8; r++) {
        uint8_t mask = 0b10000000;
        for (int c = 0; c < 8; c++) {
            putchar((word[r] & mask) ? '#' : '.');
            mask >>= 1;
        }
        putchar('\n');
    }
}

int argmax_float(const float *arr, int n) {
    int best_i = 0;
    float best_v = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > best_v) {
            best_v = arr[i];
            best_i = i;
        }
    }
    return best_i;
}
