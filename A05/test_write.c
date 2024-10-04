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
  int w, h;
  struct ppm_pixel** pixels = read_ppm_2d("feep-raw.ppm", &w, &h);

 FILE *infile= fopen("test.ppm", "r");
  if (infile == NULL) 
  {
    exit(1);
  }

  // test writing the file to test.ppm
  write_ppm_2d("test.ppm",pixels,w,h);

   for(int i = 0; i<h; i++) 
  {
    free(pixels[i]);

  }

  free(pixels); 

//reload it
  struct ppm_pixel** pixels2 = read_ppm_2d("test.ppm", &w, &h);

// print the contents

  for(int i = 0; i<h; i++) 
  {

    for(int j = 0; j<w; j++)
    { 
      printf("(%d,%d,%d) ",pixels2[i][j].red,pixels2[i][j].green,pixels2[i][j].blue);
    }
    printf("\n");
  }


  //free


     for(int i = 0; i<h; i++) 
  {
    free(pixels2[i]);

  }

  free(pixels2); 
 fclose(infile);

  return 0;
}
