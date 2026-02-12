#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char COMMAND[1024];

void echo(char* word){
  printf("%s\n", word);
}

void type(char* word){
  if(!strcmp(word, "echo") || !strcmp(word, "type") || !strcmp(word, "exit")){
    printf("%s is a shell builtin", word);
  } else{
    printf("%s: not found\n", word);
  }
}

int main(int argc, char *argv[]) {
  // flush after every printf
  setbuf(stdout, NULL);


  while(true){
    printf("$ ");
    fgets(COMMAND, sizeof(COMMAND), stdin);
    COMMAND[strcspn(COMMAND, "\n'")] = '\0';
    
    char* firstWord = strtok(COMMAND, " ");

    if(!strcmp(firstWord, "echo")){
      echo(strtok(NULL, ""));

    }else if(!strcmp(firstWord, "type")){
      type(strtok(NULL, ""));

    } else if(!strcmp(firstWord, "exit")){
      break;

    } else {
    printf("%s: command not found\n", COMMAND);
    }
    

  }
  return 0;
}


