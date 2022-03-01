TOP_DIR = .
SRC_DIR = $(TOP_DIR)/src
BUILD_DIR = $(TOP_DIR)/build
CC = gcc
OBJS = $(BUILD_DIR)/llist.o	\
	   $(BUILD_DIR)/dir.o	\
	   $(BUILD_DIR)/file.o	\
	   $(BUILD_DIR)/mkfile.o

default: main

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
		$(CC) -c -o $@ $<

main: $(OBJS)
		$(CC) $(SRC_DIR)/main.c $(OBJS)

clean:
		rm build/*.o a.out
