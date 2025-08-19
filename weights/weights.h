#ifndef WEIGHTS_H
#define WEIGHTS_H
#define INPUT_H 8
#define INPUT_W 8
#define INPUT_SIZE (INPUT_H * INPUT_W)
#define HIDDEN_SIZE 18
#define OUTPUT_SIZE 10
extern const float Hidden_Bias[HIDDEN_SIZE];
extern const float Hidden_Weight[HIDDEN_SIZE * INPUT_SIZE];
extern const float Output_Bias[OUTPUT_SIZE];
extern const float Output_Weight[OUTPUT_SIZE * HIDDEN_SIZE];
#endif
