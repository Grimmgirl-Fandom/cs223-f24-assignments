/*----------------------------------------------
 * Author: 
 * Date: 
 * Description
 ---------------------------------------------*/
#include "write_ppm.h"
#include <stdio.h>
#include <string.h>

// implement *one* (but do not remove the other one)!

void write_ppm(const char* filename, struct ppm_pixel* pixels, int w, int h) {

}

void write_ppm_2d(const char* filename, struct ppm_pixel** pixels, int w, int h) {
    FILE *fptr;
    fptr = fopen(filename, "wb");

    if (fptr == NULL) 
    {
        printf("Error. File failed to open");
    }
    else
    {
        fprintf(fptr, "P6\n");
        fprintf(fptr,"# Created by GIMP version 2.10.24 PNM plug-in\n");
        fprintf(fptr, "4 4\n");
        fprintf(fptr, "255\n");


       // *prt;

        for(int i = 0; i<h; i++) 
            { 
            fwrite(pixels[i], sizeof(struct ppm_pixel), w, fptr);
            }

    }

    fclose(fptr);


}
