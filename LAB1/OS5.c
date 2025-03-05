#include<stdio.h>

void secondlargest(int arr[], int n) {
    if (n < 2) {
        printf("Not enough elements to find the second largest number.\n");
        return;
    }

    int largest = arr[0];
    int secondlargest = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            secondlargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondlargest && arr[i] != largest) {
            secondlargest = arr[i];
        }
    }

    if (secondlargest == largest) {
        printf("There is no second largest number.\n");
    } else {
        printf("The second largest number = %d\n", secondlargest);
    }
}

int main() {
    int arr[] = {5, 4, 6, 2, 1, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    secondlargest(arr, n);
    return 0;
}
