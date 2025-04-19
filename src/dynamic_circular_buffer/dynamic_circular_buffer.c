#include <stdio.h>
#include <stdlib.h>

struct Node {
  struct Node *nextNode;
  int value;
};

void addNodeToBuffer(struct Node *Head, int value) {
  struct Node *NewNode = malloc(sizeof(struct Node));
  NewNode->value = value;

  if (Head->nextNode == NULL) {
    Head->nextNode = NewNode;
  } else {
    struct Node *p = Head;
    while (p->nextNode != NULL && p->nextNode != Head) {
      p = p->nextNode;
    }
    p->nextNode = NewNode;
  }
  NewNode->nextNode = Head;
}

int main(void) {
  struct Node *Head = malloc(sizeof(struct Node));
  Head->nextNode = NULL;
  Head->value = 1;

  addNodeToBuffer(Head, 2);
  addNodeToBuffer(Head, 3);
  addNodeToBuffer(Head, 4);

  struct Node *LastNode = Head->nextNode->nextNode->nextNode;

  if (LastNode->nextNode == Head) {
    printf("Works");
  }

  return 0;
}
