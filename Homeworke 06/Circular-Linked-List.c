#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

void insertAfter(int key, int data) {
    if (head == NULL)
        return;

    struct Node* temp = head;
    do {
        if (temp->data == key) {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Eleman bulunamadi!\n");
}

void deleteNode(int key) {
    if (head == NULL)
        return;

    struct Node *curr = head, *prev = NULL;

    if (head->data == key && head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    if (head->data == key) {
        while (curr->next != head)
            curr = curr->next;

        curr->next = head->next;
        free(head);
        head = curr->next;
        return;
    }

    prev = head;
    curr = head->next;

    while (curr != head) {
        if (curr->data == key) {
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Silinecek eleman bulunamadi!\n");
}

void traverse() {
    if (head == NULL) {
        printf("Liste bos!\n");
        return;
    }

    struct Node* temp = head;
    printf("Liste: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    insertAtBeginning(10);
    insertAtBeginning(5);
    insertAtBeginning(1);

    traverse();

    insertAfter(5, 7);
    traverse();

    deleteNode(10);
    traverse();

    return 0;
}
