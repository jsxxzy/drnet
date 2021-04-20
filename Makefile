objects = auth.o ini.o filepath.o \
	http.o http_parser.o krypton.o \
	md5.o drcore.o html_parser.o \
	gistregex.o cutils.o opener.o

CC = gcc

CFLAGS = -fno-rtti -fno-exceptions -Wl

BUILD_TARGET = buildcache

all: clean build run

build: $(objects)
	$(CC) $(CFLAGS) -o $(BUILD_TARGET)/drnet main.c $(objects)

# ===================

opener.o: opener.h

cutils.o: cutils.h

gistregex.o: gistregex.h

drcore.o: drcore.h

html_parser.o: html_parser.h

md5.o: md5.h

http.o: http.h

http_parser.o: http_parser.h

krypton.o: krypton.h

auto.o: auth.h

ini.o: ini.h

filepath.o: filepath.h

# ===================


.PHONY: clean

run:
	./$(BUILD_TARGET)/drnet

clean:
	rm -rf *.o $(BUILD_TARGET)/*