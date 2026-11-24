# Session 4, Part 2 — Multi-file Programs and the Final Project

| | |
|---|---|
| **Session** | Lecture + live coding + project lab |
| **Assignment** | [Final Project: Student Management System](../../assignments/session4-final-project/) |
| **Demo code** | [`examples/multi-file/`](examples/multi-file/) |
| **Previous** | [Part 1 — File I/O](part1-file-io.md) |

## Reference slide reading

Use [Writing Large Programs](%5BSlide%5D%2007.%20Writing%20Large%20Programs.pdf)
(41 pages). All page numbers below are one-based PDF pages. The primary
reading is **pp. 21-40**, in this teaching order:

1. Review the build pipeline on pp. 22-23, then split responsibilities and
   share declarations using pp. 24-31.
2. Apply include guards from pp. 35-37 before building the multi-file
   [`examples/`](examples/multi-file/) program. Connect pp. 38-40 on modules, cohesion,
   and coupling to the project's list/student/menu layers.
3. Read pp. 32-34 on `extern` as declaration/definition background; the final
   project's list head still belongs in `main()`.

See the [example guide](examples/multi-file/README.md) for preprocessor experiments
and a complete book module; run `make -C examples/multi-file run`. The stats dependency
exercise remains available.

Use **pp. 3-20** as a preprocessor recap: pp. 3-7 introduce directives and
constants, pp. 8-15 explain macro expansion and pitfalls, and pp. 16-20 cover
conditional compilation and diagnostics. Review operators before macros and
function prototypes before sharing interfaces.

Revisit [File I/O](%5BSlide%5D%2004.%20File%20IO.pdf)
**pp. 17-29, 41-52, 61** for file lifetime, input, parsing, and buffering, and
the [Session 3 ownership notes](../session3-linked-list/part1-dynamic-memory-singly-list.md)
before implementing creation, deletion, and cleanup.

At pp. 17-18, `#ifdef DEBUG` remains true when `DEBUG` is defined as `0`;
`#if DEBUG` tests its numeric value. Include guards prevent repeated inclusion
within one translation unit; they do not fix duplicate external definitions
across separately compiled files.

## Learning Objectives

By the end of this session you can:

1. Split a program into headers (interfaces) and source files (implementations), with include guards.
2. Compile each `.c` file separately and link the object files, by hand and with `make`.
3. Tell a compile error from a link error, and fix both.
4. Read every line of the final project's Makefile: `$(SRCS:.c=.o)`, `%.o: %.c`, `$@`, `$^`, `$<`.
5. Explain why editing a header does not trigger a rebuild with the starter Makefile, and fix it.
6. Apply Part 1's robust input handling and file-based testing to the project.
7. Lay out the final project in two layers with clear responsibilities.

---

## 0. Review: the Whole Course in One Struct

```c
struct student {                /* Session 1: a struct                                */
    int id;
    char name[20];              /* Session 2: at most 19 characters + '\0'            */
    int score;
};

struct node {                   /* Session 3: created with malloc(), linked by next   */
    struct student data;
    struct node *next;
    struct node *prev;          /* Session 3: the second link                         */
};

struct student_list {           /* Session 3: the list remembers both ends            */
    struct node *head;
    struct node *tail;
};

if (n != NULL && n->data.id == id)      /* Session 2: check, then use, in one condition */
```

The intrusive version of this list (`struct list_head` inside `struct student`, with `container_of()`) is the project's optional extension; see Extras B and C.

Ask the class: for each line, which session explained it, and what bug does it prevent?

---

## 1. Programs Made of Several `.c` Files

### 1.1 Why split a program?

- **Separation of concerns.** `student.c` knows the list and the file, and `main.c` talks to the user.
- **Readability.** Each file is short enough to understand on its own.
- **Faster rebuilds.** Change `student.c`, and only `student.c` is recompiled.
- **Reuse.** Another program, for example a test program, can link the same `student.c`.

### 1.2 The final project's files

