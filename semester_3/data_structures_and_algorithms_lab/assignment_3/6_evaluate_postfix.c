#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

double stack[MAX];
int top = -1;

void push(double value) {
  if (top < MAX - 1) {
    stack[++top] = value;
  } else {
    printf("Stack Overflow\n");
  }
}

double pop() {
  if (top >= 0) {
    return stack[top--];
  } else {
    printf("Stack Underflow\n");
    return -1;
  }
}

double evaluatePostfix(char *exp) {
  char *token = strtok(exp, " "); // Split the input by spaces

  while (token != NULL) {
    if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
      push(strtod(token, NULL)); // Convert string to double
    } else if (strlen(token) == 1 && (token[0] == '+' || token[0] == '-' ||
                                      token[0] == '*' || token[0] == '/')) {
      double val2 = pop();
      double val1 = pop();

      switch (token[0]) {
      case '+':
        push(val1 + val2);
        break;
      case '-':
        push(val1 - val2);
        break;
      case '*':
        push(val1 * val2);
        break;
      case '/':
        push(val1 / val2);
        break;
      }
    }

    token = strtok(NULL, " "); // Move to the next token
  }

  return pop();
}

int main() {
  char exp[MAX];

  printf(
      "Enter a postfix expression (with spaces between numbers/operators): ");
  fgets(exp, MAX, stdin);

  exp[strcspn(exp, "\n")] = 0;

  double result = evaluatePostfix(exp);

  printf("Result of postfix expression: %.2f\n", result);

  return 0;
}
