#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int is_background(char ** arglist);
void run_command(char** arglist)
{
    pid_t cpid;

    int back_flag = 0;
	if(is_background(arglist))
		back_flag = 1;

    switch(cpid=fork()) {
        case -1:
        break;

        case 0: // 자식 프로세스
        execvp(arglist[0], arglist);
        perror("execvp");
        exit(1);
        break;

        default: // 부모프로세스
        if(back_flag == 0)
            waitpid(cpid, NULL, 0);
        break;
    }
 
}

int is_background(char ** arglist)
{
    int i;
    for(i =0; arglist[i]!= NULL; i++)
    {
        if(strcmp(arglist[i], "&") == 0){
            arglist[i] = NULL; // "&" 삭제
            return 1;
        }
        else 
            return 0;
    }
}

// sigchild 신호가 들어오면 
// sigaction 이 들어오면 