```text
main.c      ──#include──►  student.h
student.c   ──#include──►  student.h
```

| File | Contains |
|---|---|
| `student.h` | `struct student`, `struct node`, `struct student_list`, and the function prototypes |
| `student.c` | `list_init()`, `student_add()`, `student_find()`, `student_delete()`, printing, counting, loading, saving, freeing |
| `main.c` | The menu loop and keyboard input |

### 1.3 What goes in a header, and what does not

| Put in a `.h` (the interface) | Put in a `.c` (the implementation) |
|---|---|
| `struct` definitions that several files need | Function **definitions** (the bodies) |
| Function **prototypes** (declarations) | `static` helper functions used only in that file |
| Macros and constants | Variables |
| An include guard | |

**Never define a function or a variable in a header.** Every `.c` that includes the header gets its own copy, and the linker reports a *duplicate symbol*.

`#include "student.h"` (quotes) searches your project directory first. `#include <stdio.h>` (angle brackets) searches only the system directories.

### 1.4 Include guards

A header is often included twice in one `.c` file: once directly, and once through another header. Without a guard, every struct in it is defined twice:

```text
student.h:2:8: error: redefinition of 'struct student'      (gcc; student.h with its guard deleted, included twice)
```

The starter's headers already use the standard guard:

```c
#ifndef STUDENT_H
#define STUDENT_H

/* ... contents ... */

#endif
```

The first inclusion defines `STUDENT_H`. Every later inclusion finds it already defined and skips the whole file.

### 1.5 Separate compilation and linking

```text
main.c    ──gcc -c──►  main.o    ┐
                                 ├── gcc (link) ──►  student_manager
student.c ──gcc -c──►  student.o ┘
```

By hand:

```bash
gcc -Wall -Wextra -std=c11 -c main.c    -o main.o
gcc -Wall -Wextra -std=c11 -c student.c -o student.o
gcc -Wall -Wextra -std=c11 -o student_manager main.o student.o
```

- `-c` means "compile only, don't link". The result is an **object file** (`.o`): machine code with unresolved references to functions in other files.
- The final command **links** the object files, connecting each call to its definition.
- `gcc -Wall -Wextra -std=c11 main.c student.c -o student_manager` does all three steps at once, but it recompiles everything every time.

### 1.6 Compile errors vs. link errors

| | Compile error | Link error |
|---|---|---|
| When | Compiling **one** `.c` file | Combining the `.o` files |
| Typical message | `main.c:12:5: error: ...` (has a file and line) | macOS ld: `Undefined symbols for architecture arm64: "_student_add"`<br>GNU ld (Linux): `undefined reference to 'student_add'` |
| | | macOS ld: `duplicate symbol '_f' in: a.o b.o`<br>GNU ld (Linux): `multiple definition of 'f'` |
| Typical cause | Syntax, types, missing `#include` | A `.c` file not compiled or not linked; a name misspelled between prototype and definition; a function defined in a header |

**Live demo:** link the multi-file example **without** `stats.c`:

```bash
cd lectures/session4-file-io-project/examples/multi-file
gcc -Wall -Wextra -std=c11 main.c -o broken
```

```text
Undefined symbols for architecture arm64:
  "_stats_add", referenced from:
      _main in main-8f203c.o
  "_stats_init", referenced from:
      _main in main-8f203c.o
  "_stats_print", referenced from:
      _main in main-8f203c.o
ld: symbol(s) not found for architecture arm64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
```

On Linux, GNU ld reports the same three symbols as `undefined reference to 'stats_init'`, and so on.

`main.c` compiled fine, because the prototypes in `stats.h` satisfied the compiler. Only the linker noticed that the definitions were missing.

### 1.7 `static` functions are file-private

```c
static void print_menu(void)     /* in main.c: other files cannot call it */
```

Mark every helper that is not part of a header's interface as `static`. Then it cannot clash with a same-named function in another file, and readers know it is only used in this file.

---

## 2. The Final Project's Makefile, Line by Line

