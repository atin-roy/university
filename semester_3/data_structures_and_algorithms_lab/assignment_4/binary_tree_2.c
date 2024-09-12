#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node *newNode(int data) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

int search(int inorder[], int start, int end, int value) {
  for (int i = start; i <= end; i++) {
    if (inorder[i] == value)
      return i;
  }
  return -1;
}

struct Node *buildTree(int inorder[], int preorder[], int inStart, int inEnd,
                       int *preIndex) {
  if (inStart > inEnd) {
    return NULL;
  }

  int current = preorder[*preIndex];
  (*preIndex)++;

  struct Node *node = newNode(current);

  if (inStart == inEnd) {
    return node;
  }

  int inIndex = search(inorder, inStart, inEnd, current);

  node->left = buildTree(inorder, preorder, inStart, inIndex - 1, preIndex);
  node->right = buildTree(inorder, preorder, inIndex + 1, inEnd, preIndex);

  return node;
}

void printInorder(struct Node *node) {
  if (node == NULL) {
    return;
  }
  printInorder(node->left);
  printf("%d ", node->data);
  printInorder(node->right);
}

void printPostorder(struct Node *node) {
  if (node == NULL) {
    return;
  }
  printPostorder(node->left);
  printPostorder(node->right);
  printf("%d ", node->data);
}

int main() {
  int n;
  printf("Enter the number of nodes: ");
  scanf("%d", &n);

  int inorder[n], preorder[n];

  printf("Enter the in-order traversal: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &inorder[i]);
  }

  printf("Enter the pre-order traversal: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &preorder[i]);
  }

  int preIndex = 0;
  struct Node *root = buildTree(inorder, preorder, 0, n - 1, &preIndex);

  printf("Inorder traversal of the constructed tree is: ");
  printInorder(root);
  printf("\n");

  printf("Postorder traversal of the constructed tree is: ");
  printPostorder(root);
  printf("\n");

  return 0;
}
