/*
 * Session 2, Part B: predict, then check.
 *
 * 1. Read each CHECK line and work out its value ON PAPER.
 * 2. Replace TODO with your prediction.
 * 3. Build, run, and read the result:
 *
 *        OK    your prediction matches
 *        MISS  it does not: find out why, and write the reason in a comment
 *        ?     you have not predicted yet (the value stays hidden)
 *
 * Change only the TODOs and add comments. Do not "fix" the expressions:
 * many of them are traps on purpose, so this file is built without warnings.
 * To see what the compiler thinks of them, build it by hand:
 *
 *        gcc -Wall -Wextra -std=c11 assignment_02b.c -o session2b
 *
 * Predictions may be written as 6, 0x14, or 'C'. A double such as 6.0 is
 * compared as the integer 6.
 */
#include <stdio.h>
#include <string.h>

#define TODO (-9999)

static int total;
static int answered;
static int matched;

static void print_value(char kind, long long value)
{
    if (kind == 'x')
        printf("0x%llx", (unsigned long long)value);
    else if (kind == 'c')
        printf("'%c'", (char)value);
    else
        printf("%lld", value);
}

static void report(const char *label, const char *text, char kind,
                   long long actual, long long guess)
{
    ++total;
    printf("  Q%-3s %-38s ", label, text);
    if (guess == TODO) {
        printf("?\n");
        return;
    }
    ++answered;
    if (guess == actual) {
        ++matched;
        printf("OK    ");
        print_value(kind, actual);
    } else {
        printf("MISS  predicted ");
        print_value(kind, guess);
        printf(", actual ");
        print_value(kind, actual);
    }
    printf("\n");
}

/* CHECK prints in decimal, CHECKX in hexadecimal, CHECKC as a character.
 * CHECK_AS is for a value that needs a description instead of its own text.
 */
#define CHECK_AS(label, text, kind, value, guess) \
    report((label), (text), (kind), (long long)(value), (long long)(guess))
#define CHECK(label, e, guess)   CHECK_AS(label, #e, 'd', e, guess)
#define CHECKX(label, e, guess)  CHECK_AS(label, #e, 'x', e, guess)
#define CHECKC(label, e, guess)  CHECK_AS(label, #e, 'c', e, guess)

struct book {
    int id;
    char title[32];
    int year;
};

#define BOOK_BORROWED (1u << 0)
#define BOOK_DAMAGED  (1u << 1)

#define HALF(x)   x / 2
#define ADD(a, b) a + b
#define MAX(a, b) ((a) > (b) ? (a) : (b))

static void section_a(void)
{
    int a = 1, b = 2, c = 4, d = 3;
    int x = 5, y = 0;

    puts("A. Precedence and associativity");
    CHECK("1", a < b == c < d, TODO);
    CHECK("2", !x == y, TODO);
    CHECK("3a", 1 < 2 < 3, TODO);
    CHECK("3b", 3 > 2 > 1, TODO);

    x = 4;                              /* an even number */
    CHECK("4a", x & 1 == 0, TODO);
    CHECK("4b", (x & 1) == 0, TODO);
    CHECK("5", sizeof x + 1, TODO);

    x = (1, 2, 3);
    CHECK_AS("6a", "x = (1, 2, 3);  x is", 'd', x, TODO);
    x = 1, 2, 3;
    CHECK_AS("6b", "x = 1, 2, 3;    x is", 'd', x, TODO);
    CHECK("7", 1 << 2 + 1, TODO);
}

static void section_b(void)
{
    int percent;
    size_t i = 0;

    puts("B. Integer arithmetic and conversions");
    CHECK("8a", 7 / 2 * 2, TODO);
    CHECK("8b", 7 * 2 / 2, TODO);
    CHECK("8c", 7 / 2 * 2.0, TODO);
    CHECK("8d", 7 / 2.0 * 2, TODO);
    CHECK("9a", -7 / 2, TODO);
    CHECK("9b", -7 % 2, TODO);
    CHECK("9c", 7 % -2, TODO);

    percent = 45 / 60 * 100;
    CHECK_AS("10a", "percent = 45 / 60 * 100;", 'd', percent, TODO);
    percent = 45 * 100 / 60;
    CHECK_AS("10b", "percent = 45 * 100 / 60;", 'd', percent, TODO);
    CHECK("11a", '7' - '0', TODO);
    CHECKC("11b", 'A' + 2, TODO);

    i--;                                /* i was 0, and size_t is unsigned */
    CHECK_AS("12", "size_t i = 0; i--;  is i >= 0 ?", 'd', i >= 0, TODO);
}

static void section_c(void)
{
    int i, r, x, ran;
    struct book *p = NULL;

    puts("C. Logical operators and short-circuit evaluation");
    i = 0;
    if (i++ && i++) {
    }
    CHECK_AS("13", "i = 0; if (i++ && i++) {}  i is", 'd', i, TODO);

    i = 0;
    r = i++ || i++;
    CHECK_AS("14a", "i = 0; r = i++ || i++;  i is", 'd', i, TODO);
    CHECK_AS("14b", "                        r is", 'd', r, TODO);

    /* p is NULL here. Does this line crash? */
    CHECK("15", p != NULL && p->year > 2000, TODO);

    x = 0;
    ran = 0;
    if (x = 0)
        ran = 1;
    CHECK_AS("16", "x = 0; if (x = 0) ran = 1;  ran is", 'd', ran, TODO);

    x = 42;
    CHECK("17a", !x, TODO);
    CHECK("17b", !!x, TODO);
    CHECK("17c", ~x & 1, TODO);
}

