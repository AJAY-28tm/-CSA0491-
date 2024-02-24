#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 10

void fifoPageReplacement(int pages[], int n) {
    int frames[MAX_FRAMES];
    int frameIndex = 0;
    int pageFaults = 0;
    int pageTable[MAX_PAGES] = {0}; // To keep track of which pages are currently in frames

    for (int i = 0; i < n; i++) {
        int currentPage = pages[i];
        int pageFound = 0;

        // Check if the page is already in a frame
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == currentPage) {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound) {
            // Page fault
            pageFaults++;

            // Replace the oldest page in the frame (FIFO)
            int replacedPage = frames[frameIndex];
            frames[frameIndex] = currentPage;

            // Update the page table
            pageTable[replacedPage] = 0;
            pageTable[currentPage] = 1;

            frameIndex = (frameIndex + 1) % MAX_FRAMES;
        }

        // Print the current state of frames
        printf("Page %d: ", currentPage);
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == -1) {
                printf("[ ] ");
            } else {
                printf("[%d] ", frames[j]);
            }
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[MAX_PAGES] = {0, 1, 2, 3, 0, 4, 1, 0, 2, 3};

    printf("FIFO Page Replacement Simulation:\n\n");
    fifoPageReplacement(pages, MAX_PAGES);

    return 0;
}

