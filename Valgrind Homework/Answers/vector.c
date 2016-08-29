#include "assert.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"

// An arbitrary pointer to represent an element in the vector.
typedef void* element_t;

// An expandable array of element_ts.
typedef struct vector_t {
  size_t length;
  element_t *arry;
} *vector_t;

// On success, return vector_t with an initial length of n.
// On failure, returns NULL.  Assumes v != NULL.
vector_t VectorCreate(size_t n);

// Frees the memory allocated for the vector_t.  Assumes v != NULL.
void VectorFree(vector_t v);

// Sets the nth element of v to be e.  Returns the previous nth element_t in prev.
// Freeing e is the responsibility of the user, not the vector_t.
// Returns true iff successful.  Assumes v != NULL.
bool VectorSet(vector_t v, uint32_t index, element_t e, element_t *prev);

// Returns the element at the given index within v.  Assumes v != NULL.
element_t VectorGet(vector_t v, uint32_t index);

// Returns the length of v.  Assumes v != NULL.
size_t VectorLength(vector_t v);

//// Helper functions (assume not buggy)

// Returns a copy of arry with new length newLen.  If newLen < oldLen
// then the returned array is clipped.  If newLen > oldLen, then the
// resulting array will be padded with NULL elements.
static element_t *ResizeArray(element_t *arry, size_t oldLen, size_t newLen);

// Print the elements in the vector on a line.
static void PrintIntVector(vector_t v);

#define N 10 // Test vector length.
int main(int argc, char *argv[]) {
  uint32_t i;
  vector_t v = VectorCreate(4);

  if (v == NULL)
    return EXIT_FAILURE;

  for (i = 0; i < N; ++i) { // Place some elements in the vector.
    int *x = (int*)malloc(sizeof(int));

    // ERROR: The value of the item to be placed is not initialized. This leads
    // to a memory error in the functions where the value of the elements is
    // printed (PrintIntVector). To fix this, we'll just initialize the values.
    *x = i; //or any integer value.

    element_t old;
    VectorSet(v, i, x, &old);
  }

  PrintIntVector(v);

  // ERROR: Vector must be freed (along with its elements) to avoid memory
  // leaks. To fix this, we'll just add a call to VectorFree.
  VectorFree(v);

  return EXIT_SUCCESS;
}


vector_t VectorCreate(size_t n) {
  vector_t v = (vector_t)malloc(sizeof(struct vector_t));
  v->arry = (element_t*)malloc(n*sizeof(element_t));
  if (v == NULL || v->arry == NULL)
    return NULL;

  // ERROR: Vector's length is not initialized upon creation. This leads to a
  // memory error on the functions (conditional jump on uninitialised values)
  // where the length of the vector is required:
  // * VectorSet
  // * ResizeArray
  // To fix, we'll just add an initialization statement to v->length.
  v->length = n;

  return v;
}

void VectorFree(vector_t v) {
  assert(v != NULL);

  // ERROR: Each element of v->arry must be freed because they are allocated
  // pointers. To fix this, we'll just free each element of v->arry. This must
  // be written in the main function (because it is not the responsibility of
  // the vector according to the documentation), but I believe that it would be
  // more appropriate here.
  for (int i = 0; i < v->length; i++) {
    free(v->arry[i]);
  }

  free(v->arry);
  free(v);
}

bool VectorSet(vector_t v, uint32_t index, element_t e, element_t *prev) {
  assert(v != NULL);

  if (index >= v->length) {
    size_t newLength = index+1;

    // ERROR: The ResizeArray function does not free the old array, leading to
    // memory leaks. To fix this, we'll just keep track of the old array so we
    // can free it after resizing.
    element_t* oldArry = v->arry;
    v->arry = ResizeArray(v->arry, v->length, newLength);
    free(oldArry);

    v->length = newLength;
  } else {
    prev = v->arry[index];
  }

  v->arry[index] = e;

  return true;
}

element_t VectorGet(vector_t v, uint32_t index) {
  assert(v != NULL);
  return v->arry[index];
}

size_t VectorLength(vector_t v) {
  assert(v != NULL);
  return v->length;
}

static element_t *ResizeArray(element_t *arry, size_t oldLen, size_t newLen) {
  uint32_t i;
  size_t copyLen = oldLen > newLen ? newLen : oldLen;
  element_t *newArry;

  assert(arry != NULL);

  newArry = (element_t*)malloc(newLen*sizeof(element_t));

  if (newArry == NULL)
    return NULL; // malloc error!!!

  // Copy elements to new array
  for (i = 0; i < copyLen; ++i)
    newArry[i] = arry[i];

  // Null initialize rest of new array.
  for (i = copyLen; i < newLen; ++i)
    newArry[i] = NULL;

  return newArry;
}

static void PrintIntVector(vector_t v) {
  uint32_t i;
  size_t length;

  assert(v != NULL);

  length = VectorLength(v);

  if (length > 0) {
    printf("[%d", *((int*)VectorGet(v, 0)));
    for (i = 1; i < VectorLength(v); ++i)
      printf(",%d", *((int*)VectorGet(v, i)));
    printf("]\n");
  }
}
