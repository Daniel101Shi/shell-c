#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char COMMAND[1024];

void echo(char* word){
  printf("%s\n", word);
}

void type(char* word){
  int found = 0;
  if(!strcmp(word, "echo") || !strcmp(word, "type") || !strcmp(word, "exit")){
    printf("%s is a shell builtin\n", word);
  } else{
    char combined_path[1024];
    if(getenv("PATH") != NULL){
      char* path_env = strdup(getenv("PATH"));
      char *dir = strtok(path_env, ":");

      while(dir!=NULL){
      snprintf(combined_path, sizeof(combined_path), "%s/%s", dir, word);
      if (access(combined_path, X_OK) == 0){
        found = 1;
        printf("%s is %s\n", word, combined_path);
        break;
      }
      dir = strtok(NULL, ":");
    }
    free(path_env);
  }
  if(!found){
    printf("%s: not found\n", word);
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


