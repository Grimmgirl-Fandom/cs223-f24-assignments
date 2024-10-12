/*----------------------------------------------
 * Author: 
 * Date: 
 * Description
 ---------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read_ppm.h"
#include "write_ppm.h"

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("usage: encode <file.ppm>\n");
    return 0;
  }

  int w, h;
  char *buff= argv[1];

  struct ppm_pixel** pixels = read_ppm_2d(buff, &w, &h);

 FILE *infile= fopen(buff, "r");
  if (infile == NULL) 
  {
    exit(1);
  }


//buffer
  int str[100];
  int chars = 0;
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

  chars=(index-1)/8;

  printf("Reading %s with width %d and height %d\n",buff,w,h);
  printf("Max number of characters in the image: %d\n",chars);
  printf("Enter a phrase: ");
  char val[100];
  scanf("%s",val);


   // test writing the file to test.ppm
  write_ppm_2d("feep-raw-encoded.ppm",pixels,w,h);

   for(int i = 0; i<h; i++) 
  {
    free(pixels[i]);

  }

  free(pixels); 

  return 0;
}

