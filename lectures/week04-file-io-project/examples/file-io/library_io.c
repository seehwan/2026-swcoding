/*
 * Week 04 demo: saving a doubly linked list of books to a text file
 * and loading it back. The list is the one from Week 03, Part 2
 * (dll_book.c): heap nodes with next and prev, and a head and a tail.
 *
 *   ./library_io books.txt saved.txt
 *
 * File format, one book per line:   id,year,title
 * Empty lines and lines starting with '#' are ignored.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    int id;
    char title[32];
    int year;
};

struct node {
    struct book data;
    struct node *next;
    struct node *prev;
};

struct dlist {
    struct node *head;     /* first node, or NULL */
    struct node *tail;     /* last node, or NULL  */
};

static void dlist_init(struct dlist *list)
{
    list->head = NULL;
    list->tail = NULL;
}

static struct node *node_create(int id, const char *title, int year)
{
    struct node *n = malloc(sizeof(*n));

    if (n == NULL)
        return NULL;

    n->data.id = id;
    snprintf(n->data.title, sizeof(n->data.title), "%s", title);
    n->data.year = year;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

/* Adding at the back keeps the list in file order. */
static void dlist_push_back(struct dlist *list, struct node *n)
{
    n->next = NULL;
    n->prev = list->tail;
    if (list->tail != NULL)
        list->tail->next = n;
    else
        list->head = n;            /* empty list: n is also the first node */
    list->tail = n;
}

static void free_all(struct dlist *list)
{
    struct node *cur = list->head;

    while (cur != NULL) {
        struct node *next = cur->next;      /* read next BEFORE freeing cur */

        free(cur);
        cur = next;
    }
    dlist_init(list);
}

static void print_all(const struct dlist *list)
{
    const struct node *cur;

    for (cur = list->head; cur != NULL; cur = cur->next)
        printf("  [%d] %s (%d)\n", cur->data.id, cur->data.title, cur->data.year);
}

/* fgets() stopped in the middle of a long line: throw the rest away. */
static void skip_rest_of_line(FILE *fp)
{
    int c;

    while ((c = fgetc(fp)) != '\n' && c != EOF)
        ;
}

/* Returns the number of books loaded, or -1 if the file cannot be opened. */
static int library_load(struct dlist *list, const char *path)
{
    FILE *fp = fopen(path, "r");
    char line[128];
    int lineno = 0;
    int loaded = 0;

    if (fp == NULL) {
        perror(path);
        return -1;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        size_t len = strcspn(line, "\n");
        char title[32];
        int id;
        int year;
        struct node *n;

        lineno++;
        if (line[len] != '\n' && !feof(fp)) {
            fprintf(stderr, "%s:%d: line too long, skipped\n", path, lineno);
            skip_rest_of_line(fp);
            continue;
        }
        line[len] = '\0';                       /* strip the newline */

        if (line[0] == '\0' || line[0] == '#')
            continue;
        if (sscanf(line, "%d,%d,%31[^\n]", &id, &year, title) != 3) {
            fprintf(stderr, "%s:%d: invalid line: %s\n", path, lineno, line);
            continue;
        }

        n = node_create(id, title, year);
        if (n == NULL) {
            fprintf(stderr, "Error: out of memory\n");
            break;
        }
        dlist_push_back(list, n);
        loaded++;
    }

    fclose(fp);
    return loaded;
}

/* Returns 0 on success, -1 on failure. */
static int library_save(const struct dlist *list, const char *path)
{
    FILE *fp = fopen(path, "w");
    const struct node *cur;

    if (fp == NULL) {
        perror(path);
        return -1;
    }

    fprintf(fp, "# id,year,title\n");
    for (cur = list->head; cur != NULL; cur = cur->next)
        fprintf(fp, "%d,%d,%s\n", cur->data.id, cur->data.year, cur->data.title);

    if (fclose(fp) != 0) {                      /* buffered data is written here */
        perror(path);
        return -1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    struct dlist library;
    int n;

    if (argc != 3) {
        fprintf(stderr, "usage: %s INPUT OUTPUT\n", argv[0]);
        return EXIT_FAILURE;
    }

    dlist_init(&library);
    n = library_load(&library, argv[1]);
    if (n < 0)
        return EXIT_FAILURE;
    printf("loaded %d books from %s\n", n, argv[1]);
    print_all(&library);

    if (library_save(&library, argv[2]) != 0) {
        free_all(&library);
        return EXIT_FAILURE;
    }
    printf("saved to %s\n", argv[2]);

    free_all(&library);
    return 0;
}
