/*----------------------------------------------
 * Author: 
 * Date: 
 * Description
 ---------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "read_ppm.h"

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("usage: decode <file.ppm>\n");
    return 0;
  }


  char *buff= argv[1];
  int w;
  int h;

  struct ppm_pixel** pixels = read_ppm_2d(buff, &w, &h);
  int chars = 0;

  if(w==0||h==0){
      printf("Problem opening file\n");
      return 1;
  }




//buffer
  int str[100];

  int index = 0;


  for(int i = 0; i<h; i++) 
  {

    for(int j = 0; j<w; j++)
    { 
     // printf("(%d,%d,%d) ",pixels[i][j].red,pixels[i][j].green,pixels[i][j].blue);
      unsigned int r =pixels[i][j].red;
      str[index]=r;
      index++;
      unsigned int g = pixels[i][j].green;
      str[index]=g;
      index++;
      unsigned int b = pixels[i][j].blue;
      str[index]=b;
      index++;
     // printf("%d%d%d", r,g,b);
      //printf("%02X\n", r);
    }
    //printf("\n");
  }
  str[index+1]='\0';

  chars=index/8;

  printf("Reading %s with width %d and height %d\n",buff,w,h);
  printf("Max number of characters in the image: %d\n",chars);
  printf("Message in binary:" );

 for(int i =0; i<index;i++){
  printf("%d",str[i]);

 }
 printf("\n");





  return 0;
}

