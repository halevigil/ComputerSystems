#include <unistd.h> 
#include <sys/types.h> 
#include <errno.h> 
#include <stdio.h> 
#include <sys/wait.h> 
#include <stdlib.h> 
#include<time.h> 
pid_t pid;
void handle_sigint(int sig) 
{ 
  kill(pid, SIGKILL);
  printf("you didn't answer in time - game over \n" );
  exit(0);
} 
int main(int argc, char **argv)
{
  
  int numQs;
  printf("Enter number of questions:");
  scanf("%d", &numQs);
  pid = fork();
  if (pid == 0) {
    pid= execve("./Process6P1",NULL, NULL);
  }
  int num1;
  int num2;
  int answer;
  int operator_n;
  char * operator;
  int numCorrect;
  int i;
  int input;
  for (i=0;i<numQs;i++){
    signal(SIGINT, handle_sigint);
    num1 = rand() % 10;
    num2 = rand() % 10;
    operator_n = rand() % 3;
    if (operator_n==0){
      answer=num1+num2;
      operator="+";
    } else if (operator_n==1){
      answer=num1*num2;
      operator="*";
    } else if (operator_n==2){
      answer=num1-num2;
      operator="-";
    }
    printf("What is %d %s %d? \n", num1,operator, num2);
    scanf("%d",&input);
    if (input==answer){
      numCorrect++;
      printf("correct!\n");
    }
    else{
      printf("incorrect!\n");
    } 
    kill(pid, SIGINT);   
  }
  printf("Game over! You got %d correct and %d incorrect", numCorrect, numQs - numCorrect);
  kill(pid, SIGKILL);
//   kill(pid, SIGKILL);   
  }

  
