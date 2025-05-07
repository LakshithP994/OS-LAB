#include <stdio.h>
#include <stdlib.h>

#define TOTAL_BLOCKS 100

int memory[TOTAL_BLOCKS]; // 0 - free, 1 - allocated

void allocateSequential(int fileId, int start, int length) {
    // Check if requested blocks are within bounds
    if (start < 0 || start + length > TOTAL_BLOCKS) {
        printf("Error: Requested blocks out of range.\n");
        return;
    }

    // Check if blocks are free
    for (int i = start; i < start + length; i++) {
        if (memory[i] == 1) {
            printf("Error: Block %d already allocated.\n", i);
            return;
        }
    }

    // Allocate blocks
    for (int i = start; i < start + length; i++) {
        memory[i] = 1;
    }

    printf("File %d allocated from block %d to %d.\n", fileId, start, start + length - 1);
}

int main() {
    int choice, fileId, start, length;

    while (1) {
        printf("\n1. Allocate File\n2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter File ID: ");
                scanf("%d", &fileId);
                printf("Enter starting block: ");
                scanf("%d", &start);
                printf("Enter number of blocks: ");
                scanf("%d", &length);
                allocateSequential(fileId, start, length);
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
