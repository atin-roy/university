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

void insert(struct Node **head, int data, int position) {
  if (position < 1) {
    printf("Invalid position\n");
    return;
  }

  if (position == 1) {
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    return;
  }

  int index = 1;
  struct Node *temp = *head;
  while (temp != NULL && index < position - 1) {
    temp = temp->next;
    index++;
  }

  if (temp == NULL) {
    printf("Position out of bounds\n");
    return;
  }

  struct Node *nextNode = temp->next;
  temp->next = createNode(data);
  temp->next->next = nextNode;
}

void append(struct Node *head, int data) {
  struct Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = createNode(data);
  return;
}

void delete(struct Node **head, int position) {
  if (position < 1) {
    printf("Invalid position\n");
    return;
  }

  if (position == 1) {
    *head = (*head)->next;
    return;
  }

  struct Node *temp = *head;
  for (int i = 1; temp != NULL && i < position - 1; i++) {
    temp = temp->next;
  }

  if (temp == NULL || temp->next == NULL) {
    printf("Position out of bounds\n");
    return;
  }

  struct Node *nextNode = temp->next->next;
  free(temp->next);
  temp->next = nextNode;
}

int size(struct Node *head) {
  int count = 0;
  struct Node *temp = head;
  while (temp != NULL) {
    count++;
    temp = temp->next;
  }

  return count;
}

void print(struct Node *head) {
  struct Node *temp = head;
  while (temp != NULL) {
    printf("%d", temp->data);
    if (temp->next != NULL) {
      printf("->");
    }
    temp = temp->next;
  }
}

void reversePrint(struct Node *head) {
  struct Node *temp = head;
  int len = size(head);
  int arr[len];
  for (int i = len - 1; i >= 0; i--) {
    arr[i] = temp->data;
    temp = temp->next;
  }

  for (int i = 0; i < len; i++) {
    printf("%d", arr[i]);
    if (i != len - 1) {
      printf("<-");
    }
  }
}

void reverseLinkedList(struct Node **head) {
  struct Node *newHead = NULL;
  struct Node *temp = *head;
  struct Node *nextNode = NULL;
  while (temp != NULL) {
    nextNode = temp->next;
    temp->next = newHead;
    newHead = temp;
    temp = nextNode;
  }

  *head = newHead;
}
int main() {
  // Initialize the head of the list to NULL
  struct Node *head = NULL;

  // Insert elements into the linked list
  insert(&head, 10, 1); // Insert 10 at position 1
  insert(&head, 20, 2); // Insert 20 at position 2
  insert(&head, 15, 2); // Insert 15 at position 2
  append(head, 30);     // Append 30 at the end of the list

  printf("Original Linked List: ");
  print(head); // Print the linked list
  printf("\n");

  // Test the size function
  int len = size(head);
  printf("Size of the linked list: %d\n", len);

  // Delete an element from the linked list
  delete (&head, 3); // Delete the element at position 3

  printf("Linked List after deletion at position 3: ");
  print(head);
  printf("\n");

  // Reverse the linked list
  reverseLinkedList(&head);

  printf("Reversed Linked List: ");
  print(head);
  printf("\n");

  // Print the linked list in reverse order
  printf("Linked List printed in reverse order: ");
  reversePrint(head);
  printf("\n");

  // Clean up memory by deleting all nodes
  while (head != NULL) {
    delete (&head, 1);
  }

  return 0;
}
