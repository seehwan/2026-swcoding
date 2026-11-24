# Optional Extras

These notes are **not part of the four sessions and not on the exam**. They continue the linked-list story for students who want to go further, and they are what you need for the final project's intrusive-list extension. Read them in order.

| Extra | Notes | Slides | The question it answers | Assignment |
|---|---|---|---|---|
| A | [Circular List with a Sentinel](a-circular-list/) | In the [Session 3 Part 2 deck](../session3-linked-list/session3-part2-slides.pptx) | How do I get rid of every `NULL` special case? | [Extra A](../../assignments/optional/a-circular-list/) |
| B | [Intrusive Linked List](b-intrusive-list/) | [extra-b-slides.pptx](b-intrusive-list/extra-b-slides.pptx) | Why put the links *inside* the data? | [Extra B](../../assignments/optional/b-intrusive-list/) |
| C | [`offsetof()` and `container_of()`](c-container-of/) | [extra-c-slides.pptx](c-container-of/extra-c-slides.pptx) | How do I get the object back from its links? | [Extra C](../../assignments/optional/c-container-of/) |

Extra A continues [Session 3, Part 2](../session3-linked-list/part2-doubly-linked-list.md). After Extra C, [Extra D](../../assignments/optional/d-file-io-intrusive/) is an assignment that saves and loads an intrusive list.

```bash
make -C lectures/optional/a-circular-list/examples run
make -C lectures/optional/b-intrusive-list/examples run
make -C lectures/optional/c-container-of/examples run
```
