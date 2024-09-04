#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Define the stack structure
struct Stack {
  int arr[MAX];
  int top;
};

// Function to initialize a stack
void initStack(struct Stack *s) { s->top = -1; }

// Function to check if a stack is empty
int isEmpty(struct Stack *s) { return s->top == -1; }

// Function to check if a stack is full
int isFull(struct Stack *s) { return s->top == MAX - 1; }

// Function to push an element onto the stack
void push(struct Stack *s, int value) {
  if (isFull(s)) {
    printf("Stack Overflow\n");
    return;
  }
  s->arr[++s->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack *s) {
  if (isEmpty(s)) {
    printf("Stack Underflow\n");
    return -1; // Return -1 if the stack is empty
  }
  return s->arr[s->top--];
}

// Queue structure using two stacks
struct Queue {
  struct Stack *stack1;
  struct Stack *stack2;
};

// Function to initialize a queue
void initQueue(struct Queue *q) {
  q->stack1 = (struct Stack *)malloc(sizeof(struct Stack));
  q->stack2 = (struct Stack *)malloc(sizeof(struct Stack));
  initStack(q->stack1);
  initStack(q->stack2);
}

// Function to enqueue an element (push to stack1)
void enqueue(struct Queue *q, int value) {
  push(q->stack1, value);
  printf("Enqueued %d\n", value);
}

// Function to dequeue an element (pop from stack2)
int dequeue(struct Queue *q) {
  // If stack2 is empty, transfer all elements from stack1 to stack2
  if (isEmpty(q->stack2)) {
    while (!isEmpty(q->stack1)) {
      push(q->stack2, pop(q->stack1));
    }
  }

  // If stack2 is still empty after transferring, the queue is empty
  if (isEmpty(q->stack2)) {
    printf("Queue Underflow\n");
    return -1;
  }

  // Pop from stack2 (the front of the queue)
  return pop(q->stack2);
}

// Modified Function to display the current state of the queue
void displayQueue(struct Queue *q) {
  if (isEmpty(q->stack1) && isEmpty(q->stack2)) {
    printf("Queue is empty\n");
    return;
  }

  printf("Queue elements: ");

  // Print elements of stack2 in reverse order (FIFO)
  for (int i = q->stack2->top; i >= 0; i--) {
    printf("%d ", q->stack2->arr[i]);
  }

  // Print elements of stack1 in order
  for (int i = 0; i <= q->stack1->top; i++) {
    printf("%d ", q->stack1->arr[i]);
  }
  printf("\n");
}

// Main function
int main() {
  struct Queue q;
  initQueue(&q);

  int choice, value;

  while (1) {
    printf("\n--- Queue Using Two Stacks ---\n");
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
      enqueue(&q, value);
      break;
    case 2:
      value = dequeue(&q);
      if (value != -1) {
        printf("Dequeued %d\n", value);
      }
      break;
    case 3:
      displayQueue(&q);
      break;
    case 4:
      exit(0);
    default:
      printf("Invalid choice\n");
    }
  }

  return 0;
}

