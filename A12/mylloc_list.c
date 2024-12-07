#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


struct chunk {
  int size; // size of memory allocated from sbrk
  int used; // *NEW*: amount currently in use
  struct chunk *next;
};


struct chunk *flist = NULL;

void *malloc (size_t size) {
  // TODO: Implement malloc with a free list (See reading for details)

  if(size == 0 ){
    return NULL;
  }

  struct chunk *next = flist;
  struct chunk *prev = NULL;

  while(next!=NULL){
    if(next->size>=size)
    {
      next-> used = size;

      if(prev!=NULL)
      {
        prev->next = next ->next;
      }
      else
      {
       flist = next ->next; 
      }
      return (void*)(next+1);
    }
    else
    {
      prev = next;
      next = next ->next;
    }
  }

  void *memory = sbrk(size + sizeof(struct chunk));
  if(memory==(void*)-1)
  {
    return NULL;
  }
  else
  {
    struct chunk *cnk = (struct chunk*)memory;
    cnk->size=size;
    cnk->used=size;
    return (void*)(cnk+1);
  }
 

}




void free(void *memory) {
  // TODO: Implement malloc with a free list (See reading for details)

  if(memory!=NULL)
  {
    struct chunk *cnk = (struct chunk * )((struct chunk *)memory - 1);
    cnk -> next = flist;
    flist= cnk;
    flist->used = 0;
  }

  return;
}



