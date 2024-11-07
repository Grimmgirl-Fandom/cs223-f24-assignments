/*----------------------------------------------
 * Author: 
 * Date: 
 * Description
 * 
 * https://www.geeksforgeeks.org/deletion-in-linked-list/
 ---------------------------------------------*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

struct song
{
  char title[32];
  char artist[32];
  int duration;//ms
  float danceability;
  float energy;
  float tempo;
  float valence;

  struct song* next;

};

struct song *head = NULL;
struct song *current = NULL;
struct song *last = NULL;
struct song *body[5];







struct song* create(const char* ti,const char* ar,int dur,float d,float e, float t, float v, struct song* parent) {
  struct song* limb = malloc(sizeof(struct song));
  strncpy(limb->title, ti, 31);
  strncpy(limb->artist, ar, 31);
  limb->duration=dur;
  limb->danceability=d;
  limb->energy=e;
  limb->tempo=t;
  limb->valence=v;
  limb->next=parent;

  // A) Draw function stack here
  return limb;
}




 void traverseList(struct song* node)
 {

  int co =0;
    while (node != NULL) {
      co++;
          int min = node->duration/1000/60;
          int sec = node->duration/1000 - min*60;
          char se[3];
          if (sec<10)
          {
            se[0]='0';
            se[1]=sec+48;
            se[2]='\0';
          }
          else
          {
            se[0]=(sec/10)+48;
            se[1]=(sec%10)+48;
            se[2]='\0';
          }
          

        printf("\n\n%d)%s   %s   (%d:%ss) D:%f  E:%f  T:%f  V:%f \n",co,node->title,node->artist,min,se,node->danceability,node->energy,node->tempo,node->valence);

        printf("\n");

        node = node->next;
    }

    printf("\n");
}

struct song* mostDanceable(struct song* node)
 {
  struct song *most = NULL;
  float d = 0;

    while (node != NULL) {
        if(node->danceability>d){
          d=node->danceability;
          most = node;
        }
        node = node->next;
    }
    return most;
}

int mostDanceableSpot(struct song* node)
 {
  struct song *most = NULL;
  float d = 0;
  int spot = 0;
  int mostSpot=0;

    while (node != NULL) {
        if(node->danceability>d){
          d=node->danceability;
          most = node;
          mostSpot=spot;
        }
        node = node->next;
        spot++;
    }
    return mostSpot;
}
 

struct song* deleteNode(struct song* start, int position){
  
    struct song* prev;
    
    struct song* temp = start;

    // empty
    if (temp == NULL)
        return start;

    // head
    if (position == 1) {
        start = temp->next;
        return start;
    }

    // middle
    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
    }
    // If the given position is not present
    else {
        printf("Data not present\n");
    }

    return start;
}



void clear(int size)
{
  for(int i = 0; i<size;i++){
    
    if(body[i]!=NULL)
      {
        free(body[i]);
        body[i] = NULL;
      }
  }

}


int main() {


//number of REMAINING SONGS
int song_count = 0;

FILE *infile= fopen("songlist.csv", "r");
if (infile == NULL) {
  printf("Error: unable to open file %s\n", "songlist.csv");
  exit(1);
}
else
{


char line[128];
//have null after each token
//copy strings
//skip printing this line
fgets(line, 100, infile);
const char comma[2] = ",";
//char *token;




while(fgets(line, 100, infile))
{ 
  song_count++;

     // Returns first token
    char* token = strtok(line,comma);
 
    // Keep printing tokens while one of the
    // delimiters present in str[].
    char *holder[7];
    int spot = 0;

    while (token != NULL) {
       // printf(" %s\n", token);
       holder[spot]=token;
        token = strtok(NULL,comma);
        spot++;
    }
    if (song_count==1){
      head = create(holder[0],holder[1],atoi(holder[2]),atof(holder[3]),atof(holder[4]),atof(holder[5]),atof(holder[6]),NULL);
      current=head;
      body[song_count-1]=current;

    }
    else
    {
      current= create(holder[0],holder[1],atoi(holder[2]),atof(holder[3]),atof(holder[4]),atof(holder[5]),atof(holder[6]),last);
      body[song_count-1]=current;
    }
    last = current;

  
}


  fclose(infile);
}




printf("\n\nDataset contains %d songs\n\n",song_count);
traverseList(current);
printf("Press 'd' to show the most danceable song (any other key to quit):"); 
char key;
scanf(" %c",&key);
while(key=='d')
{
 
  
  if(song_count>0)
  {
      song_count--;
      struct song* dance = mostDanceable(current);

      printf("---------------------------------------------Most Danceable---------------------------------------------\n");

      int min = dance->duration/1000/60;
      int sec = dance->duration/1000 - min*60;
      char se[3];
      if (sec<10)
      {
        se[0]='0';
        se[1]=sec+48;
        se[2]='\0';
      }
      else
      {
        se[0]=(sec/10)+48;
        se[1]=(sec%10)+48;
        se[2]='\0';
      }
      printf("%s   %s   (%d:%ss) D:%f  E:%f  T:%f  V:%f \n",dance->title,dance->artist,min,se,dance->danceability,dance->energy,dance->tempo,dance->valence);
      printf("--------------------------------------------------------------------------------------------------------\n");
      //free(dance);
      deleteNode(mostDanceable(head),mostDanceableSpot(current));
  }
  printf("\n\nDataset contains %d songs\n\n",song_count);
  traverseList(current);
  
  printf("Press 'd' to show the most danceable song (any other key to quit):"); 
  scanf(" %c",&key);

}


clear(5);


  
  return 0;
}
