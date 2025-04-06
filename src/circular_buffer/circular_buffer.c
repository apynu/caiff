#include <stdio.h>
#include <stdlib.h>

struct Node {
  struct Node *nextNode;
  int value;
};

void addNodeToBuffer(struct Node *Head, int value) {
  struct Node *NewNode = calloc(1, sizeof(struct Node));
  NewNode->value = value;

  if (Head->nextNode == NULL) {
    Head->nextNode = NewNode;
  } else {
    struct Node *p = Head;
    while (p->nextNode != NULL) {
      p = p->nextNode;
    }
    p->nextNode = NewNode;
  }
  NewNode->nextNode = Head;
}

int main(void) { return 0; }
