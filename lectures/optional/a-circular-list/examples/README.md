# Extra A examples: circular list invariants and build modes

From the repository root:

```bash
make -C lectures/optional/a-circular-list/examples
make -C lectures/optional/a-circular-list/examples run
make -C lectures/optional/a-circular-list/examples clean
```

`make run` uses fixed, safe paths. The optional `clist_book break` command
remains a separate assert-failure demonstration and is not part of that target.

## Teaching sequence and reference pages

The doubly linked list that comes before these demos, `dll_book.c`, is in the [Session 3 examples](../../../session3-linked-list/examples/dll_book.c).

| Order | Demo | Connection to the reference PDFs |
|---|---|---|
| 1 | [clist_book.c](clist_book.c) | Add a sentinel and circular invariants; revisit [Dynamic Memory Allocation](../../../session3-linked-list/%5BSlide%5D%2002.%20Dynamic%20Memory%20Allocation.pdf), pp. 25-27, before saving the next link and freeing each node. These list algorithms extend the PDF's pointer and lifetime mechanisms. |
| 2 | [invariant_modes.c](invariant_modes.c) | [Writing Large Programs](../../../session4-file-io-project/%5BSlide%5D%2007.%20Writing%20Large%20Programs.pdf), pp. 16-18, supplies conditional compilation and `-D`; the course's `assert` extension shows which checks disappear under `NDEBUG` and which runtime checks must remain. |

The new mode demo uses a small ring of live stack objects to isolate the build
question. It does not replace the insertion, traversal, and cleanup examples.
Its bounded checker detects logical topology mistakes among live objects; it
cannot prove that an arbitrary pointer points to accessible storage.

## Compare build modes

In `lectures/optional/a-circular-list/examples/`:

```bash
make -B invariant_modes CFLAGS='-std=c11 -Wall -Wextra -Wpedantic -Werror -DDEBUG=0'
./invariant_modes
make -B invariant_modes CFLAGS='-std=c11 -Wall -Wextra -Wpedantic -Werror -DDEBUG=1'
./invariant_modes
make -B invariant_modes CFLAGS='-std=c11 -Wall -Wextra -Wpedantic -Werror -DDEBUG=0 -DNDEBUG'
./invariant_modes
make clean
```

The default output is:

```text
assertions: enabled
DEBUG=0; insertions=2
valid ring: 1
wrong prev link rejected by runtime check: 1
restored ring: 1
```

With `DEBUG=1`, the first line is `debug after insertions: first=1 last=2`.
With `NDEBUG`, `assertions: disabled` replaces the assertion-status line;
insertions, required validation, detection, and restoration still run.

`#ifdef DEBUG` tests whether the macro exists, so it is true even when
`DEBUG=0`. This demo uses `#if DEBUG` to test its numeric value. `assert(valid)`
has no side effects; allocation, link changes, and required validation occur
before it. The default run introduces one wrong `prev` link among live objects,
checks it without traversing the malformed ring, then restores it.

## Predict, then change

1. Predict whether the two insertions still happen with `-DNDEBUG`. Locate the
   statements that make the answer independent of `assert` expansion.
2. Add `-DDEBUG=1 -DNDEBUG` together. Predict the debug trace and the assertion
   status separately, then verify both.
3. Change the expected count passed to the checker from 2 to 1 in a scratch
   copy. Explain why a correctly linked ring can still fail that count check.
4. Compare the lifetime of these stack books with the heap nodes in
   `clist_book.c`. Which demo calls `free()`, and why?
