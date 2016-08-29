# GDB Homework - Answers to Part 2

1. Explain the bug in ```ll_equal()``` and your fix to the function.

  __Answer:__
  The function ```ll_equal()``` doesn't check if list _b_ has already terminated. Not doing this check will lead to a program crash since the loop checks for the values at the nodes pointed by _a_ and _b_.

  To fix the function, we'll just add a condition at the while loop in ```ll_equal()``` that checks if _b_ has already terminated.

  ```c
  int ll_equal(const node* a, const node* b) {
     // also check if b has already terminated
  	while (a != NULL && b != NULL) {
  		if (a->val != b->val)
  			return 0;
  		a = a->next;
  		b = b->next;
  	}
  	/* lists are equal if a and b are both null */
  	return a == b;
  }
  ```
