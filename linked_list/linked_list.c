#include <stdio.h>

struct Node {
  int value;
  struct Node *nodepointer;
};

struct Node addNodeToTail(struct Node *Head, int value) {
  struct Node NewNode;

  NewNode.value = value;
  NewNode.nodepointer = NULL;

  Head->nodepointer = &NewNode;

  return NewNode;
}

int main(void) {

  struct Node FirstNode;
  FirstNode.value = 0;

  struct Node NewNode = addNodeToTail(&FirstNode, 1);

  printf("NewNode Value: %d", FirstNode.nodepointer->value);
  return 0;
}
