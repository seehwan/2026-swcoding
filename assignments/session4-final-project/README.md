# Final Project: Student Management System

## 1. Project Goal

Combine everything from the course — `struct`, pointers, operators, dynamic memory, linked lists, and file I/O — into one program.

The final result is a **Student Management System** that keeps its students in a **doubly linked list**, **loads them from a file** when it starts, and **saves them to the file** when it ends.

---

## 2. Required Data Structures

Use these structures as the base. They are in `starter/student.h`:

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
    struct node *head;      /* first node, or NULL when the list is empty */
    struct node *tail;      /* last node, or NULL when the list is empty  */
};
```

### Structural rules you must follow

1. Use a **doubly linked list**: every node has both `next` and `prev`.
2. Keep both `head` and `tail` in `struct student_list`.
3. Do not store the students in an array.
4. Create each node at run time with `malloc()`.
5. Do not use global variables for the list. `main()` owns it and passes a pointer.

These invariants must hold after **every** operation:

```text
empty list:      head == NULL  and  tail == NULL
non-empty list:  head->prev == NULL  and  tail->next == NULL
every node n:    if n->next != NULL, then n->next->prev == n
```

---

## 3. User Interface

Run the program with the name of the data file. Without an argument it uses `students.txt`.

```bash
./student_manager              # uses students.txt
./student_manager class_a.txt
```

The program loads the file, then shows this menu:

```text
===== Student Management System =====
1. Add Student
2. Delete Student
3. Search Student
4. Print Students (Forward)
5. Print Students (Backward)
6. Student Count
7. Save
8. Exit
Select:
```

The starter's `main.c` already reads the keyboard input safely (one line at a time with `fgets()` and `sscanf()`). You write what each menu item does.

---

## 4. Required Features

### 4.1 Load at start

- Call `student_load()` with the file name.
- If the file cannot be opened, print the reason with `perror()` and start with an empty list. The program keeps running.
- Skip empty lines and lines that start with `#`.
- If a line has the wrong format, an ID that is not positive, a score outside 0–100, or an ID that is already in the list, print `filename:line: invalid line` to `stderr` and skip the line.

The given `students.txt` has 2 bad lines on purpose. Your program should load 3 students from it:

```text
students.txt:5: invalid line
students.txt:6: invalid line
Loaded 3 students from students.txt
```

### 4.2 Add Student

- Read an ID, a name, and a score.
- Add the student at the **end** of the list with `student_add()`.
- If the ID is not positive or the score is outside 0–100, do not add it.
- If a student with the same ID already exists, do not add it.

Suggested error messages:

```text
Error: Invalid ID or score.
Error: Student ID already exists.
```

### 4.3 Delete Student

Read an ID, find the node, unlink it from the list, and free its memory.

```text
student_find()
    ↓
unlink (fix prev, next, and maybe head or tail)
    ↓
free()
```

Test all four positions: the only node, the first node, the last node, and a node in the middle.

If the ID does not exist, print:

```text
Error: Student not found.
```

### 4.4 Search Student

Find a student by ID and print its information.

```text
ID: 5, Name: Eve, Score: 58
```

If there is no such student:

```text
Error: Student not found.
```

### 4.5 Print Students — Forward

Start at `head` and follow `next` until `NULL`.

```c
for (n = list->head; n != NULL; n = n->next)
    student_print(&n->data);
```

If the list is empty:

```text
No students found.
```

### 4.6 Print Students — Backward

Start at `tail` and follow `prev` until `NULL`.

### 4.7 Student Count

```text
Student count: 3
```

### 4.8 Save

Write every student to the data file, in list order, with `student_save()`.

### 4.9 Exit

Save the list, then `free()` every node. The starter's `main()` also treats the end of input (Ctrl-D) as Exit.

Just before the program ends, the list must be empty again:

```c
list.head == NULL;
list.tail == NULL;
```

---

## 5. File Format

```text
# id name score
1 Alice 95
2 Bob 72
```

- One student per line. The fields are separated by spaces.
- A name has no spaces and is at most 19 characters long.
- `student_save()` writes the `# id name score` line first, then one line per student.
- **Round trip:** when you load a file that your program saved, and save it again, the two files must be the same.

```bash
./student_manager data.txt     # choose 8 (Exit): data.txt is saved
cp data.txt first.txt
./student_manager data.txt     # choose 8 again
diff first.txt data.txt        # prints nothing
```

---

## 6. Required Functions

All of these are declared in `starter/student.h`:

