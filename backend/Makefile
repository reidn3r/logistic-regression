SRC_DIR := ./src
BUILD_DIR := ./build
INCLUDE_DIR := ./include
LIB_NAME := library.so
LIBRARY_PATH := $(BUILD_DIR)/$(LIB_NAME)

SRCS = $(SRC_DIR)/logistic-regression.c $(SRC_DIR)/matrix-op.c
OBJS = $(BUILD_DIR)/logistic-regression.o $(BUILD_DIR)/matrix-op.o

lib: $(OBJS)
$(BUILD_DIR)/logistic-regression.o: $(SRC_DIR)/logistic-regression.c
	gcc -fPIC -I $(INCLUDE_DIR) -c $(SRC_DIR)/logistic-regression.c -o $(BUILD_DIR)/logistic-regression.o

$(BUILD_DIR)/matrix-op.o: $(SRC_DIR)/matrix-op.c
	gcc -fPIC -I $(INCLUDE_DIR) -lm -c $(SRC_DIR)/matrix-op.c -o $(BUILD_DIR)/matrix-op.o
	gcc -shared -o $(LIBRARY_PATH) $(BUILD_DIR)/*.o

clean:
	rm -rf $(BUILD_DIR)/*.o