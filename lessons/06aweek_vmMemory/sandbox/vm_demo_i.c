#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
  int a, i;
  if (fork()) sleep(1);
  a = getpid();
  for (i = 0; i < 4; i++) {
    printf("pid = %i: &getpid = %p, getpid = %i\n", getpid(), &a, a);
    sleep(2);
  }
  return 0;
}



// pid=23: &a=0x7ffff89d1b08, a=23
// pid=22: &a=0x7ffff89d1b08, a=22
// pid=23: &a=0x7ffff89d1b08, a=23
// pid=22: &a=0x7ffff89d1b08, a=22
// pid=23: &a=0x7ffff89d1b08, a=23
// pid=22: &a=0x7ffff89d1b08, a=22
// pid=23: &a=0x7ffff89d1b08, a=23
// pid=22: &a=0x7ffff89d1b08, a=22

// Explanation

//The memory seen by processes, therefore, is only virtual memory. This allows an OS to present a contiguous and isolated virtual memory space to each process, irrespective of what else is running on the machine—each process in effect thinks it has all the memory to itself.
