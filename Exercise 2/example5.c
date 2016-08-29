#include "stdlib.h"
#include "stdio.h"

int main(int argc, char* argv[]) {
  int *x = (int *)malloc(sizeof(int));
  *x = 4;

  printf("%d\n", *x);
  return EXIT_SUCCESS;
}
