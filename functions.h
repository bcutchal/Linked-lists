#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct NODE {
  int value;
  double key1;
  double key2;
  struct NODE *next;
  struct NODE *sort1;
  struct NODE *sort2;
} Node;

Node *rand_list(int num) {
  Node node[num];
  Node *head = &node[0];
  srand(time(0));
  int i;

  for (i = 0; i < num; i++) {
    node[i].value = rand() % 11;
    node[i].key1 = (double)(rand() % 41 + 10);
    node[i].key2 = (double)(rand() % 41 + 50);
    if (i == (num - 1)) {
      node[i].next = NULL;
    } else {
      node[i].next = &node[i + 1];
    }
    node[i].sort1 = NULL;
    node[i].sort2 = NULL;
    printf("< %d, %f, %f > %p -> %p\n", node[i].value, node[i].key1,
           node[i].key2, &node[i], node[i].next);
  }

  return head;
}

void print_list(Node *head) {
  Node *temp = head;

  while (temp != NULL) {
    printf("< %d, %f, %f > %p\n", temp->value, temp->key1, temp->key2,
           temp->next);
    temp = temp->next;
    printf("%p\n", temp);
  }
}