```c
void list_init(struct student_list *list);
int student_add(struct student_list *list, int id, const char *name, int score);
struct node *student_find(const struct student_list *list, int id);
int student_delete(struct student_list *list, int id);
void student_print(const struct student *student);
void student_print_all(const struct student_list *list);
void student_print_reverse(const struct student_list *list);
int student_count(const struct student_list *list);
int student_load(struct student_list *list, const char *path);
int student_save(const struct student_list *list, const char *path);
void student_free_all(struct student_list *list);
```

### Function responsibilities

| Function | It must | It must not |
|---|---|---|
| `student_add()` | validate, `malloc()`, copy the name with a size limit, link at the tail | print anything |
| `student_find()` | return the node, or `NULL` | change the list |
| `student_delete()` | find → unlink → `free()` | leave `head` or `tail` pointing at freed memory |
| `student_load()` | `fopen()` → `fgets()` + `sscanf()` → `student_add()` → `fclose()` | stop at the first bad line |
| `student_save()` | `fopen(path, "w")` → `fprintf()` → `fclose()` | write pointer values |
| `student_free_all()` | read `next` **before** freeing each node, then reset `head` and `tail` | use a node after `free()` |

`main.c` talks to the user. `student.c` never reads from the keyboard.

---

## 7. Input Constraints

- ID: a positive integer
- Name: at most 19 characters, no spaces
- Score: from `0` to `100`
- Every student ID must be unique.

Handle input errors so that the program never crashes.

---

## 8. Restrictions

These are not allowed:

1. Storing all students in an array
2. Using an external linked list library
3. Using global storage for the students
4. Reading a name with `gets()` or with `%s` without a length limit
5. Saving the structs with `fwrite()` (the file must be readable text)

---

## 9. Starter Files

```text
starter/
├── main.c          the menu, the keyboard input, and the program flow
├── student.h       the structures and the function prototypes
├── student.c       the list and file operations (all TODO)
├── students.txt    sample data, with 2 bad lines on purpose
├── Makefile
└── README.md
```

Write the code for every TODO yourself.

---

## 10. Build and Run

### GCC

```bash
gcc -Wall -Wextra -std=c11 main.c student.c -o student_manager
./student_manager
```

### Makefile

```bash
make
./student_manager
make clean
```

---

## 11. Suggested Order

Build and test after each step. Do not write everything first.

| Step | Write | Check |
|---|---|---|
| 1 | `list_init()`, `student_add()`, `student_print()`, `student_print_all()` | Add 3 students, print forward. |
| 2 | `student_print_reverse()`, `student_count()` | Backward print is the exact reverse. |
| 3 | `student_find()`, Search, duplicate-ID check | Search for a missing ID and for an existing one. |
| 4 | `student_delete()` | Delete the first, the last, a middle node, and the only node. Print both ways after each. |
| 5 | `student_free_all()` | Exit with 0, 1, and 3 students. |
| 6 | `student_save()` | Open the saved file in an editor. |
| 7 | `student_load()` | Load `students.txt`: 3 students and 2 messages. Do the round-trip test. |

---

## 12. Optional Extensions (bonus)

Do these only after the required features work.

- **Intrusive list.** Replace `struct node` with a `struct list_head` inside `struct student`, and use `container_of()`. See [Extra B](../optional/b-intrusive-list/) and [Extra C](../optional/c-container-of/).
- **Status flags.** Add an `unsigned int flags` member (enrolled, honors, paid) with the bit operations from [Session 2](../session2-operators/), and save it in the file.
- **Sorted insert.** Keep the list ordered by ID.
- **Statistics.** Print the average, the highest, and the lowest score.

Say in your README which extensions you did.

---

## 13. README Requirement

The README you submit must include at least:

1. How to run the program
2. The features you implemented
3. The data structures you used, with a picture of a list of 3 students
4. The four cases of delete, and how your code handles each one
5. How your program handles a bad line in the file
6. The problems you met while implementing, and how you solved them

---

## 14. Final Checklist

- [ ] Each node is created with `malloc()`, and the result is checked.
- [ ] Each node is freed with `free()`.
- [ ] Every node has correct `next` and `prev` links after add and delete.
- [ ] `head` and `tail` are correct for an empty list and for a list of one.
- [ ] Add works, and rejects a bad ID, a bad score, and a duplicate ID.
- [ ] Delete works for the only, first, last, and a middle node.
- [ ] Search works.
- [ ] Forward Print and Backward Print work.
- [ ] Student Count works.
- [ ] The program loads 3 students from the given `students.txt` and reports 2 bad lines.
- [ ] A missing data file does not stop the program.
- [ ] Save, load, and save again give the same file.
- [ ] Every `fopen()` has a matching `fclose()`.
- [ ] There are no memory leaks.
- [ ] There are no warnings with `gcc -Wall -Wextra -std=c11`.
- [ ] I wrote the README for my submission.
