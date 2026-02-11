#include <stdio.h>
#include <stdlib.h>

char COMMAND[1024];

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);

  // TODO: Uncomment the code below to pass the first stage
  printf("$ ");
  fgets(COMMAND, sizeof(COMMAND), stdin);
  COMMAND[strcspn(COMMAND, '\n')] = '\0';

  printf("%s: command not found", COMMAND);
  
  return 0;
}
