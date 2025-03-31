#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node *nextnode;
} Node;

void addNodeToTail(struct Node *Head, int value) {

  struct Node *NewNode = calloc(1, sizeof(struct Node));
  NewNode->nextnode = NULL;
  NewNode->value = value;

  if (Head->nextnode == NULL) {
    Head->nextnode = NewNode;
  } else {
    struct Node *tmp = Head;

    while (tmp->nextnode != NULL) {
      tmp = tmp->nextnode;
    }
    tmp->nextnode = NewNode;
  }
}

int main(void) {

  struct Node *Head;

  Head->value = 1;
  addNodeToTail(Head, 2);
  addNodeToTail(Head, 3);

  printf("Head Value: %d\n", Head->value);
  printf("SecondNode Value: %d\n", Head->nextnode->value);
  printf("ThirdNode Value: %d\n", Head->nextnode->nextnode->value);

  return 0;
}
