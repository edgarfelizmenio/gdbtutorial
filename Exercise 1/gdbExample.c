#include <stdio.h>
#include "string.h"

int main(int argc, char* argv[]) {
  int i, j, k;
  int x[1000];

  for(i = 0; i < 1000; ++i) {
    x[i] = i;
  }

  printf("Enter integer in 0..999: ");
  scanf("%d", &k);

  for(i = 0; i < 1000; ++i) {
    tester(x, i);
  }

}

int tester(int* c, int k) {
  printf("x[%d] = %d\n", k, c[k]);
}
