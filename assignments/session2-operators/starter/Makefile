CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGETS = session2a session2b

all: $(TARGETS)

session2a: assignment_02a.c
	$(CC) $(CFLAGS) assignment_02a.c -o session2a

# Part B is full of deliberate traps, so it is built with warnings off (-w).
session2b: assignment_02b.c
	$(CC) -std=c11 -w assignment_02b.c -o session2b

clean:
	rm -f $(TARGETS)
