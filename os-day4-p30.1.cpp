1.	#include <stdio.h>
2.	#include <pthread.h>
3.	
4.	void *printMessage(void *message) {
5.	    char *msg = (char *)message;
6.	    printf("Thread Message: %s\n", msg);
7.	    pthread_exit(NULL);
8.	}
9.	
10.	int main() {
11.	    pthread_t thread;
12.	    char message[] = "Hello from the thread!";
13.	
14.	    // Create a thread
15.	    if (pthread_create(&thread, NULL, printMessage, (void *)message) != 0) {
16.	        fprintf(stderr, "Error creating thread\n");
17.	        return 1;
18.	    }
19.	
20.	    // Wait for the thread to finish
21.	    pthread_join(thread, NULL);
22.	
23.	    printf("Main thread exiting.\n");
24.	
    return 0;
}


