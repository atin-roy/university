#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node {
  int data;
  struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Function to check if the queue is empty
int isEmptyLL() { return front == NULL; }

// Function to insert an element into the circular queue (enqueue)
void enqueueLL(int value) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (newNode == NULL) {
    printf("Memory Overflow!\n");
    return;
  }
  newNode->data = value;
  newNode->next = front; // Point to the front to create the circular structure

  if (isEmptyLL()) {
    front = rear = newNode;
    rear->next = front; // Single node points to itself
  } else {
    rear->next = newNode;
    rear = newNode;
  }
  printf("Inserted %d\n", value);
}

// Function to delete an element from the circular queue (dequeue)
void dequeueLL() {
  if (isEmptyLL()) {
    printf("Queue Underflow!\n");
    return;
  }

  if (front == rear) { // Only one node in the queue
    printf("Deleted %d\n", front->data);
    free(front);
    front = rear = NULL;
  } else {
    struct Node *temp = front;
    printf("Deleted %d\n", front->data);
    front = front->next;
    rear->next = front; // Maintain circular link
    free(temp);
  }
}

// Function to display the queue elements
void displayQueueLL() {
  if (isEmptyLL()) {
    printf("Queue is empty\n");
    return;
  }

  struct Node *temp = front;
  printf("Queue elements: ");

  do {
    printf("%d ", temp->data);
    temp = temp->next;
  } while (temp != front); // Stop when back at the front
  printf("\n");
}

int main() {
  int choice, value;

  while (1) {
    printf("\n--- Circular Queue Using Linked List ---\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display Queue\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter value to enqueue: ");
      scanf("%d", &value);
      enqueueLL(value);
      break;
    case 2:
      dequeueLL();
      break;
    case 3:
      displayQueueLL();
      break;
    case 4:
      exit(0);
    default:
      printf("Invalid choice\n");
    }
  }
  return 0;
}
