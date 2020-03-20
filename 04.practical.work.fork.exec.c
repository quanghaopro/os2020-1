#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
  int pid1=fork();
  if(pid1==0)
  {
  printf("I am child after fork()\n");
  char*args[]={"free","-h",NULL};
  execvp("free",args);
  }
  else
  {
  printf("Launching ps-ef\n");
  char*args[]={"/bin/ps","-ef",NULL};
  execvp("/bin/ps",args);
  wait(NULL);
  }
  return 0;
}
