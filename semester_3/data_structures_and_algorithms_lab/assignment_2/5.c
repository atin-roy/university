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

void addTerm(struct Node **poly, int coef, int exp) {
  struct Node *node = *poly, *prev = NULL;
  while (node && node->exp > exp) {
    prev = node;
    node = node->next;
  }
  if (node && node->exp == exp) {
    node->coef += coef;
  } else {
    struct Node *newNode = createNode(coef, exp);
    if (prev) {
      newNode->next = prev->next;
      prev->next = newNode;
    } else {
      newNode->next = *poly;
      *poly = newNode;
    }
  }
}

struct Node *multiplyPolynomials(struct Node *poly1, struct Node *poly2) {
  struct Node *result = NULL;
  for (; poly1; poly1 = poly1->next) {
    for (struct Node *p = poly2; p; p = p->next) {
      addTerm(&result, poly1->coef * p->coef, poly1->exp + p->exp);
    }
  }
  return result;
}

void printPolynomial(struct Node *poly) {
  while (poly) {
    printf("%dx^%d", poly->coef, poly->exp);
    poly = poly->next;
    if (poly)
      printf(" + ");
  }
  printf("\n");
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
  printf("Enter the first polynomial:\n");
  struct Node *poly1 = inputPolynomial();

  printf("Enter the second polynomial:\n");
  struct Node *poly2 = inputPolynomial();

  struct Node *result = multiplyPolynomials(poly1, poly2);
  printf("Resultant polynomial:\n");
  printPolynomial(result);

  return 0;
}
