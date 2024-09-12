#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node *createBinaryTree() {
  struct Node *root = (struct Node *)malloc(sizeof(struct Node));
  printf("Enter data (-1 for no node):\n");
  scanf("%d", &root->data);
  if (root->data == -1) {
    free(root);
    return NULL;
  }

  printf("Enter left child of %d\n", root->data);
  root->left = createBinaryTree();

  printf("Enter right child of %d\n", root->data);
  root->right = createBinaryTree();

  return root;
}

void in_order(struct Node *root) {
  if (root == NULL) {
    return;
  }
  in_order(root->left);
  printf("%d ", root->data);
  in_order(root->right);
}

void pre_order(struct Node *root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->data);
  pre_order(root->left);
  pre_order(root->right);
}

void post_order(struct Node *root) {
  if (root == NULL) {
    return;
  }
  post_order(root->left);
  post_order(root->right);
  printf("%d ", root->data);
}

void showMenu() {
  printf("---------------------- MENU ---------------------\n");
  printf("1. Create Binary Tree\n");
  printf("2. Perform in-order traversal on Binary Tree\n");
  printf("3. Perform pre-order traversal on Binary Tree\n");
  printf("4. Perform post-order traversal on Binary Tree\n");
  printf("5. Exit\n");
}

void freeTree(struct Node *root) {
  if (root == NULL) {
    return;
  }
  freeTree(root->left);
  freeTree(root->right);
  free(root);
}

int main() {
  int choice;
  struct Node *root = NULL;
  while (1) {
    showMenu();
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      if (root != NULL) {
        printf("Tree already exists, please restart the program to create a "
               "new tree.\n");
      } else {
        root = createBinaryTree();
      }
      break;
    case 2:
      if (root == NULL) {
        printf("The tree is empty. Create the tree first.\n");
      } else {
        in_order(root);
        printf("\n");
      }
      break;
    case 3:
      if (root == NULL) {
        printf("The tree is empty. Create the tree first.\n");
      } else {
        pre_order(root);
        printf("\n");
      }
      break;
    case 4:
      if (root == NULL) {
        printf("The tree is empty. Create the tree first.\n");
      } else {
        post_order(root);
        printf("\n");
      }
      break;
    case 5:
      freeTree(root); // Free the memory before exiting
      printf("Exiting program.\n");
      exit(0);
    default:
      printf("Enter valid choice!\n");
    }
  }
  return 0;
}
