#include "nn.h"
#include "utils.h"

void forward_hidden_raw(const uint8_t word[INPUT_H], float hidden[HIDDEN_SIZE]) {
    for (int i = 0; i < HIDDEN_SIZE; i++) hidden[i] = 0.0f;

    for (int i = 0; i < HIDDEN_SIZE; i++) {
        float acc = 0.0f;
        for (int r = 0; r < INPUT_H; r++) {
            uint8_t mask = 0b10000000;
            for (int c = 0; c < INPUT_W; c++) {
                if (word[r] & mask) {
                    int flat = r * INPUT_W + c; // 0..63
                    acc += Hidden_Weight[i * INPUT_SIZE + flat];
                }
                mask >>= 1;
            }
        }
        hidden[i] = acc; // raw sum
    }
}

void activate_hidden_inplace(float hidden[HIDDEN_SIZE]) {
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        hidden[i] = ReLu(hidden[i] + Hidden_Bias[i]);
    }
}

void forward_output_raw(const float hidden[HIDDEN_SIZE], float output[OUTPUT_SIZE]) {
    for (int o = 0; o < OUTPUT_SIZE; o++) {
        float acc = 0.0f;
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            acc += hidden[j] * Output_Weight[o * HIDDEN_SIZE + j];
        }
        output[o] = acc;
    }
}

void activate_output_inplace(float output[OUTPUT_SIZE]) {
    for (int o = 0; o < OUTPUT_SIZE; o++) {
        output[o] = ReLu(output[o] + Output_Bias[o]);
    }
}
