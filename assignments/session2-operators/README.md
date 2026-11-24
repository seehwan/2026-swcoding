# Session 2 — Operators and Precedence

## Learning Objectives

- Understand operator precedence and associativity.
- Read expressions that mix `*`, `&`, `.`, `->`, and `++` correctly.
- Check for a `NULL` pointer safely with the short-circuit of `&&`.
- Set, clear, and test flags with bitwise operators.
- Use compiler warnings to find precedence bugs.
- Predict the value of an expression before you run it.

## Assignment

This assignment has two parts. Submit both files.

| Part | File | What you do |
|---|---|---|
| A | `starter/assignment_02a.c` | Write and fix code. |
| B | `starter/assignment_02b.c` | Predict the value of each expression, then check. |

### Part A — write and fix

Complete the TODOs in `starter/assignment_02a.c`.

1. `is_valid_score()`: check that the score is between 0 and 100 (inclusive).
2. `is_passing()`: write the `NULL` check and the "60 or more" check as one `&&` expression.
3. Using only `struct student **pp`, add 5 to the score.
4. Set (`|=`), clear (`&= ~`), and test (`&`) flags, then print them with `print_flags()`.
5. Fix the 5 bugs in `fix_me()`, and add a comment to each one that explains what was wrong.

### Part B — predict, then check

`starter/assignment_02b.c` has one `CHECK` line for each expression, in seven sections:
precedence, integer arithmetic, short-circuit logic, pointer expressions,
bitwise operators, macros, and strings.

1. Work out the value of each `CHECK` line **on paper**, before you run anything.
2. Replace each `TODO` with your prediction.
3. Build and run. Each line prints one of these:

   ```text
   Q90  2 + 3 * 4                              OK    14
   Q91  10 - 4 - 3                             MISS  predicted 9, actual 3
   Q92  8 / 4 / 2                              ?
   ```

   (These three lines only show the format; they are not in the file.)

   `?` means you have not predicted yet, so the value stays hidden.
4. For every `MISS`, correct the prediction and add a comment on that line that
   explains what you got wrong. A `MISS` that you explain well is worth more
   than an `OK` that you copied.
5. Answer the three written questions (W1–W3) in the comment at the end of the
   file. They are about code that cannot be run safely.

## Requirements

- **Part A:** the starter produces 3 compiler warnings **on purpose**. Your submission must have 0 warnings.
- **Part A:** `fix_me()` also has 2 bugs that produce no warning. Run the program and read the output to find them.
- **Part A:** do not chain comparisons like `0 <= score <= 100`.
- **Part B:** change only the `TODO`s and add comments. Do not rewrite the expressions; they are traps on purpose.
- **Part B:** the last line must read `predicted N of N, matched N`.
- If you are not sure about precedence, add parentheses.

## Build

```bash
cd starter
gcc -Wall -Wextra -std=c11 assignment_02a.c -o session2a
./session2a
gcc -std=c11 -w assignment_02b.c -o session2b
./session2b
```

Part B is built with `-w` (warnings off), because its traps would fill the
screen. Once you have finished, build it with `-Wall -Wextra` instead and match
each warning to a `CHECK` line: which traps does the compiler catch, and which
does it miss?

## Checklist

- [ ] `is_valid_score()` returns the right value for -1, 0, 100, and 101.
- [ ] `is_passing(NULL)` returns 0 without crashing.
- [ ] I changed the value with `(*pp)->score`.
- [ ] I used `|=`, `&= ~`, and `&` for the flags.
- [ ] I fixed the 5 bugs in `fix_me()` and wrote down why each one was wrong.
- [ ] Part A builds with no compiler warnings.
- [ ] I predicted every `CHECK` line in Part B before running it.
- [ ] Every line in Part B prints `OK`, and each earlier `MISS` has a comment.
- [ ] I answered W1, W2, and W3.

## Makefile

```bash
cd starter
make
./session2a
./session2b
make clean
```
