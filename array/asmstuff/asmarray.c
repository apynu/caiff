#include <stdint.h>
#include <stdio.h>

// NOTE: needs to be build with -fno-stack-protector flag, otherwise the
// compiler will throw a stack smashing error

int *intarray(int size) {
  // allocated int sized memory blocks on the stack via inline x86_64 asm
  // long cause 64 bit
  int *baseptr;

  __asm__ __volatile__("subq $16, %%rsp \n\t"
                       "subq %1, %%rsp \n\t"
                       "movq %%rsp, %0 \n\t"
                       : "=r"(baseptr)
                       : "r"((long)size)
                       : "rsp");
  return baseptr;
}

/*
int *carray(int element1, int element2, int element3) {
  // save baseptr to not lose address
  int *baseptr = &element1;

  // assuming that the next 3 int sized memory adresses are unallocated
  int *arrayp = baseptr;

  arrayp++;
  *arrayp = element2;

  arrayp++;
  *arrayp = element3;
  return (baseptr);
}
*/

int main(void) {
  int size = 10;
  int *baseptr = intarray(size);
  int *arrayp = baseptr;

  *arrayp = 10;
  //*(arrayp + 1) = 3;
  //*(arrayp + 2) = 4;
  //*(arrayp + 3) = 5;

  printf("arrayp: %d\n", *baseptr);
  // printf("arrayp: %d\n", *(baseptr + 1));
  // printf("arrayp: %d\n", *(baseptr + 2));
  // printf("arrayp: %d\n", *(baseptr + 3));

  __asm__ __volatile__("addq %0, %%rsp \n\t" : : "r"((long)size) : "rsp");

  // int element2 = 10;
  // printf("arrayp: %d", *(carray(3, element2, 4) + 1));
  return 0;
}
