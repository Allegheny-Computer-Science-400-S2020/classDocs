// date 4 Feb 2020
// compile: gcc thread_raceCond.c -pthread

// DEFINES A RACE CONDITION BETWEEN THREADS


#include<stdio.h>
#include<pthread.h>
#define NUM_THREAD 10

void *threadFunc(void *pArg){
  // private variables to created threads
  int *p = (int*)pArg;
  int myNum = *p;

  printf("\t Thread Number :%d\n", myNum);
  return 0;
}


int main(void){
  int i; //index of my for loop
  pthread_t tid[NUM_THREAD];
  int tNum[NUM_THREAD]; // keep track of each created thread

  for (i = 0; i < NUM_THREAD; i++){
//    pthread_create(NEED_AN_ID,NULL,THREAD-MAKING-FUNCTION,INDEX_FROM_FOR_LOOP)
//    pthread_create(&tid[i],NULL,threadFunc,&i);
    pthread_create(&tid[i],NULL,threadFunc,&tNum[i]);
  }
  for (i = 0; i < NUM_THREAD; i++){
    //wait and a join command
//    pthread_join(THREAD_ID,NULL);
    pthread_join(tid[i],NULL);
  }
  return 0;
}
