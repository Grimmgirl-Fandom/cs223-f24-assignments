#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

//note only counts if each word starts with a capital letter and no random letters are capital

int wordCount(char stuff[]){
  int count = 0;
  int len = 0;
  
  while(stuff[len]!='\0')
  {
    if((int)stuff[len]>64&&(int)stuff[len]<91)
    {
      count++;
    }
    len++;
  }

  return count;
}



int main() {


  printf("\nEnter a phrase: "); 
  char phrase[1024];
  scanf("%[^\n]%*c", phrase);

  int siz= wordCount(phrase);
  char acr[1024];
  int spot = 0;
  //fill it
  int i = 0;
  acr[siz]='\0';
  while(spot<siz){
    if((int)phrase[i]>64&&(int)phrase[i]<91){
      acr[spot]=phrase[i];
      spot++;
      }
    i++;
  }

  printf("\n Your acronym is: "); 
  printf("%s\n",acr);


  return 0;

}
