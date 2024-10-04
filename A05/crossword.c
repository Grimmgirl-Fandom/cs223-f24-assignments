/*----------------------------------------------
 * Author: Grace Swenson Hollis
 * Date: October 10,2024
 * Description Crossword puzzle 
 ---------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

int sizeMe(char *str){
  int count = 0;
  while (str[count]!='\0')
  {
    count++;
  }
  
  return count;
}

void wordTime(int sa,int sb,int spotA,int spotB,char *wA,char *wB){

  //https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/ helped out with 2d array


    //make it
    char** crossword = (char**)malloc(sa * sizeof(char*));
    for (int i = 0; i < sa; i++)
    {
        crossword[i] = (char*)malloc(sb * sizeof(char));
    }

    //fill it
    int countA = 0;
    int countB = 0;
    for (int i = 0; i < sa; i++)
    {
      for (int j = 0; j < sb; j++)
      {
        if(i==spotA&&j==spotB)
        {
          crossword[i][j] = wB[countB]; 
          countA++;
          countB++;

        }
        else if(i==spotA)
        {
          crossword[i][j] = wB[countB]; 
          countB++;
        }
        else if(j==spotB)
        {
          
          crossword[i][j] = wA[countA]; 
          countA++;
        }
        else
        {
        crossword[i][j] = '.';
        }
      }
    }
    //print it
    for (int i = 0; i < sa; i++)
    {
        for (int j = 0; j < sb; j++){
          printf("%c ", crossword[i][j]);
        }
        printf("\n");
    }

//free it
    for (int i = 0; i < sa; i++)
    {
        free(crossword[i]);
    }

    free(crossword); 
}

int main(int argc, char *argv[]) {
   if (argc < 3) {
    printf("Usage: %s <word1> <word2>\n", argv[0]);
    exit(0);
  }

char *wordA=argv[1];
char *wordB=argv[2];

int sizeA=sizeMe(wordA);
int sizeB=sizeMe(wordB);


char sharedChar='\0';
int a = -1;
int b = -1;

for(int i = 0; i < sizeA; i++)
{
  for(int j = 0; j < sizeB; j++)
  {
    if(sharedChar=='\0')
    {
      if(wordA[i]==wordB[j])
      {
        sharedChar=wordA[i];
        a=i;
        b=j;
      }
    }
  }
}

if(sharedChar=='\0'){
  printf("No common letter!");
  exit(0);
}

if(sizeA>sizeB)
{
  wordTime( sizeA,sizeB,a,b,wordA,wordB);

}
else
{
    wordTime(sizeB,sizeA,b,a,wordB,wordA);
}


  return 0;
}
