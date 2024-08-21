#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int coef;
  int exp;
  struct Node *next;
};

struct Node *createNode(int coef, int exp) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->coef = coef;
  node->exp = exp;
  node->next = NULL;
  return node;
}

int evaluatePolynomial(struct Node *poly, int x) {
  int result = 0;
  while (poly) {
    result += poly->coef * pow(x, poly->exp);
    poly = poly->next;
  }
  return result;
}

struct Node *inputPolynomial() {
  int n, coef, exp;
  struct Node *head = NULL, **lastPtrRef = &head;

  printf("Enter the number of terms: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("Enter coefficient and exponent: ");
    scanf("%d %d", &coef, &exp);
    *lastPtrRef = createNode(coef, exp);
    lastPtrRef = &(*lastPtrRef)->next;
  }

  return head;
}

int main() {
  printf("Enter the polynomial:\n");
  struct Node *poly = inputPolynomial();

  int x;
  printf("Enter the value of x: ");
  scanf("%d", &x);

  printf("Result: %d\n", evaluatePolynomial(poly, x));

  return 0;
}
