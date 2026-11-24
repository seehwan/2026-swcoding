# Lecture Notes

These are the English lecture notes for **C Programming — Linked Lists**. The course runs in **four sessions and an exam**. Each session includes its lab: lecture and live coding, then hands-on work on that session's assignment, then a short wrap-up.

## Sessions

| Session | Notes | Slides | Demo code | Assignment | Makefile topic |
|---|---|---|---|---|---|
| 1 | [Build Tools, Makefile, and `struct`](session1-struct/) | [session1-slides.pptx](session1-struct/session1-slides.pptx) | [examples](session1-struct/examples/) | [Session 1](../assignments/session1-struct/) | `gcc` flags, rules, `make` / `make clean`, variables, `.PHONY` |
| 2 | [Operators and Precedence](session2-operators/) | [session2-slides.pptx](session2-operators/session2-slides.pptx) | [examples](session2-operators/examples/) | [Session 2 (Parts A, B)](../assignments/session2-operators/) | |
| 3 | [Dynamic Memory and Linked Lists](session3-linked-list/): [Part 1](session3-linked-list/part1-dynamic-memory-singly-list.md), [Part 2](session3-linked-list/part2-doubly-linked-list.md) | [part 1](session3-linked-list/session3-part1-slides.pptx), [part 2](session3-linked-list/session3-part2-slides.pptx) | [examples](session3-linked-list/examples/) | [Session 3 (03A, 03B, 03C)](../assignments/session3-linked-list/) | flags are not prerequisites: `make -B` |
| 4 | [File I/O, Multi-file Programs, and the Final Project](session4-file-io-project/): [Part 1](session4-file-io-project/part1-file-io.md), [Part 2](session4-file-io-project/part2-multi-file-project.md) | [part 1](session4-file-io-project/session4-part1-slides.pptx), [part 2](session4-file-io-project/session4-part2-slides.pptx) | [file-io](session4-file-io-project/examples/file-io/), [multi-file](session4-file-io-project/examples/multi-file/) | [Final Project](../assignments/session4-final-project/) | a `test` target with `diff`; `$(SRCS:.c=.o)`, `%.o: %.c`, `$@ $^ $<`, header dependencies |

