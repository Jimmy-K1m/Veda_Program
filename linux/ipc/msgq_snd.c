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

    msgid = msgget(ftok("/home/ubuntu",100), IPC_CREAT|0644);

    if(msgid==-1)
    {
        perror("msgget");
        exit(1);
    }

    mbuf.mtype = 1;
    strcpy(mbuf.mtext, "sender");
    msgsnd(msgid, &mbuf, strlen(mbuf.mtext), 0);
    //msgctl(msgid, IPC_RMID, 0);
    sleep(5);
    return 0;
}