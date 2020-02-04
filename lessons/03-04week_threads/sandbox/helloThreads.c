#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS     5
//Compile on Linux: g++ -pthread helloWorldThread.c
// compile: gcc helloThreads.c -pthread


 void *PrintHello(void *threadid)
 {
    long tid;
    tid = (long)threadid;
    printf("\t\t * Cloned thread from number %ld!\n", tid);
    pthread_exit(NULL);
 }

 int main (int argc, char *argv[])
 {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    for(t=0; t<NUM_THREADS; t++){
       printf("\t In main: creating thread number %ld\n", t);
       rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
       if (rc){
          printf("ERROR; return code from pthread_create() is %d\n", rc);
          //exit(-1); //This line works on some systems when return doesn't work
          return 0;
       }
    }

    /* Last thing that main() should do */
    pthread_exit(NULL);
 }
