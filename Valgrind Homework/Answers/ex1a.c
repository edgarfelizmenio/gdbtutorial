#include <stdlib.h>

int main(void) {
  int *ip;
  ip = (int *)malloc(sizeof(int));
  *ip=4711;

  // Pointer was dereferenced to NULL while pointing to an allocated memory
  // location. The effect is we can never free the allocated memory, leading to
  // a memory leak. To deallocate the allocated memory, we'll just rearrange
  // the order of the last 2 lines.
  free(ip);
  ip = (void *)0;

  // This error may not be detected by Valgrind,
  // But you must return an integer since main()
  // is defined to return an integer.
  return 0;
}
