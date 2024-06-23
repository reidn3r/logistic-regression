SRC_DIR := ./src
BUILD_DIR := ./build
INCLUDE_DIR := ./include
LIB_NAME := library.so
LIBRARY_PATH := $(BUILD_DIR)/$(LIB_NAME)

SRCS = $(SRC_DIR)/model.c $(SRC_DIR)/linear_alg.c
OBJS = $(BUILD_DIR)/model.o $(BUILD_DIR)/linear_alg.o

lib: $(OBJS)
$(BUILD_DIR)/model.o: $(SRC_DIR)/model.c
	gcc -fPIC -I $(INCLUDE_DIR) -c $(SRC_DIR)/model.c -o $(BUILD_DIR)/model.o

$(BUILD_DIR)/linear_alg.o: $(SRC_DIR)/linear_alg.c
	gcc -fPIC -I $(INCLUDE_DIR) -lm -c $(SRC_DIR)/linear_alg.c -o $(BUILD_DIR)/linear_alg.o
	gcc -shared -o $(LIBRARY_PATH) $(BUILD_DIR)/*.o

clean:
	rm -rf $(BUILD_DIR)/*.o