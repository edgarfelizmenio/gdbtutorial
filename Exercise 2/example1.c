#include "stdlib.h"
#include "stdio.h"

// Returns an array containing [n,n+1,...,m−1,m].
// If n > m, then the array returned is [].
// If an error occurs, NULL is returned.
int* RangeArray(int n,int m){

  if (n > m) {
    return (int *)malloc(0);
  }

  int length = m - n + 1;

  // Heap−allocate the array needed to return.
  int* arry = (int*)malloc(sizeof(int) * length);

  //Initialize the elements.
  for( int i = 0; i < length; ++i)
    arry[i] = i + n;

  return arry;
}

// Accepts two integers as arguments
int main(int argc,char *argv[]) {
  if(argc!=3)
    return EXIT_FAILURE;

// Parse cmd−line args.
  int n = atoi(argv[1]), m = atoi(argv[2]);

  int* nums = RangeArray(n,m);

// Print the resulting array.
  for(int i=0; i<(m-n+1); ++i)
    printf("%d ",nums[i]);
  free(nums);

  puts("");

  return EXIT_SUCCESS;
}
