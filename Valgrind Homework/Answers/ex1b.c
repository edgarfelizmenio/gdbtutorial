#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char *p = malloc(1);
  *p = 'a';
  char c = *p;
  printf("\n [%c]\n", c);
  free(p);
  // Assigning *p to c will lead to an invalid read because
  // the location pointed to by p is already freed (inaccessible).
  // To fix this, we will just erase the assignment statement
  // after the free in line 9 (assignment statement commented
  // out in this code).
  // c = *p;
  return 0;
}
