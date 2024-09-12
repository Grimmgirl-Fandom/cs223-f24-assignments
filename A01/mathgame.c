/***************************************************
 * mathgame.c
 * Author: 
 * Implements a math game
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <time.h>



int main() {
  printf("Welcome to Math Game!\n");
  printf("How many rounds do you want to play?\n"); 
  int rounds;
  scanf("%d", &rounds);
  int correct = 0;
    srand(time(NULL));

  for(int i = 0;i<rounds;i++){
    int answer;
    int a = rand()%(10);
    char a2[20];
    sprintf(a2, "%d", a);
    int b = rand()%(10);
    char b2[20];
    sprintf(b2, "%d", b);

    int sum= a+b;
    char clip1[100]= "+ ";
    char clip2[100]=" = ? ";
    strcat(a2,clip1);
    strcat(a2,b2);
    strcat(a2,clip2);



      printf("%s", a2);
      scanf("%d", &answer);


      if(answer==sum){
        printf("Correct!\n\n"); 
        correct=correct+1;
      }
      else{
        printf("Incorrect:(\n\n"); 
      }
  }


  char total[20];
  sprintf(total, "%d", rounds);

  char right[20];
  sprintf(right, "%d", correct);
  char slash[100] = "/";
  char end[100] = "You answered ";
  char end2[100]=" correctly.";
  strcat(end,right);
  strcat(end,slash);
  strcat(end,total);
  strcat(end,end2);
  printf("%s\n", end);
  return 0;
}
