#include <stdio.h>
#include <string.h>
#include <stdlib.h> 


int main() {


  char pick[4];
  pick[0]='@';
  pick[1]='!';
  pick[2]='#';
  pick[3]='*';
  char start[32]="OMG! ";

  printf("Enter a word: "); 
  char buff[32];
  scanf("%s",buff);
  char exc[32];


  int len = 0;
  
  while(buff[len]!='\0')
  {
    char holder;
    if((int)buff[len]>96&&(int)buff[len]<123){//if its lowercase
    //pick random character
      int spot =rand() % (3 -0 + 1)+0; //??
      holder = pick[spot];      
      exc[len]=holder;
    }
    else{//add it 
      exc[len]=buff[len];      
    }
    len++;
  }

  exc[len]='\0';

  //pring the string
  printf("%s",start);
  printf("%s\n",exc);


  return 0;
}



