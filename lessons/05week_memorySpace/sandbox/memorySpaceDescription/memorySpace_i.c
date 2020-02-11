// date 11 Feb. 2020
// Memory Space Description


# include <stdio.h>
# include <stdlib.h>


int global; // pointer memory to watch

int times_called() {
  static int counter = 0;
  counter ++;
  return counter;
}

int main() {
  int local = 5; // memory space to watch
  int c;
  void *p = malloc(128); //allocate memory to a pointer called 'p'
  printf("\t Address of main() is  : %p\n",main); //show where main() is stored in mem
  printf("\t Address of global is  : %p\n",&global); //show where global is stored in mem
  printf("\t Address of local is   : %p\n",&local); //show where local is stored in mem
  printf("\t Address of point p is : %p\n",p); //show where p is stored in mem
  c = times_called(); // init times_called() and static counter variable
  printf("\t Calling times_called() ... value of c : %d\n",c);

  times_called(); // run counter++
  times_called(); // run counter++
  times_called(); // run counter++
  printf("\t Calling times_called() ... value of c : %d\n",c); //nonupdated c

  c = times_called(); // update c on current counter value
  printf("\t Calling times_called() ... value of c : %d\n",c); // print current counter value


}
