#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

const int n;
const int ms;

int sequence(int n);
void delay(int ms);

int main(void)
{

  pid_t pid;
  int x, y;
  int i = 0;
  int p;
  int j = 0;
  int begin = time(NULL);

  fflush(stdin);
  printf("Input X and Y : ");
  scanf("%d %d", &x, &y);

  printf("x = %d, y = %d\n", x, y);

  int s[y];

  for (i = 0; i < x; i++)
  {
    pid = fork();
    p = getpid();

    if (pid < 0)
    {
      fprintf(stderr, "Fork Failed");
      exit(-1);
      fflush(stdin);
    }

    else if (pid == 0)
    {

      printf("This is a parent (PID %d) spawning a new ", p);
      printf("child PID : %d \n", getppid());
      printf("This is a child %d  PID : %d \n", i + 1, getppid());

      printf("Sequence is : ");

      for (j = 0; j < y; j++)
      {
        printf("%d, ", sequence(j));
        delay(100);
      }

      printf("\n");
    }

    else
    {
      wait(NULL);
      fflush(stdin);
      exit(0);
    }
  }

  printf("Good Bye");

  return 0;
}

int sequence(int n)
{
  if (n == 0)
    return 0;

  else if (n <= 2)
    return 1;

  else if (n % 3 == 0)
    return sequence(n - 1) + sequence(n - 2) + sequence(n - 3);

  return 2 * sequence(n - 1);
}

void delay(int ms)
{

  clock_t start, stop;

  int clock_per_second = CLOCKS_PER_SEC / 1000;

  start = clock();

  do
  {

    stop = clock();

  } while ((stop - start) / clock_per_second < ms);
}
