# C Programming — Linked Lists: Student Materials

Weekly lecture notes, PowerPoint slides, reference PDFs, C examples, and assignment starters for the eight-week course.
Build a **Student Management System** using an **intrusive circular doubly linked list**.

## Weekly Materials

| Week | Topic | Slides | Examples | Assignment |
|---|---|---|---|---|
| 1 | Build Tools, Makefile, and Struct | [PPTX](lectures/week01-struct/week01-slides.pptx) | [Examples](lectures/week01-struct/examples/) | [Instructions and starter](assignments/week01-struct/) |
| 2 | Operators and Precedence | [PPTX](lectures/week02-operators/week02-slides.pptx) | [Examples](lectures/week02-operators/examples/) | [Instructions and starter](assignments/week02-operators/) |
| 3 | Dynamic Memory and Singly Linked List | [PPTX](lectures/week03-dynamic-memory-singly-list/week03-slides.pptx) | [Examples](lectures/week03-dynamic-memory-singly-list/examples/) | [Instructions and starter](assignments/week03-dynamic-memory-singly-list/) |
| 4 | Doubly Linked and Circular Lists | [PPTX](lectures/week04-doubly-circular-list/week04-slides.pptx) | [Examples](lectures/week04-doubly-circular-list/examples/) | [Instructions and starter](assignments/week04-doubly-circular-list/) |
| 5 | Intrusive Linked List | [PPTX](lectures/week05-intrusive-list/week05-slides.pptx) | [Examples](lectures/week05-intrusive-list/examples/) | [Instructions and starter](assignments/week05-intrusive-list/) |
| 6 | offsetof() and container_of() | [PPTX](lectures/week06-container-of/week06-slides.pptx) | [Examples](lectures/week06-container-of/examples/) | [Instructions and starter](assignments/week06-container-of/) |
| 7 | File I/O | [PPTX](lectures/week07-file-io/week07-slides.pptx) | [Examples](lectures/week07-file-io/examples/) | [Instructions and starter](assignments/week07-file-io/) |
| 8 | Multi-file Programs and the Final Project | [PPTX](lectures/week08-final-project/week08-slides.pptx) | [Examples](lectures/week08-final-project/examples/) | [Instructions and starter](assignments/week08-final-project/) |

Weeks 03 and 04 each include assignments A and B. Read the assignment's `README.md` first, then complete the TODOs in its `starter/` directory.

## Lecture Notes and Reference PDFs

The [lecture guide](lectures/README.md) links each week's notes, examples, and assignments.
Seven reference PDFs from **C Programming Part 2** are placed beside the relevant weekly decks;
the [reading map](lectures/README.md#reference-pdf-placement) lists their locations and selected pages for each week.
Each week's example guide maps runnable C demos to those PDF pages and includes short exercises.

## Getting Started

You need a C11 compiler (`gcc` or Clang) and `make`.

```bash
git clone https://github.com/seehwan/2026-swcoding.git
cd 2026-swcoding

# Build or run every week's lecture examples with prepared input.
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
- Implement the final project with an intrusive circular doubly linked list and `container_of()`.
- Follow each assignment's requirements and verify that your program compiles and works before submitting.
- Submit source files, the Makefile, and your README; leave out compiled executables.

## Build Notes

The lecture examples build without warnings, except for three demonstration files intentionally left out of the default build: `warnings.c` (Week 01), `precedence_traps.c` (Week 02), and `dangling_local.c` (Week 03).
The Week 02 assignment starter intentionally produces warnings for you to fix.

Week 07 includes a file-based example test:

```bash
make -C lectures/week07-file-io/examples test
```

The [final project assignment](assignments/week08-final-project/README.md) contains the complete requirements and submission checklist.
See also the [project overview](docs/project_overview.md), [grading criteria](docs/grading.md),
and [submission guide](docs/submission.md).
