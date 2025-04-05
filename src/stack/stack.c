#include <stdio.h>
#include <stdlib.h>

struct Element {
  struct Element *previousElement;
  int value;
};

struct Element *push(struct Element *LastElement, int value) {
  struct Element *NewElement = calloc(1, sizeof(struct Element));
  NewElement->previousElement = LastElement;
  NewElement->value = value;

  return NewElement;
}

struct Element *pop(struct Element *LastElement) {

  if (LastElement->previousElement != NULL) {
    return LastElement->previousElement;
  }
  return NULL;
};

int main(void) {
  struct Element *LastElement = calloc(1, sizeof(struct Element));
  LastElement->previousElement = NULL;
  LastElement->value = 0;

  printf("Initial Value: %d\n", LastElement->value);

  LastElement = push(LastElement, 1);
  printf("Value: %d\n", LastElement->value);

  LastElement = push(LastElement, 2);
  printf("Value: %d\n", LastElement->value);

  LastElement = push(LastElement, 3);
  printf("Value: %d\n", LastElement->value);

  LastElement = push(LastElement, 4);
  printf("Value: %d\n", LastElement->value);

  LastElement = pop(LastElement);
  printf("Value: %d\n", LastElement->value);

  return 0;
}
