CC = gcc

CFLAGS = -Os

SRCS = $(wildcard *.c)

BUILD_DIR = buildcache

BUILD_BINFILE = drnet

BUILD_RASP_BINFILE = drnet_rasp

OBJECTS = $(patsubst %.c, %.o, $(SRCS))

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

build: $(OBJECTS)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(BUILD_BINFILE) $(OBJECTS)

tar:
	tar -zcvf dr.tar.gz *

run:
	./$(BUILD_DIR)/$(BUILD_BINFILE)

clean:
	rm *.o $(BUILD_DIR)/*

all: build

.PHONY: clean tar