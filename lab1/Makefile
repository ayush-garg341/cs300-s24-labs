CFLAGS = -Wall -Werror

.PHONY: all clean format

all: reverse_test

reverse_test: reverse.o test_reverse.o
	gcc $(CFLAGS) $^ -o $@

%.o: %.c
	gcc $(CFLAGS) -c $^ -o $@

clean: 
	rm -f *.o reverse_test 

format:
	clang-format -style=Google -i reverse.c reverse.h
