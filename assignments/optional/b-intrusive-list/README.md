# Extra B — Intrusive Linked List

> **Optional.** This assignment is not required and is not part of the grade. It goes with the [Extra B notes](../../../lectures/optional/b-intrusive-list/). Do it, after Extra A, if you take the final project's intrusive-list extension.

## Learning Objectives

- Understand how to build a linked list without a separate `struct node`.
- Write an intrusive list, where each data object contains a `struct list_head`.
- Think of the list links and the real data object as separate things.

## Assignment

In `starter/extra_b.c`, use these structures:

```c
struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct student {
    int id;
    char name[20];
    int score;
    struct list_head list;
};
```

Do not create a separate `struct node`. Use `student.list` as the list node.

## Requirements

- Put a `struct list_head list` inside each student.
- Use a sentinel `head`.
- Keep the list a circular doubly linked list.
- Do not add a `struct node`.

## Build

```bash
cd starter
gcc -Wall -Wextra -std=c11 extra_b.c -o extra_b
./extra_b
```

## Checklist

- [ ] I did not create a `struct node`.
- [ ] I used `student.list`.
- [ ] The list stays circular.
- [ ] I wrote forward and backward traversal.
- [ ] All students are freed with `free()` before the program ends.

## Makefile

```bash
cd starter
make
./extra_b
make clean
```
