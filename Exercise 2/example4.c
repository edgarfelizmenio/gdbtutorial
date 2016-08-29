#include "stdlib.h"

int main(int argc, char* argv[]) {

  int *x = (int*)malloc(sizeof(int));
  free(x);
  return EXIT_SUCCESS;
}
