#include <stdio.h>
// NOTE: needs to be build with -fno-stack-protector flag, otherwise the
// compiler will throw a stack smashing error

int *carray(int element1, int element2, int element3) {
  // assuming that the next 3 int sized memory adresses are unallocated
  int *arrayp = &element1;

  arrayp++;
  *arrayp = element2;

  arrayp++;
  *arrayp = element3;
  return (arrayp - 2);
}

int main(void) {
  int element2 = 10;
  printf("arrayp: %d", *(carray(3, element2, 4) + 1));
  return 0;
}
