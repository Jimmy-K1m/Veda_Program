#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/msg.h>
#include <string.h>

int main()
{
    int msgid;
    struct msgbuf{
        long mtype;
        char mtext[1024];
    }mbuf;
    int n;
    msgid = msgget(ftok("/home/ubuntu",100), IPC_CREAT|0644); // 100은 키값

    if(msgid==-1)
    {
        perror("msgget");
        exit(1);
    }

    if(n=msgrcv(msgid, &mbuf, sizeof(mbuf), 1,0)<0)
    {
        printf("error\n");
        exit(1);
    }

    mbuf.mtext[n] = '\0';
    printf("%s\n", mbuf.mtext);
    msgctl(msgid, IPC_RMID, 0); // remove
    
    return 0;
}