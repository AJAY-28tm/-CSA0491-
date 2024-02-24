#include <stdio.h>
#include <pthread.h>

void *printMessage(void *message) {
    char *msg = (char *)message;
    printf("Thread Message: %s\n", msg);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    char message[] = "Hello from the thread!";

    // Create a thread
    if (pthread_create(&thread, NULL, printMessage, (void *)message) != 0) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    // Exit the main thread
    pthread_exit(NULL);

    // This line will not be reached
    printf("Main thread exiting.\n");

    return 0;
}



