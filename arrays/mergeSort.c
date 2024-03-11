#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(char* arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    char* L[n1];
    char* R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        int leftAge = atoi(strchr(L[i], ',') + 1);
        int rightAge = atoi(strchr(R[j], ',') + 1);
        if (leftAge <= rightAge) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

}

void mergeSort(char* arr[], int l, int r) {
    if (l < r) {
        // Find the middle point
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

void printArray(char* arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%s\n", arr[i]);
}

int main() {
    char* data[] = {
        "John,25,Male",
        "Alice,30,Female",
        "Bob,20,Male",
        "Eve,28,Female",
        "Charlie,35,Male"
    };

    int arr_size = sizeof(data) / sizeof(data[0]);

    printf("Given array is: \n");
    printArray(data, arr_size);

    mergeSort(data, 0, arr_size - 1);

    printf("\nSorted array is: \n");
    printArray(data, arr_size);
    return 0;
}
