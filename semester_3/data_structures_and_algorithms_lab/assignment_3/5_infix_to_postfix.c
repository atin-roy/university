#include <ctype.h>
#include <stdio.h>

#define MAX 100

struct Stack {
  int top;
  char arr[MAX];
};

void initStack(struct Stack *s) { s->top = -1; }

int isEmpty(struct Stack *s) { return s->top == -1; }

int isFull(struct Stack *s) { return s->top == MAX - 1; }

void push(struct Stack *s, char c) {
  if (isFull(s)) {
    printf("Stack overflow\n");
    return;
  }
  s->arr[++(s->top)] = c;
}

char pop(struct Stack *s) {
  if (isEmpty(s)) {
    printf("Stack underflow\n");
    return '\0';
  }
  return s->arr[(s->top)--];
}

char peek(struct Stack *s) {
  if (isEmpty(s)) {
    return '\0';
  }
  return s->arr[s->top];
}

int precedence(char c) {
  if (c == '+' || c == '-') {
    return 1;
  } else if (c == '*' || c == '/') {
    return 2;
  } else if (c == '^') {
    return 3;
  }
  return 0;
}

// Function to convert infix expression to postfix
void infixToPostfix(char *infix) {
  struct Stack s;
  initStack(&s);
  char postfix[MAX];
  int k = 0;

  for (int i = 0; infix[i] != '\0'; i++) {
    // If the scanned character is an operand, add it to the output
    if (isalnum(infix[i])) {
      postfix[k++] = infix[i];
    }
    // If the scanned character is '(', push it to the stack
    else if (infix[i] == '(') {
      push(&s, infix[i]);
    }
    // If the scanned character is ')', pop and output from the stack until '('
    // is found
    else if (infix[i] == ')') {
      while (!isEmpty(&s) && peek(&s) != '(') {
        postfix[k++] = pop(&s);
      }
      pop(&s); // Remove '(' from the stack
    }
    // If an operator is encountered
    else {
      while (!isEmpty(&s) && precedence(infix[i]) <= precedence(peek(&s))) {
        postfix[k++] = pop(&s);
      }
      push(&s, infix[i]);
    }
  }

  // Pop all remaining operators from the stack
  while (!isEmpty(&s)) {
    postfix[k++] = pop(&s);
  }

  postfix[k] = '\0'; // Null terminate the postfix expression

  int i = 0;
  while (i < 100 && postfix[i] != '\0') {
    printf("%c ", postfix[i]);
    i++;
  }
  printf("\n");
}

int main() {
  char infix[MAX];
  printf("Enter infix expression: ");
  scanf("%s", infix);

  infixToPostfix(infix);

  return 0;
}
