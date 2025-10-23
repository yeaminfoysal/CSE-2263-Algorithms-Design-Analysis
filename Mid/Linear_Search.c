#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {5, 8, 12, 20, 33, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the number want to find: ");
    scanf("%d", &target);

    int result = linearSearch(arr, size, target);

    if (result != -1) {
        printf("Found the number, Index: %d\n", result);
    } else {
        printf("Could not found the number.\n");
    }

    return 0;
}
