#include <stdio.h>
// NOTE: needs to be build with -fno-stack-protector flag, otherwise the
// compiler will throw a stack smashing error

// DAMN YOU OS MEMORY MANAGER!!!!!!! xD
/*
int main(void) {
  // object is the object that is being stored size times
  // size is the size of the array
  // int* to the first object in the array
  int object = 3;
  int size = 10;

  int *arrayp = &object;
  printf("arrayp init value: %d\n", *arrayp);
  printf("\n");

  for (int i = 0; i < size; i++) {
    arrayp++;
    // fill up everything with 10s except for the first object which will be a 3
    *arrayp = i + 5;
    printf("Arrayp %d value: %d\n", i, *arrayp);
    printf("Prev Arrayp %d value: %d\n", i, *(arrayp - 1));
    arrayp--;
    printf("\n");
  }

  if (arrayp != NULL) {
    printf("hell\n");
    printf("curr arrayp value: %d", *(arrayp - 9));

    int *firstvalue = arrayp - 9;

    printf("FirstArray value: %d", *firstvalue);
  }

  return 0;
}
*/

int main(void) {
  int object = 3;

  // assuming that the next 3 int sized memory adresses are unallocated
  int size = 3;

  int *arrayp = &object;

  for (int i = 0; i < size; i++) {
    arrayp++;
    *arrayp = 10;
  }

  printf("arrayp: %d", *(arrayp - 3));
}
