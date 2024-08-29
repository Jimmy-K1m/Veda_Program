#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

static int g_var = 1;
char str[] = "PID";

int main()
{
    pid_t cpid;
    int status;
    cpid = fork();

    switch(cpid)
    {
        case -1:
        perror("fork"); // pid max 값, 메모리 부족 문제
        exit(1);
        break;
        case 0: // child 프로세스
        printf("pid : %d, ppid : %d \n", getpid(), getppid());
        sleep(8);
        exit(2);
        break;
        default: // parent 프로세스
        printf("cpid : %d , pid : %d\n", cpid, getpid());
         // wait 프로세스를 추가하여 zombie 프로세스를 없앤다. 
         while(waitpid(cpid, &status, 0) != cpid) // waitpid에 0 옵션을 쓰는 것은 wait랑 다를 게 없음 주로 WNOHANG을 사용함.
        {
            printf("parent process\n");
            sleep(1);
        }
        if(WIFEXITED(status))
        {
            printf("exit code : %d\n", WEXITSTATUS(status));
           
            WEXITSTATUS((status));
        }
        else if(WIFSIGNALED(status))
        {   
            printf("killed by signal\n");
        }
        //sleep(5);
        system("ps -l");
        break;
    }
}