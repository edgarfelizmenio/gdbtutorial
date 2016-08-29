#include "stdlib.h"
#include "stdio.h"

int main(int argc, char* argv[]) {
  int *x = (int*)malloc(sizeof(int));
  x += 2;
  printf("%d \n", *x);
  *x = 4;
  free(x - 2);
  printf("%d\n", *((int*)3838338));
  return EXIT_SUCCESS;
}
