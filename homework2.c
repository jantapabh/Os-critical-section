#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int value = 10; 

int main(void) {

  pid_t pid;

 

  pid = fork();

  if (pid < 0)
  {
  	fprintf(stderr,"Fork Failed");
  	exit(-1);
  }

  if (pid == 0)
  {
  	value +=25;
  	printf("CHILD : value = %d \n",value); 
  }

  else if (pid > 0) {
  
  wait(NULL);

  printf("PARENT : value = %d \n",value); 
  exit(0);

  }

  return 0;


}
