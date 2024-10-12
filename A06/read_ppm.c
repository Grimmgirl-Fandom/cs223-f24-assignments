/*----------------------------------------------
 * Author: 
 * Date: 
 * Description
 ---------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_ppm.h"

// Choose *one* to implement (do not remove the other one!)

struct ppm_pixel* read_ppm(const char* filename, int* w, int* h) {
  return NULL;
}



struct ppm_pixel** read_ppm_2d(const char* filename, int* w, int* h) {

  FILE *infile= fopen(filename, "r");
  if (infile == NULL) 
  {
    return NULL;
    exit(1);
  }

  char line1[4];
  fgets (line1, 4, infile);


/*
  char line[1000];
  fgets(line, 100, infile);//magic number
  fgets(line, 100, infile);//stuff
  fgets(line, 100, infile);//width and height

  int count = 0;
  char* token = strtok(ppm[2]," ");

   while (token != NULL) {
       if(count==0){
        *w = atoi(token);
       }
       else if(count==1){
         *h = atoi(token);
       }
        token = strtok(NULL," ");
        count++;
    }

   
 
  fgets(line, 100, infile);//stuff
  */

  char ppm[100];
  fgets (ppm, 100, infile); 
  int max;
  fscanf (infile, "%d %d\n%d\n", w, h, &max);

  struct ppm_pixel **pixels = malloc(sizeof(struct ppm_pixel *) * (*w * *h));
  if (pixels ==NULL) 
  {
    printf("Error! No space \n");
    return NULL;
  }

  for (int i = 0; i<*h; i++)
  {
    pixels[i] = malloc(sizeof(struct ppm_pixel) * *w);
  }

  for(int i = 0; i<*h; i++) 
  {
    for(int j = 0; j<*w; j++)
    {
      unsigned char ch = getc(infile);
      struct ppm_pixel Pix;
      Pix.red = ch;

      ch = fgetc(infile);
      Pix.green = ch;

      ch = fgetc(infile);

      Pix.blue = ch;

      pixels[i][j] = Pix;

    }
    

  }

  fclose(infile);
  return pixels;
}
