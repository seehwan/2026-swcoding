# C Programming — Linked Lists: Student Materials

Lecture notes, PowerPoint slides, reference PDFs, C examples, and assignment starters.
Build a **Student Management System** that keeps its students in a **doubly linked list** and saves them to a file.

## Schedule

The course runs in **four weeks and an exam**.

| Week | Week of | Topic | Lecture notes | Examples | Assignment |
|---|---|---|---|---|---|
| 1 | — | Build Tools, Makefile, and Struct | [Week 01](lectures/week01-struct/) | [Examples](lectures/week01-struct/examples/) | [Week 01](assignments/week01-struct/) |
| 2 | Nov 23 | Operators and Precedence | [Week 02](lectures/week02-operators/) | [Examples](lectures/week02-operators/examples/) | [Week 02: Parts A and B](assignments/week02-operators/) |
| 3 | Nov 30 | Dynamic Memory and Linked Lists | [Week 03](lectures/week03-linked-list/): [Part 1](lectures/week03-linked-list/part1-dynamic-memory-singly-list.md), [Part 2](lectures/week03-linked-list/part2-doubly-linked-list.md) | [Examples](lectures/week03-linked-list/examples/) | [Week 03](assignments/week03-linked-list/): labs 03A and 03B, assignment 03C |
| 4 | Dec 7 | File I/O, Multi-file Programs, and the Final Project | [Week 04](lectures/week04-file-io-project/): [Part 1](lectures/week04-file-io-project/part1-file-io.md), [Part 2](lectures/week04-file-io-project/part2-multi-file-project.md) | [Examples](lectures/week04-file-io-project/examples/) | [Final Project](assignments/week04-final-project/) |
| — | Dec 14 | **Exam**; final project due | | | |

Read the assignment's `README.md` first, then complete the TODOs in its `starter/` directory.

### Optional extras

These are **not part of the four weeks and not on the exam**. They continue from Week 03, and the final project accepts an intrusive list as a bonus extension.

| Extra | Topic | Lecture notes | Assignment |
|---|---|---|---|
| A | Circular List with a Sentinel | [Extra A](lectures/optional/a-circular-list/) | [Extra A](assignments/optional/a-circular-list/) |
| B | Intrusive Linked List | [Extra B](lectures/optional/b-intrusive-list/) | [Extra B](assignments/optional/b-intrusive-list/) |
| C | `offsetof()` and `container_of()` | [Extra C](lectures/optional/c-container-of/) | [Extra C](assignments/optional/c-container-of/) |
| D | File I/O with an Intrusive List | [Week 04, Part 1](lectures/week04-file-io-project/part1-file-io.md) | [Extra D](assignments/optional/d-file-io-intrusive/) |

## Lecture Notes and Reference PDFs

The [lecture guide](lectures/README.md) links each week's notes, slides, examples, and assignments.
Seven reference PDFs from **C Programming Part 2** are placed beside the relevant decks;
the [reading map](lectures/README.md#reference-pdf-placement) lists their locations and selected pages.
Each example guide maps runnable C demos to those PDF pages and includes short exercises.

## Getting Started

You need a C11 compiler (`gcc` or Clang) and `make`.

```bash
git clone https://github.com/seehwan/2026-swcoding.git
cd 2026-swcoding

# Build or run every lecture example with prepared input.
make -C lectures
make -C lectures run

# Build and run a lecture example.
make -C lectures/week01-struct/examples
./lectures/week01-struct/examples/struct_basics

# Build and run the first assignment starter.
make -C assignments/week01-struct/starter
./assignments/week01-struct/starter/week01

# Remove compiled files.
make -C lectures clean
make -C assignments/week01-struct/starter clean
```

Use the same commands with the appropriate week's directory. Makefiles and sample input files are included with the examples and assignments.

## Course Rules

- Write C11 code and check compiler warnings with `gcc -Wall -Wextra -std=c11`.
- Free dynamically allocated memory when it is no longer needed.
- Implement the final project with a doubly linked list of `malloc()`ed nodes, and load and save it as a text file.
- Follow each assignment's requirements and verify that your program compiles and works before submitting.
- Submit source files, the Makefile, and your README; leave out compiled executables.

## Build Notes

The lecture examples build without warnings, except for three demonstration files intentionally left out of the default build: `warnings.c` (Week 01), `precedence_traps.c` (Week 02), and `dangling_local.c` (Week 03).
The Week 02 assignment starter intentionally produces warnings for you to fix.

Week 04 includes a file-based example test:

```bash
make -C lectures/week04-file-io-project/examples/file-io test
```

The [final project assignment](assignments/week04-final-project/README.md) contains the complete requirements and submission checklist.
See also the [project overview](docs/project_overview.md), [grading criteria](docs/grading.md),
and [submission guide](docs/submission.md).
