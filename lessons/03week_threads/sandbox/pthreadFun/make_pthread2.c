// date: 30 Jan 2020
// CREATION OF THREADS

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/syscall.h>

void *myTurn(void *arg) {
  while(1){
    sleep(1);
    printf("\n It is MY turn!");
  }
}

void yourTurn() {
  while(1){
    sleep(3);
    printf("\n\t It is YOUR turn!");
  }
}


int main() {
  printf("Hello! This is main()");
  pthread_t newThread; //thread id
  pthread_create(&newThread, NULL, myTurn, NULL);

//  myTurn(); //call myTurn function
  yourTurn(); //call yourTurn function
}
