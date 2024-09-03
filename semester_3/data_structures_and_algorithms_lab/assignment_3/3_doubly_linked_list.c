#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
  struct Node *previous;
};

struct Node *createNode(int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (newNode == NULL) {
    printf("Memory allocation failed\n");
    exit(1);
  }
  newNode->data = data;
  newNode->next = NULL;
  newNode->previous = NULL;
  return newNode;
}

void insert(struct Node **head, int data, int position) {
  struct Node *newNode = createNode(data);

  if (position < 1) {
    printf("Invalid position\n");
    free(newNode);
    return;
  }

  if (*head == NULL || position == 1) {
    newNode->next = *head;
    if (*head != NULL) {
      (*head)->previous = newNode;
    }
    *head = newNode;
    return;
  }

  struct Node *temp = *head;
  for (int i = 1; temp != NULL && i < position - 1; i++) {
    temp = temp->next;
  }

  if (temp == NULL) {
    printf("Position out of bounds\n");
    free(newNode);
    return;
  }

  newNode->next = temp->next;
  newNode->previous = temp;
  if (temp->next != NULL) {
    temp->next->previous = newNode;
  }
  temp->next = newNode;
}

void append(struct Node **head, int data) {
  struct Node *newNode = createNode(data);
  if (*head == NULL) {
    *head = newNode;
    return;
  }

  struct Node *temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->previous = temp;
}

void deleteNode(struct Node **head, int position) {
  if (position < 1 || *head == NULL) {
    printf("Invalid position or empty list\n");
    return;
  }

  struct Node *temp = *head;

  if (position == 1) {
    *head = (*head)->next;
    if (*head != NULL) {
      (*head)->previous = NULL;
    }
    free(temp);
    return;
  }

  for (int i = 1; temp != NULL && i < position; i++) {
    temp = temp->next;
  }

  if (temp == NULL) {
    printf("Position out of bounds\n");
    return;
  }

  if (temp->next != NULL) {
    temp->next->previous = temp->previous;
  }
  if (temp->previous != NULL) {
    temp->previous->next = temp->next;
  }

  free(temp);
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
  printf("\n");
}

void reversePrint(struct Node *head) {
  struct Node *temp = head;
  if (temp == NULL) {
    return;
  }

  while (temp->next != NULL) {
    temp = temp->next;
  }

  while (temp != NULL) {
    printf("%d", temp->data);
    if (temp->previous != NULL) {
      printf("<-");
    }
    temp = temp->previous;
  }
  printf("\n");
}

void reverseLinkedList(struct Node **head) {
  struct Node *current = *head;
  struct Node *temp = NULL;

  while (current != NULL) {
    temp = current->previous;
    current->previous = current->next;
    current->next = temp;
    current = current->previous;
  }

  if (temp != NULL) {
    *head = temp->previous;
  }
}

int main() {
  // Initialize the head of the list to NULL
  struct Node *head = NULL;

  // Insert elements into the linked list
  insert(&head, 10, 1); // Insert 10 at position 1
  insert(&head, 20, 2); // Insert 20 at position 2
  insert(&head, 15, 2); // Insert 15 at position 2
  append(&head, 30);    // Append 30 at the end of the list

  printf("Original Linked List: ");
  print(head); // Print the linked list

  // Test the size function
  int len = size(head);
  printf("Size of the linked list: %d\n", len);

  // Delete an element from the linked list
  deleteNode(&head, 3); // Delete the element at position 3

  printf("Linked List after deletion at position 3: ");
  print(head);

  // Reverse the linked list
  reverseLinkedList(&head);

  printf("Reversed Linked List: ");
  print(head);

  // Print the linked list in reverse order
  printf("Linked List printed in reverse order: ");
  reversePrint(head);

  // Clean up memory by deleting all nodes
  while (head != NULL) {
    deleteNode(&head, 1);
  }

  return 0;
}

