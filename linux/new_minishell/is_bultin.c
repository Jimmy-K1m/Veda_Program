#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void cd_func(char** arg);

struct b_cmd{
    char *cmd;
    void (*func)(char**);
} builtin_cmd[] = {
    "cd", cd_func,
    NULL, NULL
};

int is_builtin(char** arg)
{
    for(int i=0; builtin_cmd[i].cmd!=NULL; i++) {
        if(strcmp(arg[0], builtin_cmd[i].cmd)==0) {
            builtin_cmd[i].func(arg);
            return 1;
        }
    }
    return 0;
}

void cd_func(char** arg)
{
    if(chdir(arg[1])==1) {
        perror("chdir");
        return;
    }
}