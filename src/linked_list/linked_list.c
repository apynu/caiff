#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node *nodepointer;
} Node;

struct Node *addNodeToTail(struct Node *Head, int value) {

  // creat new node
  struct Node *NewNode = calloc(1, sizeof(struct Node));

  // set new nodepointer to nodepoiner where head points to?
  NewNode->nodepointer = Head->nodepointer;

  Head->nodepointer = NewNode;

  while (NewNode->nodepointer != NULL) {
    NewNode = NewNode->nodepointer;
  }

  NewNode->nodepointer = NULL;
  NewNode->value = value;

  return Head;
}

int main(void) {

  struct Node *Head;
  Head->value = 1;
  printf("Head Value: %d\n", Head->value);
  Head = addNodeToTail(Head, 2);
  printf("SecondNode Value: %d\n", Head->nodepointer->value);
  Head = addNodeToTail(Head, 3);
  printf("ThirdNode Value: %d\n", Head->nodepointer->nodepointer->value);

  printf("Head Value: %d\n", Head->value);
  printf("SecondNode Value: %d\n", Head->nodepointer->value);
  printf("ThirdNode Value: %d\n", Head->nodepointer->nodepointer->value);

  return 0;
}
