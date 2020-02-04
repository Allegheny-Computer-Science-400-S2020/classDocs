// date: 30 Jan 2020

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/syscall.h>

void myTurn() {
  while(1){
    //sleep(1);
    printf("\n It is MY turn!");
  }
}

void yourTurn() {
  while(1){
    //sleep(1);
    printf("\n\t It is YOUR turn!");
  }
}


int main() {
  printf("Hello! This is main()");
  myTurn(); //call myTurn function
  yourTurn(); //call yourTurn function
}
