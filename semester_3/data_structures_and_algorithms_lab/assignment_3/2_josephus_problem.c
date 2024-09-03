#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *createNode(int data) {
  struct Node *newNode = (struct Node *)(malloc(sizeof(struct Node)));
  if (newNode == NULL) {
    printf("Memory allocation failed\n");
    exit(1);
  }
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

struct Node *createCircularLinkedList(int n) {
  struct Node *head = createNode(1);
  struct Node *temp = head;
  int i = 2;
  while (i <= n) {
    temp->next = createNode(i);
    temp = temp->next;
    i++;
  }

  temp->next = head;
  return head;
}

struct Node *josephusProblem(struct Node *head, int k) {
  struct Node *temp = head;
  struct Node *temp2 = head;
  int i;
  while (1) {
    for (i = 0; i < k - 1; i++) {
      temp = temp->next;
    }
    temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
    if (temp->next == temp) {
      return temp;
    }
    temp = temp->next;
  }

  return NULL;
}

int main() {
  int n, k;

  printf("Enter the number of people: ");
  scanf("%d", &n);
  printf("Enter the step size: ");
  scanf("%d", &k);

  if (n <= 0 || k <= 0) {
    printf("The number of people and the step size must be greater than 0.\n");
    return 1;
  }

  struct Node *head = createCircularLinkedList(n);
  struct Node *winner = josephusProblem(head, k);
  printf("winner is %d\n", winner->data);
  free(winner);
  return 0;
}
