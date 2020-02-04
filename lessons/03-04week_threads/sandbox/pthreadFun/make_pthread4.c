// date: 30 Jan 2020
// CREATION OF THREADS

// ADD A JOIN FUNCTION TO ENSURE THE ALL THREADS COMPLETE



#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/syscall.h>

void *myTurn(void *arg) {
//  while(1){
  for (int i = 0; i < 8; i++){
    sleep(1);
    printf("\n %d It is MY turn!",i);
  }
}

void yourTurn() {
//  while(1){
  for (int i = 0; i < 3; i++){
    sleep(2);
    printf("\n\t %d It is YOUR turn!",i);
  }
}


int main() {
  printf("Hello! This is main()");
  pthread_t newThread; //thread id
  pthread_create(&newThread, NULL, myTurn, NULL);

//  myTurn(); //call myTurn function
  yourTurn(); //call yourTurn function
  pthread_join(newThread, NULL);
}
