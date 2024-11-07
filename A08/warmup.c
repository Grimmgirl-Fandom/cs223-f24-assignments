//Grace Swenson Hollis
//October 2024

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{

  //try with wait
  char c = 'A';
  
  int n = 0;

  printf("%d] %c%d\n",getpid(),c,n);//A0

  pid_t p;
  p=fork();


   if(p==0)
  {
    c++;
    n++;
    printf("%d] %c%d\n",getpid(),c,n);//B1
    printf("%d] Bye\n",getpid());
    c++;
    p=fork();
    if(p==0)
    {
      printf("%d] %c%d\n",getpid(),c,n);//C1
      printf("%d] Bye\n",getpid());
    }
  }
    else
    {
      c++;
      printf("%d] %c%d\n",getpid(),c,n);//B0
      p=fork();
      c++;
      if(p==0)
      {
        printf("%d] %c%d\n",getpid(),c,n);//C1
        printf("%d] Bye\n",getpid());
        }
    }
  
      

    return 0;
}
