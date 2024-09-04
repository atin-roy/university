#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Function to check if the queue is empty
int isEmpty() { return front == -1; }

// Function to check if the queue is full
int isFull() { return rear == MAX - 1; }

// Function to insert an element into the queue (enqueue)
void enqueue(int value) {
  if (isFull()) {
    printf("Queue Overflow!\n");
    return;
  }
  if (isEmpty()) {
    front = 0;
  }
  queue[++rear] = value;
  printf("Inserted %d\n", value);
}

// Function to delete an element from the queue (dequeue)
void dequeue() {
  if (isEmpty()) {
    printf("Queue Underflow!\n");
    return;
  }
  printf("Deleted %d\n", queue[front]);
  if (front == rear) {
    front = rear = -1; // Queue becomes empty
  } else {
    front++;
  }
}

// Function to display the number of elements
void displayQueue() {
  if (isEmpty()) {
    printf("Queue is empty\n");
    return;
  }
  printf("Queue elements are: ");
  for (int i = front; i <= rear; i++) {
    printf("%d ", queue[i]);
  }
  printf("\n");
}

int main() {
  int choice, value;

  while (1) {
    printf("\n--- Array-based Queue ---\n");
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
