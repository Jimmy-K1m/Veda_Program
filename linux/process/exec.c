#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int status;
    if(fork()==0)
    {
        char *arglist[] = {"sleep", "sleep", "5", NULL};
        printf("child start\n");
        execvp(arglist[0], &arglist[1]); // 코드를 교체하는 함수 다음 print문이 출력이 안 된다.

        printf("child end\n");
        exit(0); // 실행될 일이 없다.
    }
    else{
        wait(&status);
         if(WIFEXITED(status))
        {
            printf("exit code : %d\n", WEXITSTATUS(status));
            WEXITSTATUS(status);
        }
        else if(WIFSIGNALED(status))
        {   
            printf("killed by signal\n");
        }

    }

    
}