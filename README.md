# Science-Fair-Project

- `notebooks/MicroProcessor.ipynb`: your training notebook (add your file here)
- `weights/weights.h, weights/weights.c`: auto-generated from uploaded txt parameters (float)
- `include/`, `src/`: minimal C inference program (8x8 bitmap -> hidden -> output)

## Build & Run
```bash
make
make run
```

## Files auto-generated from your uploads
- Hidden_Bias: 18 values
- Hidden_Weight: 1152 values (expected 18 * 64)
- Output_Bias: 10 values
- Output_Weight: 180 values (expected 10 * 18)
