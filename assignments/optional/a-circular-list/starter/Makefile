CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = extra_a

all: $(TARGET)

$(TARGET): extra_a.c
	$(CC) $(CFLAGS) extra_a.c -o $(TARGET)

clean:
	rm -f $(TARGET)
