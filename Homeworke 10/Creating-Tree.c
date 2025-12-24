#include <stdio.h>

#define MAX 100

int tree[MAX];
int size = 0;

void insert(int value) {
    if (size >= MAX) {
        printf("Tree is full!\n");
        return;
    }
    tree[size++] = value;
}

void preorder(int index) {
    if (index >= size)
        return;

    printf("%d ", tree[index]);
    preorder(2 * index + 1);
    preorder(2 * index + 2);
}

void inorder(int index) {
    if (index >= size)
        return;

    inorder(2 * index + 1);
    printf("%d ", tree[index]);
    inorder(2 * index + 2);
}

void postorder(int index) {
    if (index >= size)
        return;

    postorder(2 * index + 1);
    postorder(2 * index + 2);
    printf("%d ", tree[index]);
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    printf("Preorder Traversal: ");
    preorder(0);

    printf("\nInorder Traversal: ");
    inorder(0);

    printf("\nPostorder Traversal: ");
    postorder(0);

    return 0;
}
