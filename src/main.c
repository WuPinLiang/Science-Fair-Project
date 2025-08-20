#include <stdio.h>
#include <stdint.h>
#include "nn.h"
#include "utils.h"

int main(void) {
    uint8_t word[8] = {
        0b00111100,
        0b01100110,
        0b01101110,
        0b01110110,
        0b01100110,
        0b01100110,
        0b00111100,
        0b00000000 
    };

    float hidden[HIDDEN_SIZE] = {0};
    float output[OUTPUT_SIZE] = {0};

    puts("Input bitmap:");
    print_bitmap(word);

    forward_hidden_raw(word, hidden);
    activate_hidden_inplace(hidden);

    for (int i = 0; i < HIDDEN_SIZE; i++) {
        printf("hidden[%02d] = %.6f\n", i, hidden[i]);
    }

    forward_output_raw(hidden, output);
    activate_output_inplace(output);

    for (int i = 0; i < OUTPUT_SIZE; i++) {
        printf("number %d, score: %.6f\n", i, output[i]);
    }

    int pred = argmax_float(output, OUTPUT_SIZE);
    printf("Prediction: %d\n", pred);

    return 0;
}
