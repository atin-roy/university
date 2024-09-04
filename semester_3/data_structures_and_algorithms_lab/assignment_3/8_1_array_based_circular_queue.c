#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int circularQueue[MAX];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() { return (front == (rear + 1) % MAX); }

// Function to check if the queue is empty
int isEmpty() { return (front == -1); }

// Function to insert an element into the circular queue (enqueue)
void enqueue(int value) {
  if (isFull()) {
    printf("Queue Overflow!\n");
    return;
  }
  if (isEmpty()) {
    front = 0;
  }
  rear = (rear + 1) % MAX;
  circularQueue[rear] = value;
  printf("Inserted %d\n", value);
}

// Function to delete an element from the circular queue (dequeue)
void dequeue() {
  if (isEmpty()) {
    printf("Queue Underflow!\n");
    return;
  }
  printf("Deleted %d\n", circularQueue[front]);
  if (front == rear) { // Queue becomes empty after deletion
    front = rear = -1;
  } else {
    front = (front + 1) % MAX;
  }
}

// Function to display the queue elements
void displayQueue() {
  if (isEmpty()) {
    printf("Queue is empty\n");
    return;
  }

  printf("Queue elements: ");
  int i = front;
  while (1) {
    printf("%d ", circularQueue[i]);
    if (i == rear)
      break;
    i = (i + 1) % MAX;
  }
  printf("\n");
}

int main() {
  int choice, value;

  while (1) {
    printf("\n--- Circular Queue Using Array ---\n");
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
      enqueue(value);
      break;
    case 2:
      dequeue();
      break;
    case 3:
      displayQueue();
      break;
    case 4:
      exit(0);
    default:
      printf("Invalid choice\n");
    }
  }
  return 0;
}
