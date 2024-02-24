#include <stdio.h>
#include <pthread.h>

void *printMessage(void *message) {
    char *msg = (char *)message;
    printf("Thread Message: %s\n", msg);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    char message[] = "Hello from the thread!";

    // Create two threads
    pthread_create(&thread1, NULL, printMessage, (void *)message);
    pthread_create(&thread2, NULL, printMessage, (void *)message);

    // Check if the threads are equal
    if (pthread_equal(thread1, thread2)) {
        printf("The threads are equal.\n");
    } else {
        printf("The threads are not equal.\n");
    }

    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Main thread exiting.\n");

    return 0;
}



