#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

struct Song{
  int id;
  char title[32];
  char artist[32];
  int duration_min;
  int duration_sec;
  float danceability;

};

void printSongs(struct Song songList[]){

  for(int i = 0; i<3; i++){

    printf("%d)",songList[i].id);

    printf("%-30s   ",songList[i].title);
    printf("Artist: %-20s     ",songList[i].artist);
    printf("Duration: %d:%d     ",songList[i].duration_min,songList[i].duration_sec);
    printf("danceability: %f\n",songList[i].danceability);
  }
  printf("\n\n");

}


int main() {



  struct Song songA={0,"Coffee And a Question Mark","Taylor Bickett",2,42,0.4};
  struct Song songB={1,"Taste","Sabrina Carpenter",2,36,0.7};
  struct Song songC={2,"Ruin My Life","BLU EYES",3,39,0.6};

  struct Song songs[3];
  songs[0]=songA;
  songs[1]=songB;
  songs[2]=songC;


  printf("Welcome to the Grace Hollis song list\n\n"); 

  printSongs(songs);

  printf("Enter a song id to edit [0,1,2]"); 
  int id_num;
  scanf("%d",&id_num);
  //check for valid id number
  if(id_num<-1||id_num>2)
    {
      printf("Invalid ID number\n"); 

    }
  else{
      printf("Which attribute do you wish to edit? [artist, title, duration, danceability]: "); 
      char buff[32];
      scanf("%s",buff);

      char ti[20]="title";
      char ar[20]="artist";
      char dur[20]="duration";
      char dan[20]="danceablity";

        if(strcmp(ti,buff)==0){
          printf("Enter title: "); 
          scanf(" %[^\n]%*c", songs[id_num].title);



        }
        else if(strcmp(ar,buff)==0){
          printf("Enter artist: "); 
          scanf(" %[^\n]%*c", songs[id_num].artist);


        }
        else if(strcmp(dur,buff)==0){
          printf("Enter duration(minutes): "); 
          scanf(" %d%*c", &songs[id_num].duration_min);
          printf("Enter duration(seconds): "); 
          scanf(" %d%*c", &songs[id_num].duration_sec);


        }
        else if (strcmp(dan,buff)==0){
          printf("Enter danceablity:"); 
          scanf("%f%*c", &songs[id_num].danceability);
        }

      printSongs(songs);
  }

  return 0;
}
