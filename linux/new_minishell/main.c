#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "minishell.h"
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAXLINE 255

void handler(){
    //waitpid(...);
   while(waitpid(0, NULL, WNOHANG) == 0); // 0이면 자식 프로세스가 살아있다.
}


int main(void) {
    char line[MAXLINE];
    char **arglist;
    struct sigaction quit_child;

    quit_child.sa_handler =  handler;
    sigfillset(&quit_child.sa_mask); // blocking할 시그널 셋. 핸들러에 대한 보장 필요.
    quit_child.sa_flags = SA_RESTART|SA_RESETHAND; // 핸들러 동작을 다양하게 할 수 있음.
    
    sigaction(SIGCHLD, &quit_child, NULL); // handler를 갖고 있는 것은 부모프로세스
    fputs("minishell> ",stdout);


    while (fgets(line,MAXLINE,stdin)) {
        if(!strncmp(line,"exit",4))
            exit(0);

        arglist=command_parse(line);

        // for(int i=0; arglist[i]!=NULL; i++)
        //     printf("%s\n", arglist[i]);
        if(!is_builtin(arglist))
            run_command(arglist);
        command_freelist(arglist);
        fputs("minishell> ",stdout);
    }
    return 0;
}