# TinyML-DigitRecognizer

This project demonstrates a complete pipeline from **training a neural network model** to **deploying it on a microcontroller-like environment**, ultimately achieving handwritten digit recognition. It combines Python (for training and parameter export) with C (for inference), showing how AI can be embedded in resource-constrained systems. This is not only a science fair project but also a practical example of **TinyML**.

---

## Background

Deep learning models are widely applied in computer vision, speech recognition, and natural language processing. However, these models usually require high computational power, making it difficult to run them directly on microcontrollers. At the same time, the demand for **AI on the edge** is growing due to IoT, wearable devices, and embedded applications.

Potential applications include:

* Real-time anomaly detection in health monitoring devices.
* On-site defect detection in industrial manufacturing.
* Voice or gesture recognition in smart home devices.
* Lightweight AI inference for edge devices without internet.

This project answers the question: **How can a trained neural network be converted into efficient C code that runs on microcontrollers?**

---

## Objectives

1. Build a simple neural network for handwritten digit recognition.
2. Train the model in Python and export weights/biases as text files.
3. Convert parameters into C arrays to integrate into embedded code.
4. Implement inference (forward pass + ReLU activation) in C.
5. Test using 8×8 input patterns and verify outputs.

---

## Methodology

### Model Training

* Designed a two-layer fully connected network.
* Hidden layer: ReLU activation.
* Output layer: scores for digits 0–9 with argmax prediction.

### Parameter Export

Exported four sets of parameters into `weights_raw/`:

* Hidden Bias, Hidden Weight, Output Bias, Output Weight.

### Conversion to C

Converted text weights into `weights/weights.c` and `weights/weights.h`. These are directly included during compilation.

### C Implementation

* Reads 8×8 test input.
* Computes hidden layer and applies ReLU.
* Computes output layer and applies ReLU.
* Predicts digit by finding maximum score.

### Validation

The system prints the 8×8 test pattern, intermediate results, and final digit prediction.

---

## Results

* **Correctness**: Successfully predicts test digits.
* **Portability**: The system can run in constrained environments.
* **Educational value**: Demonstrates the full pipeline from ML training to embedded deployment.
* **Limitations**: Accuracy is limited due to small model size.

---

## Project Contents

* `notebooks/MicroProcessor.ipynb` → model training and weight export (Colab).
* `src/`, `include/` → C inference code.
* `weights_raw/` → raw exported weights.
* `weights/` → converted C arrays for compilation.

---

## Usage

### Notebook

[![Open In Colab](https://colab.research.google.com/assets/colab-badge.svg)](https://colab.research.google.com/github/WuPinLiang/TinyML-DigitRecognizer/blob/main/notebooks/MicroProcessor.ipynb)

### Compile & Run

```bash
make clean
make
./build/demo
```

Outputs include:

* Visualized 8×8 pattern.
* Hidden and output layer calculations.
* Final digit prediction.

---

## Structure

```
TinyML-DigitRecognizer/
├── notebooks/        # Training notebook
├── weights_raw/      # Raw text weights
├── weights/          # C arrays for compilation
├── src/              # C source code
├── include/          # Header files
├── Makefile
└── README.md
```

---

## Significance & Future Work

This project shows how AI can be embedded on microcontrollers, illustrating the field of **TinyML**. While it focuses on digit recognition, the methods can extend to:

* Health monitoring in wearables.
* Industrial defect detection.
* Smart home gesture/voice recognition.
* Edge AI applications without internet.

Future directions:

1. Quantization (e.g., 32-bit → 8-bit) to reduce size.
2. Test CNNs with pruning/compression for efficiency.
3. Deploy to real microcontrollers or FPGA hardware.
4. Automate conversion from ML frameworks (PyTorch/TensorFlow) to embedded C.

---

## Conclusion

**TinyML-DigitRecognizer** is a complete demonstration of taking a neural network from Python training to C-based embedded inference. It highlights the challenges and possibilities of running AI on microcontrollers, serving as both an educational resource and a foundation for future research in embedded AI.
