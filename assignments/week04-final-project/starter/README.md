# Final Project Starter

This directory has the starter code for the final project.

## Files

- `main.c` — the menu, the keyboard input, and the program flow
- `student.h` — the student, node, and list structures, and the function prototypes
- `student.c` — the list and file operations
- `students.txt` — sample data, with 2 bad lines on purpose
- `Makefile` — for building easily

Write the code for every `TODO` yourself.

## Build

```bash
make
./student_manager
```

Or:

```bash
gcc -Wall -Wextra -std=c11 main.c student.c -o student_manager
./student_manager
```

The starter builds with no warnings and runs, but every operation is empty:
it loads 0 students, and Save writes nothing.

## Important

The function structure in this starter code is one suggested design. What matters is that your program meets these requirements:

- Doubly linked list with `head` and `tail`
- Dynamic memory management
- Student features: add, search, print forward and backward, count, delete
- Load from a file at start, save to the file at exit
- Bad input, from the keyboard or from the file, never crashes the program
