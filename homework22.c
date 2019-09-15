#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



int main(void) {

 pid_t pid;

 int i = 0;
  
  
 pid = fork();

 printf("This is parent (PID %d) Spawning a new child (PID %d)",getpid(),getppid());

if (pid < 0)

{

  fprintf(stderr,"Fork Failed");
  exit(-1);

}

if(pid == 0)
{

printf(" CHILD PROCESS\n");

}


else if (pid > 0)
{

wait(NULL);

exit(0);

}

return 0;

}

