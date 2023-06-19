CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -pthread -ansi

SOURCES = $(shell find . -type f -name '*.c')
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all clean

all: clean kernel

kernel: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@
	rm -f $(SOURCES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) kernel

