#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char *p = malloc(1);
  *p = 'a';
  // char c = *(p + 1);
  // is an invalid read since only one byte is allocated
  // to p. The location p + 1 must not be accesible to
  // the program. To fix this, we will just remove
  // the + 1
  char c = *(p);
  printf("\n [%c]\n", c);
  free(p);
  return 0;
}
