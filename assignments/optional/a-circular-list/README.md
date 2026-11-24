# Extra A — Circular Doubly Linked List

> **Optional.** This assignment is not required and is not part of the grade. It goes with the [Extra A notes](../../../lectures/optional/a-circular-list/), and it continues [assignment 03C](../../session3-linked-list/): it keeps the two links of 03C and replaces every `NULL` end with a sentinel.

## Learning Objectives

- Understand a circular list that uses a sentinel instead of `NULL`.
- Understand the invariant of the empty list.
- Insert and unlink with no special cases.

## Assignment

Starting from `starter/extra_a.c`, write a **circular doubly linked list that uses a sentinel `head`**.

### Empty List Invariant

In an empty list, these conditions must always be true:

```c
head.next == &head;
head.prev == &head;
```

When you traverse the list, the node after the last node is `&head`, not `NULL`.

### Requirements

- Use a sentinel `head`.
- Keep both `next` and `prev` correct.
- Write Insert and Delete.
- Write forward and backward traversal.
- Always test the empty list and a list with one element.

### Checklist

- [ ] The empty-list invariant always holds.
- [ ] `next` and `prev` are correct after Insert.
- [ ] `next` and `prev` are correct after Delete.
- [ ] Forward traversal works.
- [ ] Backward traversal works.
- [ ] All nodes are freed with `free()` before the program ends.

## Build

```bash
cd starter
gcc -Wall -Wextra -std=c11 extra_a.c -o extra_a
./extra_a
```

## Makefile

```bash
cd starter
make
./extra_a
make clean
```
