CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGETS = session3a session3b session3c

all: $(TARGETS)

session3a: assignment_03a.c
	$(CC) $(CFLAGS) assignment_03a.c -o session3a

session3b: assignment_03b.c
	$(CC) $(CFLAGS) assignment_03b.c -o session3b

session3c: assignment_03c.c
	$(CC) $(CFLAGS) assignment_03c.c -o session3c

clean:
	rm -f $(TARGETS)
