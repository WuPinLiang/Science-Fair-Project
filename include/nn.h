#ifndef NN_H
#define NN_H

#include <stdint.h>
#include "../weights/weights.h"

void forward_hidden_raw(const uint8_t word[INPUT_H], float hidden[HIDDEN_SIZE]);
void activate_hidden_inplace(float hidden[HIDDEN_SIZE]);
void forward_output_raw(const float hidden[HIDDEN_SIZE], float output[OUTPUT_SIZE]);
void activate_output_inplace(float output[OUTPUT_SIZE]);

#endif // NN_H
