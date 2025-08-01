#include <stdio.h>

int main() {
    int n, i;
    int sum = 0;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of integers must be positive.\n");
        return 1;
    }

    int arr[n];

    printf("Enter %d integers:\n", n)
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    double average = (double)sum / n;
    printf("Average = %.2f\n", average);

    return 0;
}
