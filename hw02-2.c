#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<math.h>

int sequence(int n);

int main(int argc,char *argv[]){
	int x,y,mparent;
	x= atoi(argv[1]);
	y= atoi(argv[2]);

	pid_t pid;
for(int i=0; i<x ; i++){
	pid=fork();
	mparent=getpid();

	if(pid < 0){
	fprintf(stderr,"Fork Failed");
	exit(-1);
	}

	else if(pid == 0){
	printf("This is a parent(PID %d)spawning a new child(PID %d)\n",mparent,getppid());
	printf("This is a child:%d PID:%d\n",i+1,getppid());
	printf("Sequence is:");

	for(int j=0;j<y;j++){
	printf("%d,",sequence(j));
	}
	printf("\n\n");
	}

	else{
	wait(NULL);
	exit(0);
	}
}

printf("Good Bye\n");

return 0;
}
 

int sequence(int n){
	if(n == 0 ){
	return 0;
	}
	else if(n==1 || n==2){
	return 1;
	}
	else if(n%3 == 0){
	return sequence(n-1)+sequence(n-2)+sequence(n-3);
	}
	else	
	return 2*sequence(n-1);
}
