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

void push(struct Node **head, int data) {
  struct Node *newNode = createNode(data);
  newNode->next = *head;
  *head = newNode;
  return;
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

int pop(struct Node **head) {
  if (*head == NULL) {
    printf("Stack underflow\n");
    return -1;
  }
  struct Node *temp = *head;
  int value = temp->data;
  *head = (*head)->next;
  free(temp);
  return value;
}

int peek(struct Node *head) {
  if (head == NULL) {
    printf("Stack is empty\n");
    return -1;
  }
  return head->data;
}

int isEmpty(struct Node *head) {
  if (head == NULL) {
    return 1;
  }

  return 0;
}

void print(struct Node *head) {
  struct Node *temp = head;
  if (isEmpty(temp)) {
    printf("Stack is empty\n");
    return;
  }
  while (temp != NULL) {
    printf("%d", temp->data);
    if (temp->next != NULL) {
      printf("->");
    }
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  struct Node *stack = NULL;
  int choice, value;

  do {
    printf("\nStack Operations:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Check if Empty\n");
    printf("5. Print Stack\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter value to push: ");
      scanf("%d", &value);
      push(&stack, value);
      break;
    case 2:
      value = pop(&stack);
      if (value != -1) {
        printf("Popped value: %d\n", value);
      }
      break;
    case 3:
      value = peek(stack);
      if (value != -1) {
        printf("Top value: %d\n", value);
      }
      break;
    case 4:
      if (isEmpty(stack)) {
        printf("Stack is empty\n");
      } else {
        printf("Stack is not empty\n");
      }
      break;
    case 5:
      print(stack);
      break;
    case 6:
      printf("Exiting...\n");
      break;
    default:
      printf("Invalid choice! Please try again.\n");
    }
  } while (choice != 6);

  // Free memory before exit
  while (!isEmpty(stack)) {
    pop(&stack);
  }

  return 0;
}
