#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 10

int total_philosophers;
int hungry_philosophers[MAX];
int hungry_count;

void eat(int p) {
    printf("P %d is granted to eat\n", p);
    sleep(1);  // Simulate eating
    printf("P %d has finished eating\n", p);
}

void one_can_eat() {
    for (int i = 0; i < hungry_count; i++) {
        for (int j = 0; j < hungry_count; j++) {
            printf("P %d is waiting\n", hungry_philosophers[j]);
        }
        eat(hungry_philosophers[i]);
    }
}

void two_can_eat() {
    int i = 0;
    while (i < hungry_count) {
        for (int j = 0; j < hungry_count; j++) {
            printf("P %d is waiting\n", hungry_philosophers[j]);
        }
        if (i + 1 < hungry_count) {
            printf("P %d is granted to eat\n", hungry_philosophers[i]);
            printf("P %d is granted to eat\n", hungry_philosophers[i + 1]);
            sleep(1);
            printf("P %d has finished eating\n", hungry_philosophers[i]);
            printf("P %d has finished eating\n", hungry_philosophers[i + 1]);
            i += 2;
        } else {
            eat(hungry_philosophers[i]);
            i++;
        }
    }
}

int main() {
    int choice;

    printf("Enter the total number of philosophers: ");
    scanf("%d", &total_philosophers);

    printf("How many are hungry: ");
    scanf("%d", &hungry_count);

    for (int i = 0; i < hungry_count; i++) {
        printf("Enter philosopher %d position (1 to %d): ", i + 1, total_philosophers);
        scanf("%d", &hungry_philosophers[i]);
    }

    do {
        printf("\n1. One can eat at a time\n2. Two can eat at a time\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Allow one philosopher to eat at any time\n");
                one_can_eat();
                break;
            case 2:
                printf("Allow two philosophers to eat at any time\n");
                two_can_eat();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}
