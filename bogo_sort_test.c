#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Check if the array is sorted
bool is_sorted(int* a, int size) {
    for (int i = 1; i < size; i++) {
        if (a[i - 1] > a[i]) return false;
    }
    return true;
}

// Shuffle the array randomly
void shuffle(int* a, int size) {
    for (int i = 0; i < size; i++) {
        int r = rand() % size;
        int temp = a[i];
        a[i] = a[r];
        a[r] = temp;
    }
}

// Bogo sort function that returns number of shuffle operations
int bogo_sort(int* a, int size) {
    int operations = 0;
    while (!is_sorted(a, size)) {
        shuffle(a, size);
        operations++;
    }
    return operations;
}

int main() {
    int input[] = {3, 2, 1, 5, 4, 6, 9, 8, 7, 11, 10, 12};
    int size = sizeof(input) / sizeof(input[0]);

    srand(time(NULL)); // Seed for randomness

    printf("Unsorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", input[i]);
    }
    printf("\n");

    int operations = bogo_sort(input, size);

    printf("\nSorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", input[i]);
    }
    printf("\n");

    printf("Total shuffle operations: %d\n", operations);

    return 0;
}

