#include<stdio.h>
#include<stdlib.h>

// Function to perform SCAN disk scheduling
void SCAN(int arr[], int head, int size, int direction) {
    int total_movement = 0;
    int current_position = head;
    int visited[size];

    for (int i = 0; i < size; i++) {
        visited[i] = 0;
    }

    printf("Sequence of disk movements:\n");

    while (1) {
        int next_position = -1;

        // Scan towards right
        if (direction == 1) {
            for (int i = current_position; i < size; i++) {
                if (!visited[i] && (next_position == -1 || abs(arr[i] - current_position) < abs(arr[next_position] - current_position))) {
                    next_position = i;
                }
            }

            if (next_position == -1) {
                direction = 0; // Change direction to left
                continue;
            }
        }

        // Scan towards left
        else {
            for (int i = current_position; i >= 0; i--) {
                if (!visited[i] && (next_position == -1 || abs(arr[i] - current_position) < abs(arr[next_position] - current_position))) {
                    next_position = i;
                }
            }

            if (next_position == -1) {
                direction = 1; // Change direction to right
                continue;
            }
        }

        // Print the movement
        printf("Move from %d to %d\n", current_position, arr[next_position]);

        // Update total movement and mark the position as visited
        total_movement += abs(arr[next_position] - current_position);
        visited[next_position] = 1;

        // Update current position
        current_position = arr[next_position];
    }

    printf("Total disk movement: %d\n", total_movement);
}

int main() {
    int size, head;

    printf("Enter the size of the disk queue: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the disk queue:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    int direction;

    printf("Enter the direction (1 for right, 0 for left): ");
    scanf("%d", &direction);

    SCAN(arr, head, size, direction);

    return 0;
}