static void section_d(void)
{
    struct book shelf[2] = { { 1, "Linux", 1991 }, { 2, "Minix", 1987 } };
    struct book *p = &shelf[0];
    struct book **pp = &p;
    const char *s = "ace";
    int a[] = { 10, 20, 30 };
    int *q = a;
    int x, y, z, w, year;
    char source[] = "copy me";
    char target[sizeof source];
    char *from = source, *to = target;

    puts("D. Pointer expressions");
    CHECKC("18a", *p->title, TODO);
    CHECKC("18b", p->title[2], TODO);
    CHECKC("18c", *(p->title + 4), TODO);
    CHECK("18d", (*pp)->year, TODO);
    CHECK("19", strlen(&p->title[1]), TODO);

    ++p->year;
    CHECK_AS("20a", "++p->year;  shelf[0].year is", 'd', shelf[0].year, TODO);
    CHECK_AS("20b", "            p - shelf is", 'd', p - shelf, TODO);
    year = p++->year;
    CHECK_AS("20c", "year = p++->year;  year is", 'd', year, TODO);
    CHECK_AS("20d", "                   p - shelf is", 'd', p - shelf, TODO);

    CHECKC("21a", *s + 1, TODO);        /* s points to "ace" */
    CHECKC("21b", *(s + 1), TODO);

    x = *q++;                           /* a is { 10, 20, 30 }, q points to a[0] */
    y = (*q)++;
    z = *++q;
    w = ++*q;
    CHECK("22a", x, TODO);
    CHECK("22b", y, TODO);
    CHECK("22c", z, TODO);
    CHECK("22d", w, TODO);
    CHECK("22e", a[1], TODO);
    CHECK("22f", a[2], TODO);
    CHECK("22g", q - a, TODO);

    while ((*to++ = *from++) != '\0')   /* source is "copy me" */
        ;
    CHECK_AS("23", "after the copy loop, to - target is", 'd', to - target, TODO);
}

static void section_e(void)
{
    unsigned int flags = 0x5;
    unsigned int wanted = 0x3;
    unsigned int x = 0x14;
    unsigned int n = 4;

    puts("E. Bitwise operators (flags = 0x5)");
    CHECKX("24a", flags & 0x2, TODO);
    CHECKX("24b", flags | 0x2, TODO);
    CHECKX("24c", flags ^ 0x1, TODO);
    CHECKX("24d", flags & ~0x1, TODO);
    CHECKX("24e", flags >> 1, TODO);
    CHECKX("24f", flags << 2, TODO);
    CHECKX("25a", !flags, TODO);
    CHECKX("25b", ~flags, TODO);        /* write it as 0x...u */

    flags = BOOK_BORROWED;              /* only BORROWED is set */
    CHECK("26a", flags & BOOK_DAMAGED == BOOK_DAMAGED, TODO);
    CHECK("26b", (flags & BOOK_DAMAGED) == BOOK_DAMAGED, TODO);

    flags = 0x1;                        /* wanted = 0x3 */
    CHECK("27a", (flags & wanted) != 0, TODO);
    CHECK("27b", (flags & wanted) == wanted, TODO);

    CHECK("28a", (x >> n) & 1u, TODO);  /* x = 0x14, n = 4 */
    CHECK("28b", (x & (1u << n)) != 0, TODO);
}

static void section_f(void)
{
    int i = 3, j = 5, m;

    puts("F. Macros");
    CHECK("29a", HALF(4 + 6), TODO);
    CHECK("29b", ADD(1, 2) * 3, TODO);

    m = MAX(i++, j++);                  /* i = 3, j = 5 */
    CHECK_AS("30a", "m = MAX(i++, j++);  m is", 'd', m, TODO);
    CHECK_AS("30b", "                    i is", 'd', i, TODO);
    CHECK_AS("30c", "                    j is", 'd', j, TODO);
}

static void section_g(void)
{
    char t[] = "Linux";
    const char *s = "Linux";
    char no_null[5] = "Linux";          /* legal C, but is it a string? */
    char a[] = "C";
    char b[] = "C";

    puts("G. Strings");
    CHECK("32a", sizeof t, TODO);
    CHECK("32b", strlen(t), TODO);
    CHECK("32c", sizeof s, TODO);
    CHECK("33", sizeof no_null, TODO);
    CHECK("34a", a == b, TODO);
    CHECK("34b", strcmp(a, b) == 0, TODO);
}

/*
 * Written questions. These cannot be checked by running them, because the
 * code in question has undefined behavior or never ends. Answer in the
 * comment, in one or two sentences each.
 *
 * W1. (Q12) Why does this loop never end?
 *         for (size_t i = n - 1; i >= 0; i--)
 *     TODO:
 *
 * W2. (Q31) Which of these have undefined behavior, and why?
 *         (a) i = i + 1;     (b) i = i++;        (c) a[i++] = i;
 *         (d) x = i++ + j++; (e) f(i++, i++);
 *     TODO:
 *
 * W3. (Q33) Why must you not call strlen(no_null) in section_g()?
 *     TODO:
 */

int main(void)
{
    section_a();
    section_b();
    section_c();
    section_d();
    section_e();
    section_f();
    section_g();

    printf("\npredicted %d of %d, matched %d\n", answered, total, matched);
    return 0;
}
