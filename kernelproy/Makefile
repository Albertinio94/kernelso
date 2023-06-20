CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -pthread -ansi

KERNEL_SOURCES = kernel.c
KERNEL_OBJECTS = $(KERNEL_SOURCES:.c=.o)

TESTS_SOURCES = tests.c
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
