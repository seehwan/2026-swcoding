# Week 04 — File I/O, Multi-file Programs, and the Final Project

| | |
|---|---|
| **Session** | Lecture + live coding + project lab |
| **Assignment** | [Final Project: Student Management System](../../assignments/week04-final-project/) |
| **Demo code** | [`examples/file-io/`](examples/file-io/) · [`examples/multi-file/`](examples/multi-file/) |
| **Previous** | [Week 03](../week03-linked-list/) |

The list from Week 03 disappears when the program exits. This session saves it to a file and loads it back, splits the program into several source files, and starts the final project. The session has two parts; read them in order.

| Part | Notes | Slides | Covers | Examples |
|---|---|---|---|---|
| 1 | [File I/O](part1-file-io.md) | [week04-part1-slides.pptx](week04-part1-slides.pptx) | Streams, `fopen()` / `fclose()`, `fgets()` + `sscanf()`, saving and loading a list, testing with files | [file-io](examples/file-io/README.md) |
| 2 | [Multi-file Programs and the Final Project](part2-multi-file-project.md) | [week04-part2-slides.pptx](week04-part2-slides.pptx) | Headers and include guards, separate compilation, the project Makefile, project architecture and test plan | [multi-file](examples/multi-file/README.md) |

Reference PDFs: [File IO](%5BSlide%5D%2004.%20File%20IO.pdf) for Part 1 and [Writing Large Programs](%5BSlide%5D%2007.%20Writing%20Large%20Programs.pdf) for Part 2. Each part's notes list the pages to read.

Both decks use the `struct node` list of Week 03, the same list as the notes and the final project.

## Build the examples

```bash
make -C lectures/week04-file-io-project/examples          # both sets
make -C lectures/week04-file-io-project/examples run
make -C lectures/week04-file-io-project/examples test     # the file-based tests of Part 1
make -C lectures/week04-file-io-project/examples clean
```

## After this session you can

- Open, read, write, and close a text file, and handle each failure.
- Save a linked list as text and rebuild it from the file.
- Split a program into a header and source files, and build it with `make`.
- Start the [final project](../../assignments/week04-final-project/) from its starter and finish it step by step.
