# Project Overview

## Goal

The goal of this project is not to memorize a linked list API. It is to understand how the core ideas of C connect inside one program: a struct, pointers to it, memory you allocate and free yourself, links between objects, and a file that outlives the program.

## Schedule

The course runs in four sessions and ends with an exam.

| Session | Week of | Topic | Key Concepts | Materials |
|---|---|---|---|---|
| 1 | — | Build tools and struct | `gcc`, `make`, `struct`, pointer | [Session 1](../lectures/session1-struct/) |
| 2 | Nov 23 | Operators and precedence | precedence, short-circuit, bit flags, strings | [Session 2](../lectures/session2-operators/) |
| 3 | Nov 30 | Dynamic memory and linked lists | `malloc()`, `free()`, `next`, `prev`, `head`, `tail`, traversal | [Session 3](../lectures/session3-linked-list/), Parts 1 and 2 |
| 4 | Dec 7 | File I/O and multi-file programs | `fopen()`, `fgets()`, `sscanf()`, headers, separate compilation | [Session 4](../lectures/session4-file-io-project/), Parts 1 and 2 |
| — | Dec 14 | **Exam**; final project due | | |

The circular list with a sentinel (Extra A), the intrusive list (Extra B), and `container_of()` (Extra C) are **[optional reading](../lectures/optional/)**. They are the next step after this course, and the final project lists them as a bonus extension.

## Final Data Structure

```c
struct student {
    int id;
    char name[20];
    int score;
};

struct node {
    struct student data;
    struct node *next;
    struct node *prev;
};

struct student_list {
    struct node *head;
    struct node *tail;
};
```

Each node is created with `malloc()` and holds one student. `next` and `prev` link the nodes in both directions, and the list remembers its first and last node.

These invariants must always hold:

```text
empty list:      head == NULL  and  tail == NULL
non-empty list:  head->prev == NULL  and  tail->next == NULL
every node n:    if n->next != NULL, then n->next->prev == n
```

## Where Each Topic Appears in the Project

| Topic | In the final project |
|---|---|
| Struct and pointers (Session 1) | `struct student`, `struct node`, `list->head`, `n->data.id` |
| Operators (Session 2) | `n != NULL && n->data.id == id`, input validation, `&n->data` |
| Dynamic memory (Session 3, Part 1) | one `malloc()` per node, one `free()` per node |
| Linked lists (Session 3, Parts 1 and 2) | add at the tail, delete in four cases, forward and backward traversal |
| File I/O (Session 4, Part 1) | `student_load()` and `student_save()` |
| Multi-file programs (Session 4, Part 2) | `main.c`, `student.h`, `student.c`, and the Makefile |
