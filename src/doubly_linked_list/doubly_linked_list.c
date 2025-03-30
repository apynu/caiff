#include <stdio.h>
#include <stdlib.h>

struct Node {
  struct Node *previousnode;
  int value;
  struct Node *nextnode;
} Node;

struct Node *addNodeToTail(struct Node *Head, int value) {

  struct Node *NewNode = calloc(1, sizeof(struct Node));
  NewNode->nextnode = NULL;
  NewNode->previousnode = NULL;
  NewNode->value = value;

  if (Head->nextnode == NULL) {
    Head->nextnode = NewNode;
    NewNode->previousnode = Head;
  } else {
    struct Node *tmp = Head;

    while (tmp->nextnode != NULL) {
      tmp = tmp->nextnode;
    }
    tmp->nextnode = NewNode;
    NewNode->previousnode = tmp;
  }

  return Head;
}

void removeNode(struct Node *RmNode) {
  struct Node *PrevNode = RmNode->previousnode;

  if (RmNode->nextnode == NULL) {
    PrevNode->nextnode = NULL;
  } else {
    struct Node *NextNode = RmNode->nextnode;

    PrevNode->nextnode = NextNode;
    NextNode->previousnode = PrevNode;
  }
}

int main(void) {

  struct Node *Head;
  Head->nextnode = NULL;
  Head->previousnode = NULL;
  Head->value = 1;

  Head = addNodeToTail(Head, 2);
  Head = addNodeToTail(Head, 3);

  printf("Head Value: %d\n", Head->value);
  printf("Previous Head Value: %d\n\n", Head->nextnode->previousnode->value);

  printf("SecondNode Value: %d\n", Head->nextnode->value);
  printf("Previous SecondNode Value: %d\n\n",
         Head->nextnode->nextnode->previousnode->value);

  printf("ThirdNode Value: %d\n", Head->nextnode->nextnode->value);

  // remove second node
  removeNode(Head->nextnode);
  printf("removed second node\n");
  printf("New SecondNode Value: %d\n\n", Head->nextnode->value);

  // remove new second node (third node)
  removeNode(Head->nextnode);
  if (Head->nextnode == NULL) {
    printf("removed all nodes\n");
  }

  return 0;
}
