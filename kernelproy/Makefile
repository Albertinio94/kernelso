CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -pthread -ansi

KERNEL_SOURCES = $(filter-out kernel.c, $(shell find . -type f -name '*.c'))
KERNEL_OBJECTS = $(KERNEL_SOURCES:.c=.o)

TESTS_SOURCES = $(filter-out tests.c, $(shell find . -type f -name '*.c'))
TESTS_OBJECTS = $(TESTS_SOURCES:.c=.o)

.PHONY: all clean

all: clean kernel tests

kernel: $(KERNEL_OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@
	rm -f $(KERNEL_OBJECTS)

tests: $(TESTS_OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@
	rm -f $(TESTS_OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(KERNEL_OBJECTS) $(TESTS_OBJECTS) kernel tests
