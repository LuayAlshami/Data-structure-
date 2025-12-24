#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

void insertAfter(int key, int data) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Eleman bulunamadi!\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

void deleteNode(int key) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Silinecek eleman bulunamadi!\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;  

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

void traverseForward() {
    struct Node* temp = head;
    printf("Ileri: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void traverseBackward() {
    struct Node* temp = head;

    if (temp == NULL)
        return;

    while (temp->next != NULL)
        temp = temp->next;

    printf("Geri: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    insertAtBeginning(10);
    insertAtBeginning(5);
    insertAtBeginning(1);

    traverseForward();
    traverseBackward();

    insertAfter(5, 7);
    traverseForward();

    deleteNode(10);
    traverseForward();

    return 0;
}
