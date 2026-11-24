#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

/* Reads one whole line from the keyboard. A line that is too long is cut,
 * and the rest of it is thrown away. Returns 0 at end of input.
 */
static int read_line(char *line, size_t size)
{
    int c;

    if (fgets(line, (int)size, stdin) == NULL)
        return 0;
    if (strchr(line, '\n') == NULL) {
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }
    return 1;
}

/* Returns 1 if the line was one integer, 0 if it was not,
 * and -1 at end of input.
 */
static int read_int(const char *prompt, int *value)
{
    char line[64];
    char extra;

    printf("%s", prompt);
    fflush(stdout);
    if (!read_line(line, sizeof line))
        return -1;
    return sscanf(line, "%d %c", value, &extra) == 1;
}

/* Reads one word of at most size - 1 characters. Returns 1 on success,
 * 0 if the line was empty, had spaces inside, or was too long,
 * and -1 at end of input.
 */
static int read_name(const char *prompt, char *name, size_t size)
{
    char line[64];
    char word[64];
    char extra;

    printf("%s", prompt);
    fflush(stdout);
    if (!read_line(line, sizeof line))
        return -1;
    if (sscanf(line, "%63s %c", word, &extra) != 1 || strlen(word) >= size)
        return 0;
    strcpy(name, word);
    return 1;
}

static void print_menu(void)
{
    printf("\n===== Student Management System =====\n");
    printf("1. Add Student\n");
    printf("2. Delete Student\n");
    printf("3. Search Student\n");
    printf("4. Print Students (Forward)\n");
    printf("5. Print Students (Backward)\n");
    printf("6. Student Count\n");
    printf("7. Save\n");
    printf("8. Exit\n");
}

int main(int argc, char *argv[])
{
    const char *path = argc > 1 ? argv[1] : "students.txt";
    struct student_list list;
    char name[20];
    int choice, id, score, loaded, status;
    int running = 1;

    list_init(&list);

    loaded = student_load(&list, path);
    if (loaded < 0)
        printf("Starting with an empty list.\n");
    else
        printf("Loaded %d students from %s\n", loaded, path);

    while (running) {
        print_menu();
        status = read_int("Select: ", &choice);
        if (status < 0)
            break;                      /* end of input works like Exit */
        if (status == 0) {
            printf("Error: Invalid input.\n");
            continue;
        }

        switch (choice) {
        case 1:
            if (read_int("ID: ", &id) != 1 ||
                read_name("Name: ", name, sizeof name) != 1 ||
                read_int("Score: ", &score) != 1) {
                printf("Error: Invalid input.\n");
                break;
            }
            /* TODO: Add Student.
             * Print an error for a bad ID, a bad score, or a duplicate ID.
             */
            break;

        case 2:
            if (read_int("ID: ", &id) != 1) {
                printf("Error: Invalid input.\n");
                break;
            }
            /* TODO: Delete Student */
            break;

        case 3:
            if (read_int("ID: ", &id) != 1) {
                printf("Error: Invalid input.\n");
                break;
            }
            /* TODO: Search Student */
            break;

        case 4:
            student_print_all(&list);
            break;

        case 5:
            student_print_reverse(&list);
            break;

        case 6:
            printf("Student count: %d\n", student_count(&list));
            break;

        case 7:
            if (student_save(&list, path) == 0)
                printf("Saved to %s\n", path);
            break;

        case 8:
            running = 0;
            break;

        default:
            printf("Error: Invalid menu selection.\n");
            break;
        }
    }

    status = student_save(&list, path);
    student_free_all(&list);
    return status == 0 ? 0 : EXIT_FAILURE;
}
