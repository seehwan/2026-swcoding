# Week 03 — Dynamic Memory and Linked Lists

| | |
|---|---|
| **Session** | Lecture + live coding + lab |
| **Assignment** | [Week 03](../../assignments/week03-linked-list/): labs 03A and 03B in class, assignment 03C to hand in |
| **Demo code** | [`examples/`](examples/) · [Teaching guide](examples/README.md) |
| **Previous / Next** | [Week 02](../week02-operators/) · [Week 04](../week04-file-io-project/) |

Every struct so far has been a local variable. This session creates objects at run time, links them into a list, and then gives every node a second link. The session has two parts; read them in order.

| Part | Notes | Slides | Covers | Practice |
|---|---|---|---|---|
| 1 | [Dynamic Memory and Singly Linked List](part1-dynamic-memory-singly-list.md) | [week03-part1-slides.pptx](week03-part1-slides.pptx) | Global and local variables, nodes and traversal, `malloc()` / `free()`, ownership, insert, delete | Labs 03A and 03B |
| 2 | [Doubly Linked List](part2-doubly-linked-list.md) | [week03-part2-slides.pptx](week03-part2-slides.pptx) | `prev`, `head` and `tail`, invariants, the four cases of delete, debugging links | Assignment 03C |

Reference PDF: [Dynamic Memory Allocation](%5BSlide%5D%2002.%20Dynamic%20Memory%20Allocation.pdf). Each part's notes list the pages to read.

The sentinel and circular-list slides are in a separate deck. They belong to the optional [Extra A](../optional/a-circular-list/), which continues Part 2.

## Build the examples

```bash
make -C lectures/week03-linked-list/examples
make -C lectures/week03-linked-list/examples run
make -C lectures/week03-linked-list/examples clean
```

## After this session you can

- Create a struct with `malloc()`, check the result, and `free()` it exactly once.
- Build, traverse, and free a singly linked list.
- Keep `next`, `prev`, `head`, and `tail` consistent in a doubly linked list, through insert and all four cases of delete.

That doubly linked list is the data structure of the [final project](../../assignments/week04-final-project/).
