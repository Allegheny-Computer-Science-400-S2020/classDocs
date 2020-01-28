#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <sys/types.h>


// we will create a global variable and apply it to make a thread
//
// compile: gcc pthread2.c -lpthread

int g = 0;

// The function to be executed by all threads
void *myThreadFunc(void *vargp)
{
    // Store the value argument passed to this thread
    int *myid = (int *)vargp;

    // Let us create a static variable to observe its changes
    static int s = 0;

    // Change static and global variables
    ++s; ++g;

    // Print the argument, static and global variables
    printf("Thread ID: %d, Static: %d, Global: %d\n", *myid, ++s, ++g);
}

int main()
{
    int i;
    pthread_t tid;

    // we create three threads
    for (i = 0; i < 3; i++)
        pthread_create(&tid, NULL, myThreadFunc, (void *)&tid);

    pthread_exit(NULL);
    return 0;
}
