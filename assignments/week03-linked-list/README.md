# Week 03 — Dynamic Memory and Linked Lists

This session has three parts. **03A** and **03B** are the in-class lab. **03C** is the assignment to hand in. Do them in order: the singly linked list in 03B is built from the heap-allocated nodes of 03A, and 03C adds a second link to 03B.

| Part | File | Topic | When |
|---|---|---|---|
| 03A | `starter/assignment_03a.c` | Dynamic memory | Lab, in class |
| 03B | `starter/assignment_03b.c` | Singly linked list | Lab, in class |
| 03C | `starter/assignment_03c.c` | Doubly linked list | Assignment, hand in |

Lecture notes: [Week 03, Part 1](../../lectures/week03-linked-list/part1-dynamic-memory-singly-list.md) for 03A and 03B, and [Part 2](../../lectures/week03-linked-list/part2-doubly-linked-list.md) for 03C.

## Learning Objectives

- Understand the difference between the stack and the heap.
- Create a student at run time with `malloc()`, and release it with `free()`.
- Build a linked list from nodes and pointers, and traverse it by following `next`.
- Write the basic operations: insert, search, and delete.
- Keep `next` and `prev` correct at the same time, and traverse in both directions.
- When you delete a node, fix the links on both sides of it.

## 03A — Dynamic Memory (lab)

In `starter/assignment_03a.c`, use `malloc()` to create one student at run time, store its information, and print it.

### Requirements

1. Allocate the memory with `malloc(sizeof(*student))`, the idiom from the lecture (`malloc(sizeof(struct student))` also works).
2. Check whether `malloc()` failed.
3. Store the student's information and print it.
4. Always `free()` the memory before the program ends.

### Checklist

- [ ] I used `malloc()`.
- [ ] I handled allocation failure.
- [ ] I used a pointer to the student.
- [ ] I called `free()`.
- [ ] There are no compiler warnings.

## 03B — Singly Linked List (lab)

Use `struct node` in `starter/assignment_03b.c` to write a singly linked list.

Write at least these operations:

- Insert
- Search by ID
- Delete by ID
- Print

### Requirements

- Every node has a `next` pointer.
- When the list is empty, `head == NULL`.
- When you delete a node that you created with `malloc()`, `free()` it.
- Free the whole list before the program ends.

### Checklist

- [ ] Insert
- [ ] Search
- [ ] Delete
- [ ] Print
- [ ] Every deleted node is freed with `free()`
- [ ] All nodes are freed with `free()` before the program ends

## 03C — Doubly Linked List (assignment)

Complete `starter/assignment_03c.c` to write a doubly linked list. This is the list the [final project](../week04-final-project/) uses, so what you write here carries over.

### Requirements

- Every node has both `next` and `prev`.
- Write Insert and Delete by ID.
- Write Forward Print.
- Write Backward Print.
- When you delete a node, fix the links of the nodes before and after it.
- Test delete on the first node, the last node, a middle node, and the only node. Print in both directions after each.
- Free the whole list before the program ends.

### Checklist

- [ ] The `next` links are correct.
- [ ] The `prev` links are correct.
- [ ] Forward traversal works.
- [ ] Backward traversal works, and is the exact reverse of forward.
- [ ] The links are still correct after deleting the first, last, middle, and only node.
- [ ] All nodes are freed with `free()` before the program ends.
- [ ] There are no compiler warnings.

## Build

```bash
cd starter
gcc -Wall -Wextra -std=c11 assignment_03a.c -o week03a
./week03a
gcc -Wall -Wextra -std=c11 assignment_03b.c -o week03b
./week03b
gcc -Wall -Wextra -std=c11 assignment_03c.c -o week03c
./week03c
```

## Makefile

`make` builds all three programs.

```bash
cd starter
make
./week03a
./week03b
./week03c
make clean
```

Going further: [Extra A](../optional/a-circular-list/) (optional) removes every `NULL` special case from 03C with a sentinel node.
