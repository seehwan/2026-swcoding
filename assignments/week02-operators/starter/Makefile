CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGETS = week02a week02b

all: $(TARGETS)

week02a: assignment_02a.c
	$(CC) $(CFLAGS) assignment_02a.c -o week02a

# Part B is full of deliberate traps, so it is built with warnings off (-w).
week02b: assignment_02b.c
	$(CC) -std=c11 -w assignment_02b.c -o week02b

clean:
	rm -f $(TARGETS)
