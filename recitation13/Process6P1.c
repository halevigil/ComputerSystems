#include <unistd.h> 
#include <sys/types.h> 
#include <stdio.h> 
#include <sys/wait.h>
#include <stdlib.h> 
#include<signal.h> 
int secs=0;
int resets=0;
void handle_sigint(int sig) 
{ 
  secs = 0;
} 
int main(int argc, char **argv)
{
  signal(SIGINT, handle_sigint);
   printf("\n");
    while(secs<5) {
      printf("Time:%i\n",secs);
      fflush(0);
      sleep(1);
      secs++;
      printf("\r\b\r");
  }
  
  pid_t ppid;
  ppid = getppid();
  kill(ppid,SIGINT);

  return 0;
}
 
