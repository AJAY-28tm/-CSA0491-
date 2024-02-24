#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 10

void lruPageReplacement(int pages[], int n) {
    int frames[MAX_FRAMES];
    int pageTable[MAX_PAGES] = {0}; // To keep track of which pages are currently in frames
    int pageFaults = 0;
    int timeCounter = 1;

    for (int i = 0; i < n; i++) {
        int currentPage = pages[i];
        int pageFound = 0;

        // Check if the page is already in a frame
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == currentPage) {
                pageFound = 1;

                // Update page's access time
                pageTable[currentPage] = timeCounter++;
                break;
            }
        }
        if (!pageFound) {
            // Page fault
            pageFaults++;

            // Find the least recently used page in frames
            int lruIndex = 0;
            for (int j = 1; j < MAX_FRAMES; j++) {
                if (pageTable[frames[j]] < pageTable[frames[lruIndex]]) {
                    lruIndex = j;
                }
            }

            // Replace the least recently used page with the current page
            frames[lruIndex] = currentPage;

            // Update the page table
            pageTable[currentPage] = timeCounter++;
        }

        // Print the current state of frames
        printf("Page %d: ", currentPage);
        for (int j = 0; j < MAX_FRAMES; j++) {
            printf("[%d] ", frames[j]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[MAX_PAGES] = {0, 1, 2, 3, 0, 4, 1, 0, 2, 3};

    printf("LRU Page Replacement Simulation:\n\n");
    lruPageReplacement(pages, MAX_PAGES);

    return 0;
}

