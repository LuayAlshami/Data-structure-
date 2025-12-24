#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void insertMaxHeap(int value) {
    int i = size++;
    while (i > 0 && heap[(i - 1) / 2] < value) {
        heap[i] = heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap[i] = value;
}

int deleteMax() {
    int max = heap[0];
    int last = heap[--size];
    int i = 0, child;

    while (2 * i + 1 < size) {
        child = 2 * i + 1;
        if (child + 1 < size && heap[child + 1] > heap[child])
            child++;

        if (last >= heap[child])
            break;

        heap[i] = heap[child];
        i = child;
    }
    heap[i] = last;
    return max;
}

void printHeap() {
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    insertMaxHeap(10);
    insertMaxHeap(5);
    insertMaxHeap(20);
    insertMaxHeap(2);

    printHeap();
    printf("Max silindi: %d\n", deleteMax());
    printHeap();

    return 0;
}
