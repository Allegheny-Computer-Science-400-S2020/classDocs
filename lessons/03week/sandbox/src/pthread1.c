
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>


// compile: gcc  pthread1.c -pthread


// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *myThreadFun(void *vargp)
{
    sleep(1);
    printf("Making a thread \n");
    return NULL;
}

int main()
{
    pthread_t thread_id;
    printf("Before the thread\n");
    pthread_create(&thread_id, NULL, myThreadFun, NULL);
    pthread_join(thread_id, NULL);
    printf("After the thread\n");
    exit(0);
}
