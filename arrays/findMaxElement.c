#include <stdio.h>

int find_maximum(int arr[], int size) {
    int max_element = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
    }

    return max_element;
}

int main() {
    int arr[] = {5, 3, 9, 1, 7, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    int max = find_maximum(arr, size);
    printf("Maximum element in the array: %d\n", max);

    return 0;
}

