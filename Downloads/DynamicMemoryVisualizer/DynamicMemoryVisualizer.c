#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BLOCKS 10

// Structure to represent memory blocks
typedef struct {
    int size;
    bool is_allocated;
} MemoryBlock;

// Display the current memory status
void display_memory(MemoryBlock memory[], int num_blocks) {
    printf("\nMemory Status:\n");
    for (int i = 0; i < num_blocks; i++) {
        printf("Block %d: Size = %d, %s\n", i + 1, memory[i].size, memory[i].is_allocated ? "Allocated" : "Free");
    }
    printf("\n");
}

// First-Fit Memory Allocation
void first_fit(MemoryBlock memory[], int num_blocks, int process_size) {
    for (int i = 0; i < num_blocks; i++) {
        if (!memory[i].is_allocated && memory[i].size >= process_size) {
            printf("Process of size %d allocated in Block %d\n", process_size, i + 1);
            memory[i].is_allocated = true;
            return;
        }
    }
    printf("No suitable block found for process of size %d (First-Fit)\n", process_size);
}

// Best-Fit Memory Allocation
void best_fit(MemoryBlock memory[], int num_blocks, int process_size) {
    int best_index = -1;
    for (int i = 0; i < num_blocks; i++) {
        if (!memory[i].is_allocated && memory[i].size >= process_size) {
            if (best_index == -1 || memory[i].size < memory[best_index].size) {
                best_index = i;
            }
        }
    }
    if (best_index != -1) {
        printf("Process of size %d allocated in Block %d\n", process_size, best_index + 1);
        memory[best_index].is_allocated = true;
    } else {
        printf("No suitable block found for process of size %d (Best-Fit)\n", process_size);
    }
}

// Worst-Fit Memory Allocation
void worst_fit(MemoryBlock memory[], int num_blocks, int process_size) {
    int worst_index = -1;
    for (int i = 0; i < num_blocks; i++) {
        if (!memory[i].is_allocated && memory[i].size >= process_size) {
            if (worst_index == -1 || memory[i].size > memory[worst_index].size) {
                worst_index = i;
            }
        }
    }
    if (worst_index != -1) {
        printf("Process of size %d allocated in Block %d\n", process_size, worst_index + 1);
        memory[worst_index].is_allocated = true;
    } else {
        printf("No suitable block found for process of size %d (Worst-Fit)\n", process_size);
    }
}

int main() {
    int num_blocks, process_size, choice;

    printf("Enter the number of memory blocks (max %d): ", MAX_BLOCKS);
    scanf("%d", &num_blocks);

    if (num_blocks > MAX_BLOCKS || num_blocks <= 0) {
        printf("Invalid number of blocks!\n");
        return 1;
    }

    MemoryBlock memory[MAX_BLOCKS];

    for (int i = 0; i < num_blocks; i++) {
        printf("Enter size of Block %d: ", i + 1);
        scanf("%d", &memory[i].size);
        memory[i].is_allocated = false;
    }

    while (1) {
        printf("\n1. First-Fit\n2. Best-Fit\n3. Worst-Fit\n4. Display Memory\n5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter process size: ");
                scanf("%d", &process_size);
                first_fit(memory, num_blocks, process_size);
                break;

            case 2:
                printf("Enter process size: ");
                scanf("%d", &process_size);
                best_fit(memory, num_blocks, process_size);
                break;

            case 3:
                printf("Enter process size: ");
                scanf("%d", &process_size);
                worst_fit(memory, num_blocks, process_size);
                break;

            case 4:
                display_memory(memory, num_blocks);
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
