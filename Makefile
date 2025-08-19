CC := gcc
CFLAGS := -O2 -Wall -Wextra -Iinclude -Iweights
SRC := src/main.c src/nn.c src/utils.c weights/weights.c
BIN := build
OUT := $(BIN)/demo

all: $(OUT)
$(OUT): $(SRC)
	@mkdir -p $(BIN)
	$(CC) $(CFLAGS) $^ -o $@

run: all
	./$(OUT)

clean:
	rm -rf $(BIN)

.PHONY: all run clean
