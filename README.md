# C Programming — Linked Lists: Student Materials

Lecture notes, PowerPoint slides, reference PDFs, C examples, and assignment starters.
Build a **Student Management System** that keeps its students in a **doubly linked list** and saves them to a file.

## Schedule

The course runs in **four sessions and an exam**.

| Session | Week of | Topic | Lecture notes | Examples | Assignment |
|---|---|---|---|---|---|
| 1 | — | Build Tools, Makefile, and Struct | [Session 1](lectures/session1-struct/) | [Examples](lectures/session1-struct/examples/) | [Session 1](assignments/session1-struct/) |
| 2 | Nov 23 | Operators and Precedence | [Session 2](lectures/session2-operators/) | [Examples](lectures/session2-operators/examples/) | [Session 2: Parts A and B](assignments/session2-operators/) |
| 3 | Nov 30 | Dynamic Memory and Linked Lists | [Session 3](lectures/session3-linked-list/): [Part 1](lectures/session3-linked-list/part1-dynamic-memory-singly-list.md), [Part 2](lectures/session3-linked-list/part2-doubly-linked-list.md) | [Examples](lectures/session3-linked-list/examples/) | [Session 3](assignments/session3-linked-list/): labs 03A and 03B, assignment 03C |
| 4 | Dec 7 | File I/O, Multi-file Programs, and the Final Project | [Session 4](lectures/session4-file-io-project/): [Part 1](lectures/session4-file-io-project/part1-file-io.md), [Part 2](lectures/session4-file-io-project/part2-multi-file-project.md) | [Examples](lectures/session4-file-io-project/examples/) | [Final Project](assignments/session4-final-project/) |
| — | Dec 14 | **Exam**; final project due | | | |

Read the assignment's `README.md` first, then complete the TODOs in its `starter/` directory.

### Optional extras

These are **not part of the four sessions and not on the exam**. They continue from Session 3, and the final project accepts an intrusive list as a bonus extension.

| Extra | Topic | Lecture notes | Assignment |
|---|---|---|---|
| A | Circular List with a Sentinel | [Extra A](lectures/optional/a-circular-list/) | [Extra A](assignments/optional/a-circular-list/) |
| B | Intrusive Linked List | [Extra B](lectures/optional/b-intrusive-list/) | [Extra B](assignments/optional/b-intrusive-list/) |
| C | `offsetof()` and `container_of()` | [Extra C](lectures/optional/c-container-of/) | [Extra C](assignments/optional/c-container-of/) |
| D | File I/O with an Intrusive List | [Session 4, Part 1](lectures/session4-file-io-project/part1-file-io.md) | [Extra D](assignments/optional/d-file-io-intrusive/) |

## Lecture Notes and Reference PDFs

The [lecture guide](lectures/README.md) links each session's notes, slides, examples, and assignments.
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
make -C lectures/session1-struct/examples
./lectures/session1-struct/examples/struct_basics

# Build and run the first assignment starter.
make -C assignments/session1-struct/starter
./assignments/session1-struct/starter/session1

# Remove compiled files.
make -C lectures clean
make -C assignments/session1-struct/starter clean
```

Use the same commands with the appropriate session's directory. Makefiles and sample input files are included with the examples and assignments.

## Course Rules

- Write C11 code and check compiler warnings with `gcc -Wall -Wextra -std=c11`.
- Free dynamically allocated memory when it is no longer needed.
- Implement the final project with a doubly linked list of `malloc()`ed nodes, and load and save it as a text file.
- Follow each assignment's requirements and verify that your program compiles and works before submitting.
- Submit source files, the Makefile, and your README; leave out compiled executables.

## Build Notes

The lecture examples build without warnings, except for three demonstration files intentionally left out of the default build: `warnings.c` (Session 1), `precedence_traps.c` (Session 2), and `dangling_local.c` (Session 3).
The Session 2 assignment starter intentionally produces warnings for you to fix.

Session 4 includes a file-based example test:

```bash
make -C lectures/session4-file-io-project/examples/file-io test
```

The [final project assignment](assignments/session4-final-project/README.md) contains the complete requirements and submission checklist.
See also the [project overview](docs/project_overview.md), [grading criteria](docs/grading.md),
and [submission guide](docs/submission.md).
