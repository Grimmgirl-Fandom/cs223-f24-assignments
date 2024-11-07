#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pwd.h>
#include <readline/readline.h>
#include <readline/history.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_underline "\u001b[4m"



int main() {
  pid_t p;
  int status;
  char* line;

  while(1) 
  {
    line = readline(ANSI_COLOR_MAGENTA "Graces Shell> "ANSI_COLOR_RESET);
    if (line == NULL || strcmp(line, "exit") == 0) 
    {
      printf(ANSI_COLOR_RED"Goodbye!\n"ANSI_COLOR_RESET);
      break;
    }

    add_history(line);
    p = fork();

    if (p == 0) 
    {
      char *args[100];
      int i = 0;
      args[i] = strtok(line, " ");
      
      while (args[i]!= NULL) 
      {
        i++;
	      args[i] = strtok(NULL, " ");
      }

      if (execvp(args[0], args) < 0) {
        printf(ANSI_COLOR_RED"%s not found\n"ANSI_COLOR_RESET, args[0]);
        exit(1);
      }
      } 
      else
      {
      waitpid(p, &status,0);
      }
      
    free(line);
  }
  return 0;
}
