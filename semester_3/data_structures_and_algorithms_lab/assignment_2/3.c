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

struct Node *addPolynomials(struct Node *poly1, struct Node *poly2) {
  struct Node *result = NULL, **lastPtrRef = &result;
  while (poly1 && poly2) {
    if (poly1->exp > poly2->exp) {
      *lastPtrRef = createNode(poly1->coef, poly1->exp);
      poly1 = poly1->next;
    } else if (poly1->exp < poly2->exp) {
      *lastPtrRef = createNode(poly2->coef, poly2->exp);
      poly2 = poly2->next;
    } else {
      *lastPtrRef = createNode(poly1->coef + poly2->coef, poly1->exp);
      poly1 = poly1->next;
      poly2 = poly2->next;
    }
    lastPtrRef = &(*lastPtrRef)->next;
  }
  *lastPtrRef = (poly1) ? poly1 : poly2;
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

  struct Node *result = addPolynomials(poly1, poly2);
  printf("Resultant polynomial:\n");
  printPolynomial(result);

  return 0;
}
