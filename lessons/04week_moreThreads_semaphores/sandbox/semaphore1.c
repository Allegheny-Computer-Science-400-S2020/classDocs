// date: 6 Feb 2020
// Semaphore demo

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>



sem_t mutex; //mutually exclusive operations on threads

// function to create the threads

void* threadMaker(void* pArg){
  int *p = (int*)pArg;
  int myNum = *p;

  printf("\t I am thread number :%d\n", myNum);

  //wait(): reserve the resource
  sem_wait(&mutex);
  printf("\n\t Waiting: Resource has been reserved, thread %d queued ...\n",myNum);

  // critial section (i.e., memory resource)
  sleep(1);

  // signal(): release the resource back to the OS
  printf("\n\t Signal: Resource has been released back to the OS, thread %d completed.\n",myNum);
  sem_post(&mutex);

}



int main(){
  sem_init(&mutex, 0, 1); //Mutually exlusive operations only
  pthread_t t1, t2;
  int i = 0;
  int j = 1;

  // create first thread
  pthread_create(&t1, NULL, threadMaker, &i);
  sleep(2);

  // create second thread
  pthread_create(&t2, NULL, threadMaker, &j);

  pthread_join(t1,NULL);
  pthread_join(t2,NULL);

  sem_destroy(&mutex);
}