[`assignments/session4-final-project/starter/Makefile`](../../assignments/session4-final-project/starter/Makefile), unchanged:

```make
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = student_manager

SRCS = main.c student.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
```

| Line | Meaning |
|---|---|
| `SRCS = main.c student.c` | The list of source files. |
| `OBJS = $(SRCS:.c=.o)` | **Substitution reference:** the same list with `.c` replaced by `.o`, giving `main.o student.o`. |
| `$(TARGET): $(OBJS)` | The executable depends on both object files. |
| `$(CC) $(CFLAGS) -o $@ $^` | Link: `$@` is the target, `$^` is all the prerequisites. |
| `%.o: %.c` | **Pattern rule:** "any `X.o` is built from `X.c`". One rule serves every source file. |
| `$(CC) $(CFLAGS) -c $< -o $@` | Compile: `$<` is the **first** prerequisite (`X.c`), `$@` is `X.o`. |
| `clean` | Removes the object files and the executable. |
| `.PHONY: all clean` | `all` and `clean` are actions, not files (Session 1, §2.6). |

### 2.1 Automatic variables

| Variable | Means | In `$(TARGET): $(OBJS)` | In `%.o: %.c` (building `student.o`) |
|---|---|---|---|
| `$@` | the target | `student_manager` | `student.o` |
| `$^` | all prerequisites | `main.o student.o` | `student.c` |
| `$<` | the first prerequisite | `main.o` | `student.c` |

### 2.2 Watching incremental builds

**Live demo** — [`examples/`](examples/multi-file/) has the same Makefile shape with `main.c`, `stats.c`, and `stats.h`:

```bash
cd lectures/session4-file-io-project/examples/multi-file
make
```

```text
gcc -Wall -Wextra -std=c11 -c main.c -o main.o
gcc -Wall -Wextra -std=c11 -c stats.c -o stats.o
gcc -Wall -Wextra -std=c11 -o stats_demo main.o stats.o
```

```bash
touch stats.c
make
```

```text
gcc -Wall -Wextra -std=c11 -c stats.c -o stats.o
gcc -Wall -Wextra -std=c11 -o stats_demo main.o stats.o
```

Only `stats.o` was recompiled, and then everything was relinked. `main.o` was reused.

`make run` runs the program with `numbers.txt` as its input:

```text
== Score statistics ==
count   : 5
min/max : 64 / 99
average : 82.00
```

### 2.3 The header gotcha

**Live demo:** change the title macro in `stats.h`:

```c
#define STATS_TITLE "Exam statistics"
```

```bash
make
```

