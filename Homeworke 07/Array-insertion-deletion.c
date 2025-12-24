#include <stdio.h>

#define MAX 100

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertAtPosition(int arr[], int *size, int pos, int value) {
    if (*size >= MAX) {
        printf("Dizi dolu!\n");
        return;
    }

    for (int i = *size; i > pos; i--)
        arr[i] = arr[i - 1];

    arr[pos] = value;
    (*size)++;
}

void deleteAtPosition(int arr[], int *size, int pos) {
    if (*size <= 0) {
        printf("Dizi bos!\n");
        return;
    }

    for (int i = pos; i < *size - 1; i++)
        arr[i] = arr[i + 1];

    (*size)--;
}

int main() {
    int arr[MAX] = {10, 20, 30, 40};
    int size = 4;

    printf("Baslangic: ");
    printArray(arr, size);

    insertAtPosition(arr, &size, 2, 25);
    printf("Eklemeden sonra: ");
    printArray(arr, size);

    deleteAtPosition(arr, &size, 1);
    printf("Silmeden sonra: ");
    printArray(arr, size);

    return 0;
}
