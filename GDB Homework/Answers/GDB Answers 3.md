# GDB Homework - Answers to Part 3

Complete the C program *ll_cycle.c*. Complete the function *ll_has_cycle()* to implement the following algorithm for checking if a singly-linked list has a cycle.

  1. Start with two pointers at the head of the list. We'll call the first one *tortoise* and the second one *hare*.
  2. Advance *hare* by two nodes. If this is not possible because of a null pointer, we have found the end of the list, and therefore the list is acyclic.
  3. Advance *tortoise* by one node. (A null pointer check is unnecessary. Why?)
  4. If *tortoise* and *hare* point to the same node, the list is cyclic. Otherwise, go back to step 2.

After you have correctly implemented *ll_has_cycle()*, the program you get when you compile ll_cycle.c will tell you that *ll_has_cycle()* agrees with what the program expected it to output.

  __Answer:__
  ```c
  int ll_has_cycle(node *head) {
    node* hare = head;
    node* tortoise = head;
    while (hare != NULL) {
      hare = hare->next;
      if (hare == NULL) {
        return 0;
      }
      hare = hare->next;
      tortoise = tortoise->next;
      if (hare == tortoise) return 1;
    }
    return 0;
  }
  ```
