#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void list_init(struct student_list *list)
{
    /* TODO: An empty list has no first node and no last node. */
    (void)list;
}

int student_add(struct student_list *list, int id, const char *name, int score)
{
    /* TODO:
     * 1. Reject a bad ID, a bad score, and an ID that is already in the list.
     * 2. Create a node with malloc(), and check the result.
     * 3. Store id, name, and score. Copy the name with a size limit.
     * 4. Link the node after list->tail. Remember the empty list:
     *    then the new node is both the head and the tail.
     */
    (void)list;
    (void)id;
    (void)name;
    (void)score;
    return -1;
}

struct node *student_find(const struct student_list *list, int id)
{
    /* TODO: Walk from list->head, following next, until NULL. */
    (void)list;
    (void)id;
    return NULL;
}

int student_delete(struct student_list *list, int id)
{
    /* TODO:
     * student_find()
     * -> unlink the node: fix the node before it and the node after it.
     *    If it was the first node, list->head changes.
     *    If it was the last node, list->tail changes.
     * -> free()
     */
    (void)list;
    (void)id;
    return -1;
}

void student_print(const struct student *student)
{
    /* TODO */
    (void)student;
}

void student_print_all(const struct student_list *list)
{
    /* TODO: Forward traversal, from head. Handle the empty list. */
    (void)list;
}

void student_print_reverse(const struct student_list *list)
{
    /* TODO: Backward traversal, from tail. Handle the empty list. */
    (void)list;
}

int student_count(const struct student_list *list)
{
    /* TODO */
    (void)list;
    return 0;
}

int student_load(struct student_list *list, const char *path)
{
    /* TODO:
     * 1. Open the file with fopen(). If that fails, call perror() and return -1.
     * 2. Read one line at a time with fgets(), then get id, name, score with sscanf().
     *    Limit the name, as in %19s.
     * 3. Skip empty lines and lines that start with '#'.
     * 4. If a line has the wrong format, or student_add() rejects it,
     *    print it to stderr like "students.txt:5: invalid line" and skip it.
     * 5. Call fclose(), and return the number of students added.
     */
    (void)list;
    (void)path;
    return 0;
}

int student_save(const struct student_list *list, const char *path)
{
    /* TODO: fopen(path, "w") -> fprintf() for each student -> fclose() */
    (void)list;
    (void)path;
    return 0;
}

void student_free_all(struct student_list *list)
{
    /* TODO:
     * free() every node. Read node->next BEFORE you free the node.
     * Afterwards, the list must be empty again: head and tail are NULL.
     */
    (void)list;
}
