#include<stdio.h>

void sumdiagonal(int arr[3][3], int n, int m) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == j) {
                sum += arr[i][j];
            }
        }
    }
    printf("The sum of the diagonal elements = %d", sum);
}

int main() {
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = 3, m = 3;
    sumdiagonal(arr, n, m);
    return 0;
}
