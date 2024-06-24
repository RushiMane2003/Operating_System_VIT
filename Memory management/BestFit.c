#include <stdio.h>

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocate[n]; // Initializing allocate list
    for (int i = 0; i < n; i++) {
        allocate[i] = -1;
    }

    // select the best memory block that can be allocated to a process
    for (int i = 0; i < n; i++) {
        int bestIndex = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIndex == -1) {
                    bestIndex = j;
                } else if (blockSize[bestIndex] > blockSize[j]) {
                    bestIndex = j;
                }
            }
        }
        if (bestIndex != -1) {
            allocate[i] = bestIndex;
            blockSize[bestIndex] -= processSize[i];
        }
    }

    // Display the processes with the blocks that are allocated to a respective process
    printf("\nFor Best Fit Algorithm\n");
    printf(" Process No\t Process Size \t Block Number\n");
    for (int i = 0; i < n; i++) {
        printf(" %d\t\t %d\t\t", i + 1, processSize[i]);
        if (allocate[i] != -1) {
            printf("%d\n", allocate[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int m, n;

    // get the number of blocks and processes
    printf("Enter the number of blocks: ");
    scanf("%d", &m);
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int blockSize[m], processSize[n];

    // get the size of each block
    printf("Enter the size of each block: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
    }

    // get the size of each process
    printf("Enter the size of each process: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }

    // Call the function
    bestFit(blockSize, m, processSize, n);

    return 0;
}
