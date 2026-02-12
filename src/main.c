#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char COMMAND[1024];


int main(int argc, char *argv[]) {
  // flush after every printf
  setbuf(stdout, NULL);


  while(true){
    printf("$ ");
    fgets(COMMAND, sizeof(COMMAND), stdin);
    COMMAND[strcspn(COMMAND, "\n'")] = '\0';
    
    char* firstWord = strtok(COMMAND, " ");
    if(!strcmp(firstWord, "echo")){
      echo(strtok(NULL, "\0"));
    }



    if(!strcmp(COMMAND, "exit")){
      break;
    }
    printf("%s: command not found\n", COMMAND);
    

  }

  
  return 0;
}

void echo(char* word){
  printf(word);
}
