CC = gcc
SRC_DIR = ./src
FILES = $(SRC_DIR)/riscv_decoder.c \
		$(SRC_DIR)/decode.c \
		$(SRC_DIR)/decode/instr_fmt.c
BUILD_DIR = ./build
EXE_NAME = riscv_decoder
OPTS = -Wall

all:
	mkdir $(BUILD_DIR) -p
	$(CC) $(FILES) $(OPTS) -o $(BUILD_DIR)/$(EXE_NAME) 

release:
	mkdir $(BUILD_DIR) -p
	$(CC) $(FILES) $(OPTS) --static -O2 -o $(BUILD_DIR)/$(EXE_NAME) 
