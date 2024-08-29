#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** command_parse(char *line) {
  	int argcount = 0;
  	char * token;
  	char **arglist;

  	if (line == NULL) {
    	return NULL;
  	}

  	if ((token=strtok(line," \t\n")) == NULL) {
    	return NULL;
  	}

  	arglist=(char **)malloc(sizeof(char *));

  	while (token != NULL) {
    	arglist[argcount++]=strdup(token);
    	token=strtok(NULL, " \t\n");
    	arglist=(char **)realloc(arglist, (argcount+1)*sizeof(char *));
  	}

  	arglist[argcount] = NULL;
  	return arglist;
}


void command_freelist(char **arglist) {

  int i;

  for (i = 0; arglist[i] != NULL; i++) {
    free(arglist[i]);
  }
  free(arglist);
}
