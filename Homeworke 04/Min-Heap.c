#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void insertMinHeap(int value) {
    int i = size++;
    while (i > 0 && heap[(i - 1) / 2] > value) {
        heap[i] = heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap[i] = value;
}

int deleteMin() {
    int min = heap[0];
    int last = heap[--size];
    int i = 0, child;

    while (2 * i + 1 < size) {
        child = 2 * i + 1;
        if (child + 1 < size && heap[child + 1] < heap[child])
            child++;

        if (last <= heap[child])
            break;

        heap[i] = heap[child];
        i = child;
    }
    heap[i] = last;
    return min;
}

void printHeap() {
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    insertMinHeap(10);
    insertMinHeap(5);
    insertMinHeap(20);
    insertMinHeap(2);

    printHeap();
    printf("Min silindi: %d\n", deleteMin());
    printHeap();

    return 0;
}
