/*----------------------------------------------
 * Author: 
 * Date: 
 * Description
 ---------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

struct songs
{
  char *title;
  char *artist;
  int duration;//ms
  float danceability;
  float energy;
  float tempo;
  float valence;
};

void printSongs(struct songs *songList,int size){

  for(int i = 0; i<size; i++){

    struct songs helper = songList[i];
    printf("%d) %s                 artist: %s \n",i+1,helper.title,helper.artist);
    printf("Duration: %d     danceablity: %f     energy: %f     tempo: %f    valence: %f",helper.duration,helper.danceability,helper.energy,helper.tempo,helper.valence);
    printf("\n\n");

  }
  printf("\n\n");

}


int main() {

  //number of songs
  int num = 0;


FILE *infile= fopen("songlist.csv", "r");
//infile = fopen("songlist.csv", "r");
if (infile == NULL) {
printf("Error: unable to open file %s\n", "songlist.csv");
exit(1);
}
else{

}


char line[128];
//have null after each token
//copy strings
fgets(line, 100, infile);

   const char s[2] = ",";
   char *number;
   
   number = strtok(line, s);
   num = atoi(number);
     while (number != NULL)
  {
   // printf ("%s\n",number);
    number = strtok (NULL,s);
  }

  //skipline
  fgets(line, 100, infile);


  

  struct songs *song_list;
  song_list = malloc(num * sizeof(struct songs)); 


  for (int i = 0; i<num;i++){
   
  
    fgets(line, 100, infile);//string

    char *token;


    token = strtok(line, s);
    char *a =token;
   
  token = strtok (NULL,s);

    // while (token != NULL)
  {
    //printf ("%s\n",token);
    //token = strtok (NULL,s);
  }


    token = strtok(line, s);
    char *b=token;
      token = strtok (NULL,s);

    //char *b = NULL;
    //strcpy(b, token);


    token = strtok(line, s);
    int c = atoi(token);
      token = strtok (NULL,s);



    token = strtok(line, s);
    float d=atof(token);
      token = strtok (NULL,s);

   


    token = strtok(line, s);
    float e=atof(token);
      token = strtok (NULL,s);

    


    token = strtok(line, s);
    float f=atof(token);
      token = strtok (NULL,s);



    token = strtok(line, s);
    float g=atof(token);
      token = strtok (NULL,s);



     struct songs holder={a,b,c,d,e,f,g};
    song_list[i]=holder;

    //printf("\n%s",holder.title);

  }

printSongs(song_list,num);


free(song_list);
fclose(infile);



  return 0;
}
