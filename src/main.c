#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char COMMAND[1024];

void echo(char* word){
  printf("%s\n", word);
}

void type(char* word){

  if(!strcmp(word, "echo") || !strcmp(word, "type") || !strcmp(word, "exit")){
    printf("%s is a shell builtin\n", word);
  } else if(access()){

  } else{
    char* path_env = strdup(getenv("PATH"));

    char* dir = strtok(path_env, ":");

    while(dir!=NULL){
    char* combined_path = strcat(dir, "/");
    char* combined_path = strcat(combined_path, word);
    if (access(combined_path, X_OK) == 0){
      printf("%s is %s", word, combined_path);
    }else{
      printf("%s: not found\n", word);
    }
  }
    
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


