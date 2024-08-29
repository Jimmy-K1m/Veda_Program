#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
        int pid;
         pid = fork();
        printf("pid = [%d] \n", pid);
        if(pid < 0){
                printf("fork Error... : return is [%d] \n", pid );
                perror("fork error : ");
                exit(0);
        }else if (pid > 0){
                printf("child process : [%d] - parent process : [%d] \n", pid, getpid());
                exit(0);
        }else if(pid == 0){
                printf("process : [%d]\n", getpid());
        }
        signal(SIGHUP, SIG_IGN);
        //close(0);
        //close(1);
        //close(2);
        chdir("/"); //최상위 루트 폴더로
        setsid(); // 프로세스가 세션 리더가 되게 하는
        open("/dev/null", O_RDWR);
        int cnt = 0;
        while(1) {
                printf("cnt = %d\n", cnt++);
                sleep(5);
        }
}