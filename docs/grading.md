# Grading

This page is about the **final project**. Total: **100 points**

| Item | Points |
|---|---:|
| Structs and dynamic memory (`malloc()` checked, one node per student) | 15 |
| Doubly linked list: `next`, `prev`, `head`, and `tail` stay correct | 20 |
| Add, delete, and search, with their error cases | 15 |
| Forward print, backward print, and count | 10 |
| Loading a file: `fgets()` + `sscanf()`, bad lines reported and skipped | 15 |
| Saving a file, and the save → load → save round trip | 10 |
| Memory management: every node freed, no use after `free()` | 5 |
| Program structure: `main.c` / `student.c` split, Makefile, no warnings | 5 |
| README and explanations | 5 |
| **Total** | **100** |

Optional extensions (intrusive list with `container_of()`, status flags, sorted insert, statistics) can earn up to **10 bonus points**, only when all required features work.

## Common Deductions

- The program does not compile.
- All students are stored in an array.
- The list is a global variable.
- `prev` links are wrong, so the backward print differs from the reversed forward print.
- Deleting the first, last, or only node leaves `head` or `tail` wrong.
- A `free()` is missing after `malloc()`, or a node is used after `free()`.
- The program crashes, or stops loading, at a bad line in the file.
- A name is read without a length limit.
- `fclose()` is missing.
