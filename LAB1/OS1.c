#include<stdio.h>

void secondsmallest(int arr[], int n) {
    if (n < 2) {
        printf("Not enough elements to find the second smallest number.\n");
        return;
    }

    int smallest = arr[0];
    int secondsmallest = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            secondsmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] < secondsmallest && arr[i] != smallest) {
            secondsmallest = arr[i];
        }
    }

    if (secondsmallest == smallest) {
        printf("There is no second smallest number.\n");
    } else {
        printf("The second smallest number = %d\n", secondsmallest);
    }
}

int main() {
    int arr[] = {5, 4, 6, 2, 1, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    secondsmallest(arr, n);
    return 0;
}
