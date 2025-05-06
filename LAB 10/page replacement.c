#include <stdio.h>

#define MAX 50

void printFrames(int frames[], int frameCount) {
    for (int i = 0; i < frameCount; i++) {
        if (frames[i] == -1)
            printf("- ");
        else
            printf("%d ", frames[i]);
    }
    printf("\n");
}

int isInFrame(int frames[], int frameCount, int page) {
    for (int i = 0; i < frameCount; i++) {
        if (frames[i] == page)
            return 1;
    }
    return 0;
}

void fifo(int pages[], int n, int frameCount) {
    int frames[frameCount], index = 0, faults = 0;

    for (int i = 0; i < frameCount; i++)
        frames[i] = -1;

    printf("\nFIFO Page Replacement Process:\n");
    for (int i = 0; i < n; i++) {
        if (!isInFrame(frames, frameCount, pages[i])) {
            frames[index] = pages[i];
            index = (index + 1) % frameCount;
            faults++;
            printf("PF No. %d: ", faults);
            printFrames(frames, frameCount);
        }
    }
    printf("FIFO Page Faults: %d\n", faults);
}

void lru(int pages[], int n, int frameCount) {
    int frames[frameCount], age[frameCount], faults = 0;

    for (int i = 0; i < frameCount; i++) {
        frames[i] = -1;
        age[i] = 0;
    }

    printf("\nLRU Page Replacement Process:\n");
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                age[j] = i;
                break;
            }
        }

        if (!found) {
            int lruIndex = 0;
            for (int j = 1; j < frameCount; j++) {
                if (age[j] < age[lruIndex])
                    lruIndex = j;
            }
            frames[lruIndex] = pages[i];
            age[lruIndex] = i;
            faults++;
            printf("PF No. %d: ", faults);
            printFrames(frames, frameCount);
        }
    }
    printf("LRU Page Faults: %d\n", faults);
}

void optimal(int pages[], int n, int frameCount) {
    int frames[frameCount], faults = 0;

    for (int i = 0; i < frameCount; i++)
        frames[i] = -1;

    printf("\nOptimal Page Replacement Process:\n");
    for (int i = 0; i < n; i++) {
        if (!isInFrame(frames, frameCount, pages[i])) {
            int replaceIndex = -1, farthest = i;

            for (int j = 0; j < frameCount; j++) {
                int k;
                for (k = i + 1; k < n; k++) {
                    if (frames[j] == pages[k])
                        break;
                }
                if (k > farthest) {
                    farthest = k;
                    replaceIndex = j;
                }
                if (k == n) {
                    replaceIndex = j;
                    break;
                }
            }

            if (replaceIndex == -1)
                replaceIndex = 0;

            frames[replaceIndex] = pages[i];
            faults++;
            printf("PF No. %d: ", faults);
            printFrames(frames, frameCount);
        }
    }
    printf("Optimal Page Faults: %d\n", faults);
}

int main() {
    int pages[MAX], n, frameCount;

    printf("Enter the number of Frames: ");
    scanf("%d", &frameCount);

    printf("Enter the length of reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    fifo(pages, n, frameCount);
    lru(pages, n, frameCount);
    optimal(pages, n, frameCount);

    return 0;
}