The [course README](../README.md#schedule) has the dates.

## Optional Extras

[`optional/`](optional/) holds three sets of notes that are **not part of the four sessions and not on the exam**. They continue from Session 3, and they are what a student needs for the final project's intrusive-list extension.

| Extra | Notes | Slides | Demo code | Assignment | Makefile topic |
|---|---|---|---|---|---|
| A | [Circular List with a Sentinel](optional/a-circular-list/) | in the [Session 3 part 2 deck](session3-linked-list/session3-part2-slides.pptx) | [examples](optional/a-circular-list/examples/) | [Extra A](../assignments/optional/a-circular-list/) | `-DNDEBUG` and `assert()` |
| B | [Intrusive Linked List](optional/b-intrusive-list/) | [extra-b-slides.pptx](optional/b-intrusive-list/extra-b-slides.pptx) | [examples](optional/b-intrusive-list/examples/) | [Extra B](../assignments/optional/b-intrusive-list/) | |
| C | [`offsetof()` and `container_of()`](optional/c-container-of/) | [extra-c-slides.pptx](optional/c-container-of/extra-c-slides.pptx) | [examples](optional/c-container-of/examples/) | [Extra C](../assignments/optional/c-container-of/) | `gcc -E` to see macro expansion |

## About the Slides

The PowerPoint decks were made for an earlier, eight-week version of the course, and their title slides still carry the old week numbers. The notes are the reference. In particular, the two Session 4 decks show an intrusive list (`struct list_head`, `container_of()`), while the notes and the final project use the `struct node` list of Session 3.

## Session Structure

Each set of notes follows the same order:

1. Review of the previous material (warm-up questions)
2. Lecture sections with live demos and live coding
3. Lab — the assignment, with a test plan and stretch goals
4. Wrap-up — key takeaways and exit quiz

Session 1 spends more of its time on the toolchain and the Makefile. Sessions 3 and 4 each have two sets of notes, Part 1 and Part 2. Session 4 runs its lab as the project kickoff.

## Reference PDF Placement

The seven reference PDFs from **C Programming Part 2** are stored beside the
lecture decks below. Their original chapter numbers identify the source
material, not this course's session numbers. The PDFs retain their original
contents and filenames.

| Reference PDF | Pages | Primary location | Main use |
|---|---:|---|---|
| [01. Pointers Revisited](session1-struct/%5BSlide%5D%2001.%20Pointers%20Revisited.pdf) | 51 | Session 1 | Address, indirection, and pointer parameters first; revisit arrays, `**`, and callbacks later. |
| [05. Structures, Unions and Enums](session1-struct/%5BSlide%5D%2005.%20Structures%2C%20Unions%20and%20Enums.pdf) | 49 | Session 1 | Structure values and member access first; allocation, unions, and tagged variants later. |
| [03. Strings](session2-operators/%5BSlide%5D%2003.%20Strings.pdf) | 82 | Session 2 | Character arrays, pointer traversal, and string operations before allocating and linking books. |
| [06. Low Level Operations](session2-operators/%5BSlide%5D%2006.%20Low%20Level%20Operations.pdf) | 25 | Session 2 | Bitwise operators, precedence, and flags; revisit bit-fields and byte order in Extra C. |
| [02. Dynamic Memory Allocation](session3-linked-list/%5BSlide%5D%2002.%20Dynamic%20Memory%20Allocation.pdf) | 30 | Session 3 | Storage layout, allocation, release, failure handling, and dangling pointers. |
| [04. File IO](session4-file-io-project/%5BSlide%5D%2004.%20File%20IO.pdf) | 62 | Session 4 | Streams, file lifetime, text parsing, and persistence; binary I/O and positioning as extensions. |
| [07. Writing Large Programs](session4-file-io-project/%5BSlide%5D%2007.%20Writing%20Large%20Programs.pdf) | 41 | Session 4 | Separate compilation, headers, shared declarations, and modules; use macro excerpts earlier. |

Each reference PDF is stored in exactly one lecture directory: the most closely
related session listed above. Other notes link to that single copy when
revisiting selected pages. The pointer and structure PDFs are placed in
Session 1. All seven PDFs preserve their original contents and filenames.

### Reading order and revisits

Page ranges below are **one-based PDF page numbers**, which match the printed
slide numbers. They are selected reading alongside the course decks, not a
requirement to present every page in a single session. Each set of notes links
the relevant PDFs and existing runnable examples.

| Notes | Selected reference reading | Teaching purpose |
|---|---|---|
| [Session 1](session1-struct/README.md#reference-slide-reading) | Pointers pp. 3-12; Structures pp. 3-22, 24-30; Strings pp. 3-14 as a short reference for `title[]`. Enums pp. 40-45 are an optional preview. | Build tools, book records, value copying, pointer parameters, and null-terminated title storage. |
| [Session 2](session2-operators/README.md#reference-slide-reading) | Strings pp. 3-14, 26-34, 49-63, 74-81; Low Level pp. 2-19; Pointers pp. 13-16, 20-23, 27-39; Large Programs pp. 8-10, 14-15. | Read pointer expressions and loops, understand strings and arrays, set/test flags, and parenthesize macros. Matrix interfaces and extra library functions are extensions. |
| [Session 3, Part 1](session3-linked-list/part1-dynamic-memory-singly-list.md#reference-slide-reading) | Dynamic Memory pp. 2-27, optionally 28-29; Pointers pp. 17-19, 25-26; Structures p. 23; Strings pp. 13-14, 49-60, 68-72. | Establish allocation and ownership before creating linked-list nodes; distinguish copies of arrays from copies of pointer values. |
| [Session 3, Part 2](session3-linked-list/part2-doubly-linked-list.md#reference-slide-reading) | Dynamic Memory pp. 25-27; Pointers pp. 25-26. | Review lifetime and changing a head pointer. The linked-list deck is primary. [Extra A](optional/a-circular-list/README.md#reference-slide-reading) adds Large Programs pp. 16-18 for conditional compilation with invariant checks. |
| [Extra B](optional/b-intrusive-list/README.md#reference-slide-reading) | Structures pp. 21-27; Pointers pp. 17-19; Dynamic Memory pp. 25-27. | Review embedded members, generic object pointers, and one owner before intrusive lists. The existing linked-list deck is primary. |
| [Extra C](optional/c-container-of/README.md#reference-slide-reading) | Low Level pp. 20-24; Pointers pp. 13-19; Strings pp. 68-72; Large Programs pp. 6-10, 14-18. Optional: Structures pp. 32-47, Pointers pp. 41-50, Large Programs pp. 11-13, 19-20. | Connect layout and byte arithmetic to `offsetof()` and `container_of()`; revisit bit-fields, byte order, macros, and optional variants/callbacks. |
| [Session 4, Part 1](session4-file-io-project/part1-file-io.md#reference-slide-reading) | File IO pp. 3-52, 61; Strings pp. 15-25, 37-48, 64-67, 73; Low Level pp. 22-24. File IO pp. 53-60 are optional binary/positioning extensions. | Read and parse complete lines, manage streams, and persist payload data rather than live pointer values. |
| [Session 4, Part 2](session4-file-io-project/part2-multi-file-project.md#reference-slide-reading) | Large Programs pp. 21-40; pp. 3-20 as preprocessor review. Revisit File IO pp. 17-29, 41-61 as needed. | Split the final project into interfaces and implementations, link it, and integrate input and persistence. |

Session 3 and the extras use the course's own list lectures: the reference PDFs supply
language prerequisites and do not replace singly, doubly, circular, or intrusive
list instruction. Historical/nonportable code in the reference PDFs should be
discussed alongside the C11 notes and runnable examples; for example, use
`fgets()` for the Strings slides' `gets()` comparison.

## Conventions

- **Live demo** marks code to run in class. Every demo is in that session's `examples/` directory.
- **In-class exercises** and **exit quizzes** have their answers in collapsed `<details>` blocks.
- **Lecture demos use `struct book`, and assignments use `struct student`.** The notes show the mechanism; students carry it over to their own code in the lab. Assignment deliverables (for example search, delete, and backward traversal) are left as design exercises.
- All demo code is C11 and builds with `gcc -Wall -Wextra -std=c11` and **zero warnings**. The exceptions are three files that exist to show warnings: `session1-struct/examples/warnings.c`, `session2-operators/examples/precedence_traps.c`, and `session3-linked-list/examples/dangling_local.c`. Their Makefiles do not build them.
- The Session 2 assignment starter (Part A) produces three warnings **on purpose**. Fixing them is part of the task. Part B is built with warnings off.

## Building the Examples

```bash
make -C lectures                                   # build every session and extra
make -C lectures run                               # run all demos with prepared input
make -C lectures clean                             # clean everything
make -C lectures/session1-struct/examples          # build one session's demos
make -C lectures/session1-struct/examples run      # run core demos and both PDF supplements
make -C lectures/session1-struct/examples clean    # remove the executables
make -C lectures/session4-file-io-project/examples test    # Session 4: run the file-based tests
```

The [Session 1 example guide](session1-struct/examples/README.md) includes supplements
for **Pointers Revisited** and **Structures, Unions and Enums**. Their READMEs map
the runnable code to the reference PDF pages and suggest when to revisit each
topic during Sessions 1, 2, and 3, and Extra C.

### Examples added from the reference PDFs

The later sessions have their own example guides with PDF page mappings, expected
observations, and short prediction/modification exercises. Each directory's `make`
builds the examples and `make run` supplies fixed arguments or prepared input,
so all demos can be run without typing at the keyboard.

| Notes | Example guide | Added focus |
|---|---|---|
| Session 2 | [Strings and bit operations](session2-operators/examples/README.md) | Writable string storage, capacity checks, comparisons/search, pointer scans and command-line arguments, packed bit fields. |
| Session 3 | [Allocation and ownership](session3-linked-list/examples/README.md) | Safe resizing, runtime matrix allocation and cleanup, owned title replacement and append. |
| Extra A | [Invariants and build modes](optional/a-circular-list/examples/README.md) | Always-on validation versus `assert()`, `NDEBUG`, and conditional diagnostics. |
| Extra B | [Borrowed intrusive membership](optional/b-intrusive-list/examples/README.md) | Link membership and payload ownership with books owned outside the list. |
| Extra C | [Layout and representation](optional/c-container-of/examples/README.md) | Object bytes and byte order, overlap-aware copying, and bit-fields versus addressable members. |
| Session 4, Part 1 | [Streams, parsing, and positioning](session4-file-io-project/examples/file-io/README.md) | Line/block copying, binary records with an explicit format, file positions, and validated line parsing. |
| Session 4, Part 2 | [Preprocessing and complete modules](session4-file-io-project/examples/multi-file/README.md) | Macro expansion and conditional compilation, guarded interfaces, one shared definition, private helpers, and header dependencies. |

The Session 4 `stats_demo` keeps its intentional header-dependency exercise;
the additional module example shows a complete working build beside it.
Compiler flags are not prerequisites, so use `-B` when changing them:

```bash
make -B -C lectures CFLAGS='-std=c11 -Wall -Wextra -Wpedantic -Werror'
make -C lectures run
make -C lectures clean
```

The outputs shown in the notes were captured on macOS (Apple Clang, GNU Make 3.81). Addresses change from run to run. On Linux, gcc words some messages differently, and newer GNU Make quotes names as `'name'` instead of `` `name' ``.