```text
make: Nothing to be done for `all'.
```

```text
== Score statistics ==       ← the OLD title: the program was not rebuilt
```

Why? The rule `%.o: %.c` says `stats.o` depends on `stats.c` only. `make` has no idea that `stats.c` includes `stats.h`.

This is more dangerous than a stale title. Suppose you add a member to `struct student` in `student.h` and also edit `main.c`. Then only `main.o` is rebuilt. `main.o` and `student.o` now disagree about the **layout** of `struct node`: one of them looks for `next` at an offset where the other stored something else. You get corrupted data with no error message.

**Fix 1 (always works):** after editing any header, run

```bash
make clean && make
```

**Fix 2 (better): list the header dependencies.** A rule with no recipe just adds prerequisites, and the pattern rule still supplies the recipe. In `examples/Makefile`, uncomment:

```make
main.o stats.o: stats.h
```

For the final project:

```make
main.o student.o: student.h
```

`$<` is still the `.c` file, because the pattern rule's prerequisite comes first.

> **Going further (optional):** `gcc -MMD -MP` writes a `.d` file listing each object's headers, and `-include $(OBJS:.o=.d)` in the Makefile reads them, so dependencies are generated automatically. If you use it, also delete the `.d` files in `clean`.

---

## 3. Project Architecture and Test Plan

### 3.1 Two layers

```text
+--------------------------------------------------------------+
| main.c      menu loop, keyboard input, printing messages     |  uses: the student API
+--------------------------------------------------------------+
| student.c   add / find / delete / print / count / free       |  owns: next and prev,
|             load / save                                      |        malloc/free, FILE *
+--------------------------------------------------------------+
```

`main.c` never touches `next` or `prev`, and `student.c` never reads the keyboard. If you keep that line, you can test all of `student.c` from a small test program with no menu.

### 3.2 Responsibilities

These come from the [project specification](../../assignments/session4-final-project/README.md):

| Function | Does | Does **not** |
|---|---|---|
| `list_init(list)` | `head = tail = NULL` | |
| `student_add(list, id, name, score)` | validate, `malloc()`, fill in the fields, link at the **tail** | print |
| `student_find(list, id)` | Traverse from `head`, return the node or `NULL` | change the list |
| `student_delete(list, id)` | find → unlink → `free()`, return success/failure | leave `head` or `tail` pointing at the freed node |
| `student_load(list, path)` | `fopen()` → `fgets()` + `sscanf()` → `student_add()` → `fclose()` | stop at the first bad line |
| `student_save(list, path)` | `fopen(path, "w")` → `fprintf()` per node → `fclose()` | write pointer values |
| `student_free_all(list)` | Read `next`, then free, for every node; reset `head` and `tail` | use a node after `free()` |

- The list is a **local variable in `main()`**. The spec forbids global storage.
- `student_add()` links at the **tail**, so list order is file order. That is what makes the round trip (save → load → save) produce the same file.
- `student_load()` calls `student_add()`, so a line in the file gets exactly the same checks as a student typed at the keyboard.

### 3.3 The "Add Student" flow

```text
read ID, name, score (the starter does this) ──any one bad──► "Error: Invalid input."
   │ok
   ▼
id > 0  and  0 ≤ score ≤ 100 ? ──no──► "Error: Invalid ID or score."
   │yes
   ▼
student_find(&list, id) != NULL ? ──yes──► "Error: Student ID already exists."
   │no
   ▼
