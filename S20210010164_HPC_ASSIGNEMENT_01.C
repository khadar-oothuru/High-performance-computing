  
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int main() {
    const int arraySize = 1000000;
    int arr[arraySize];

    // Fill the array with random values
    srand(time(NULL));
    for (int i = 0; i < arraySize; ++i) {
        arr[i] = rand();
    }

    clock_t start = clock();

    mergeSort(arr, 0, arraySize - 1);

    clock_t end = clock();
    
    double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorting took %f seconds.\n", duration);

    return 0;
}

