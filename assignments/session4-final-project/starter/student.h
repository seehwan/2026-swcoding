#ifndef STUDENT_H
#define STUDENT_H

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

void list_init(struct student_list *list);

/* Adds a new student at the end of the list.
 * Returns 0 on success. Returns -1, and changes nothing, if the ID is not
 * positive, the score is outside 0-100, the ID is already in the list,
 * or malloc() fails.
 */
int student_add(struct student_list *list, int id, const char *name, int score);

struct node *student_find(const struct student_list *list, int id);

/* Returns 0 on success, or -1 if there is no student with this ID. */
int student_delete(struct student_list *list, int id);

void student_print(const struct student *student);
void student_print_all(const struct student_list *list);
void student_print_reverse(const struct student_list *list);
int student_count(const struct student_list *list);

/* File format: one student per line, "id name score" (e.g. 1 Alice 95).
 * Empty lines and lines that start with '#' are skipped.
 * Returns the number of students added, or -1 if the file cannot be opened.
 */
int student_load(struct student_list *list, const char *path);

/* Saves in the same format. Returns 0 on success, -1 on failure. */
int student_save(const struct student_list *list, const char *path);

void student_free_all(struct student_list *list);

#endif
