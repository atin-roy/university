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

struct Node *insert(struct Node *node, int data) {
  if (node == NULL)
    return newNode(data);

  if (data < node->data)
    node->left = insert(node->left, data);
  else if (data > node->data)
    node->right = insert(node->right, data);

  return node;
}

struct Node *minValueNode(struct Node *node) {
  struct Node *current = node;

  while (current && current->left != NULL)
    current = current->left;

  return current;
}

struct Node *deleteNode(struct Node *root, int key) {
  if (root == NULL)
    return root;

  if (key < root->data)
    root->left = deleteNode(root->left, key);
  else if (key > root->data)
    root->right = deleteNode(root->right, key);
  else {
    if (root->left == NULL) {
      struct Node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct Node *temp = root->left;
      free(root);
      return temp;
    }

    struct Node *temp = minValueNode(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

struct Node *search(struct Node *root, int key) {
  if (root == NULL || root->data == key)
    return root;

  if (key < root->data)
    return search(root->left, key);

  return search(root->right, key);
}

struct Node *findPredecessor(struct Node *root, struct Node *node) {
  if (node->left != NULL) {
    struct Node *temp = node->left;
    while (temp->right != NULL)
      temp = temp->right;
    return temp;
  }

  struct Node *predecessor = NULL;
  while (root != NULL) {
    if (node->data > root->data) {
      predecessor = root;
      root = root->right;
    } else if (node->data < root->data)
      root = root->left;
    else
      break;
  }
  return predecessor;
}

struct Node *findSuccessor(struct Node *root, struct Node *node) {
  if (node->right != NULL) {
    struct Node *temp = node->right;
    while (temp->left != NULL)
      temp = temp->left;
    return temp;
  }

  struct Node *successor = NULL;
  while (root != NULL) {
    if (node->data < root->data) {
      successor = root;
      root = root->left;
    } else if (node->data > root->data)
      root = root->right;
    else
      break;
  }
  return successor;
}

void inorder(struct Node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

int main() {
  struct Node *root = NULL;
  int choice, key;
  while (1) {
    printf("\nMenu:\n");
    printf("1. Insert a key\n");
    printf("2. Search for a key\n");
    printf("3. Find predecessor and successor\n");
    printf("4. Delete a key\n");
    printf("5. Print inorder traversal\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter the key to insert: ");
      scanf("%d", &key);
      root = insert(root, key);
      break;
    case 2:
      printf("Enter the key to search: ");
      scanf("%d", &key);
      if (search(root, key))
        printf("Key %d found in the tree.\n", key);
      else
        printf("Key %d not found in the tree.\n", key);
      break;
    case 3:
      printf("Enter the key to find predecessor and successor: ");
      scanf("%d", &key);
      struct Node *node = search(root, key);
      if (node != NULL) {
        struct Node *predecessor = findPredecessor(root, node);
        struct Node *successor = findSuccessor(root, node);
        if (predecessor != NULL)
          printf("Predecessor of %d is %d\n", key, predecessor->data);
        else
          printf("No predecessor found for %d\n", key);
        if (successor != NULL)
          printf("Successor of %d is %d\n", key, successor->data);
        else
          printf("No successor found for %d\n", key);
      } else {
        printf("Key %d not found in the tree.\n", key);
      }
      break;
    case 4:
      printf("Enter the key to delete: ");
      scanf("%d", &key);
      root = deleteNode(root, key);
      break;
    case 5:
      printf("Inorder traversal of the tree: ");
      inorder(root);
      printf("\n");
      break;
    case 6:
      exit(0);
    default:
      printf("Invalid choice!\n");
    }
  }
  return 0;
}