student_add(&list, id, name, score) ──► -1? ──► "Error: Out of memory."
```

`student_add()` repeats the first two checks itself, because `student_load()` relies on them. `main.c` checks first only so that it can print a specific message.

### 3.4 Input handling and testing

The starter's `main.c` applies Part 1 for you. Read `read_line()`, `read_int()`, and `read_name()` before you write anything:

- Every input is **one whole line**, read with `fgets()` and parsed with `sscanf()` ([Part 1, §2.3](part1-file-io.md#23-loading-fgets--sscanf-one-line-at-a-time)). A bad line is simply rejected; nothing is left behind in the input.
- The name is limited to 19 characters for `char name[20]`.
- End of input (`EOF`) at any prompt works like Exit: save, free everything, and exit normally.
- Replay tests with `./student_manager data.txt < test1.txt`, and compare with `diff` ([Part 1, §2.6](part1-file-io.md#26-testing-with-files)).

Each test file is the sequence of lines you would type. This one adds a student, tries a duplicate ID, prints, and exits:

```text
1
1
Alice
95
1
1
Bob
70
4
8
```

Use a **scratch data file** for tests, not `students.txt`: Exit saves the list, so a test run rewrites its data file.

Test cases to cover:

| Area | Cases |
|---|---|
| Empty list | Print forward/backward, count, search, delete |
| Add | Normal add; duplicate ID; ID ≤ 0; score < 0 or > 100; name longer than 19 characters |
| Delete | First, middle, last, only student; ID not found. Print both ways after each. |
| Order | Forward is exactly the reverse of backward |
| Input | Letters instead of numbers in the menu and in each field; end of input (EOF) in the middle of "Add" |
| Load | The given `students.txt` (3 students, 2 messages); a file that does not exist; an empty file; a file with a duplicate ID |
| Save | Save → load → save gives the same file; save an empty list |
| Exit | With 0 students and with several. Afterwards `head` and `tail` are `NULL`. |

Check for leaks by reasoning, as in Session 3: every `malloc()` in `student_add()` must be matched by exactly one `free()`, either in `student_delete()` or in `student_free_all()`. While developing, a temporary live-node counter makes this visible.

---

## 4. Lab — Project Kickoff

Task: [assignments/session4-final-project/README.md](../../assignments/session4-final-project/README.md). Read the whole specification first.

| Milestone | Goal | Done when |
|---|---|---|
| **M0** | Copy `starter/` into your submission directory (`<student_id>_<name>/`). Run `make` and `./student_manager`, then choose 8. | The untouched starter builds with zero warnings and exits cleanly. |
| **M1** | `list_init()`, `student_add()`, `student_print()`, `student_print_all()`. | Menu 1 and 4 work: add three students and print them. |
| **M2** | `student_print_reverse()`, `student_count()`, `student_find()`, Search, and the duplicate check. | Backward is the exact reverse of forward; a duplicate ID is refused. |
| **M3** | `student_delete()`. | All four positions work, and both prints are right after each. |
| **M4** | `student_save()` and `student_free_all()`. | Exit writes a file you can read in an editor. |
| M5 (at home) | `student_load()`, with bad lines reported and skipped. | `students.txt` loads 3 students with 2 messages, and the round trip gives the same file. |
| M6 (at home) | Header dependencies in the Makefile, test input files, and the README. | Everything in the final checklist is ticked. |

Rebuild after **every** function. Never write more than about 20 lines without compiling.

---

## 5. Wrap-up

### Submission checklist

From [docs/submission.md](../../docs/submission.md) and the [final checklist](../../assignments/session4-final-project/README.md#14-final-checklist):

- [ ] `main.c`, `student.h`, `student.c`, `students.txt`, `Makefile`, `README.md`. No executable, no `.o` files (`make clean`).
- [ ] Builds with `gcc -Wall -Wextra -std=c11` and **zero warnings**.
- [ ] No student array, no global list, no external list library.
- [ ] Every node is created with `malloc()` and freed exactly once.
- [ ] `next`, `prev`, `head`, and `tail` are correct after every add and delete.
- [ ] The data file is loaded at start and saved at exit, and the round trip gives the same file.
- [ ] The README covers: how to run it, the features, the data structures with a picture, the four cases of delete, how bad lines are handled, and the problems you solved.

### Key takeaways

- Headers declare, and `.c` files define. Include guards prevent double definitions.
- `gcc -c` compiles one file, and linking connects the pieces. A link error means a definition is missing (or duplicated), not a syntax problem.
- `$(SRCS:.c=.o)`, `%.o: %.c`, `$@`, `$^`, and `$<` let one short Makefile build any number of files.
- `make` knows only the dependencies you tell it. After editing a header, `make clean && make`, or list the headers as prerequisites.
- Check every `scanf()` return value, give every `%s` a width, and test with `< input.txt`.

### Final quiz

1. You edited `student.h` and `make` says *Nothing to be done*. Why, and what do you do?
2. In `$(TARGET): $(OBJS)`, what do `$@` and `$^` expand to?
3. `main.c` compiles, but linking reports `undefined reference to 'student_find'`. Name two possible causes.
4. Why is `scanf("%s", name)` dangerous, and what do you write instead?
5. Which file is allowed to call `free()` on a node: `student.c` or `main.c`?

<details>
<summary>Answers</summary>

1. The pattern rule makes each `.o` depend only on its `.c`, so `make` does not know about the header. Run `make clean && make`, or add the header prerequisites to the Makefile.
2. `student_manager`, and `main.o student.o`.
3. `student.c` was not compiled or linked (for example, it is missing from `SRCS`), or the function's name is misspelled in `student.c`, or it is defined `static` there. (A mismatched signature is a compile error instead, *conflicting types*, because `student.c` includes `student.h`.)
4. A name longer than the array overflows it. Use `scanf("%19s", name)` for `char name[20]`.
5. `student.c` (in `student_delete()` and `student_free_all()`). `main.c` goes through the student API and never sees a node being freed.

</details>

Good luck with the project.
