/*----------------------------------------------
 * Author: Grace Swenson Hollis
 * Date: 
 * Description
 ---------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

///CODE WORKS BUT HAS ERRORS IN VALGRIND

int main() {

int speed = 0;
char buff[32];
 
printf("Pause Length:"); 
scanf("%d",&speed);
printf("\nText: "); 
scanf("%s",buff);
int len = 0;

while(buff[len]!='\0'){
  len++;
}
//printf("len %d\n",len);
//printf("speed %d\n",speed);


int new_size=len*speed+len+1;//+1 for /0?
//printf("new size %d\n",new_size);


//char new_str[new_size];
//malloc
char *new_str;
new_str = malloc(new_size * sizeof(char)); 
new_str[new_size-1]='\0';

//set the last one to terminating character
  if(new_str==NULL)
  {
    fprintf(stderr, "Memory allocation failed\n"); 
    return 1;
  }
    else{
    int spot = 0;
    //nested for loop to fill
    int count = 0;

    //for(int i= 0;i<new_size;i=i+speed)
    //{
      int i = 0;
      while(count<new_size-1)
      {

        new_str[count]=buff[spot];
         //printf("%d  %c\n",count,new_str[count]);

        count++;
        int j = 0;
       // for(int j = 0;j<speed;j++)
        //{
          while(j<speed)
          {
            if(count>=new_size){
              j=speed;
            }
            else{
              new_str[count]='.';
              //printf("%d  %c\n",count,new_str[count]);
              count++;
              j++;
            }
          }
        spot++;
        i=i+speed;
      }
    //printf("%d\n", count); 

    printf("%s", new_str); }


free(new_str);




  return 0;
}
