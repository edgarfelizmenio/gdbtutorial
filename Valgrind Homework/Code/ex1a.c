#include <stdlib.h>

int main(void) {
  int *ip;
  ip = (int *)malloc(sizeof(int));
  *ip=4711;
  ip = (void *)0;
  free(ip);
}
