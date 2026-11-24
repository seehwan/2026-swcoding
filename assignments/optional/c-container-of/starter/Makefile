CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = extra_c

all: $(TARGET)

$(TARGET): extra_c.c
	$(CC) $(CFLAGS) extra_c.c -o $(TARGET)

clean:
	rm -f $(TARGET)
