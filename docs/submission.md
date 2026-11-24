# Submission Guide

## Submission Structure

We suggest this structure for your final project submission:

```text
<student_id>_<name>/
├── main.c
├── student.h
├── student.c
├── students.txt
├── Makefile
└── README.md
```

## Requirements

- Include every required source file.
- The code must compile with `gcc -Wall -Wextra -std=c11`.
- Do not submit the executable or `.o` files (run `make clean` first).
- Do not use an external linked list library.
- Do not use an array of students.
- Do not use a global variable for the list.
- Create each node with `malloc()`.
- Call `free()` at the right time, so that there are no memory leaks.
- Load the data file at start and save it at exit, as readable text.

## What to Put in Your README

1. How to run the program
2. The features you implemented
3. The data structures you used, with a picture of a list of 3 students
4. The four cases of delete, and how your code handles each one
5. How your program handles a bad line in the file
6. The problems you met while implementing, and how you solved them
7. Any optional extensions you did

## Check Before You Submit

```bash
gcc -Wall -Wextra -std=c11 main.c student.c -o student_manager
./student_manager
```

The build must show no warnings.
