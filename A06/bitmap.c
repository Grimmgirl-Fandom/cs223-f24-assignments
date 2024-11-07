/*----------------------------------------------
 * Author: Grace Swenson Hollis
 * Date: 
 * reads in a single 64-bit unsigned integer (e.g. unsigned long) and outputs it as an 8x8 1bpp sprite.
 ---------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 



void printSprite(int grid[8][8]){

   for(int i =0; i<8; i++){
      for(int j = 0; j<8; j++){
        int ch = grid[i][j];
        if(ch==0){
          printf(" ");
        }
        else if(ch==1){
          printf(".");
        }

      }
      printf("\n");

    }

}

int main() {


  unsigned long img;
  scanf(" %lx", &img);
  printf("Image (unsigned long): %lx\n", img);

    int sprite[8][8];
    int bit = -1;
  
    for(int i =0; i<8; i++){

      for(int j = 0; j<8; j++)
      {
          int pos = 63 - (i * 8 + j);
	        unsigned long mask = 0x1ul << pos;
	        if (img & mask)
          {
            bit = 1;
	        }
	        else 
          {
            bit = 0;
	        }
          sprite[i][j]=bit;
	    }
      }
    printSprite(sprite);
  return 0;
}
