#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main()
{
    int shmid, i,j ;
    char *shmaddr;
    struct sembuf sv_p = { 0, -1, SEM_UNDO};
    struct sembuf sv_v = { 0, 1, SEM_UNDO};
    int  semid;
    union semun
    {
        int val;
        struct semid_ds *buf;
        unsigned short int *array;
    } semctrl;


    if((shmid=shmget(0x123400, 21*30, 0660|IPC_CREAT|IPC_EXCL))==-1) {
        if((shmid=shmget(0x123400, 21*30, 0660))==-1){
            perror("shmget");
            exit(1);
        }
    }
    if((semid=semget((key_t)0x123401,1,0660|IPC_CREAT|IPC_EXCL))==-1) {
    	if((semid=semget((key_t)0x123401,1, 0))==-1){
    		perror("semget error ");
        	exit(1);
    	}
    } else {
        semctrl.val = 1;
        if (semctl( semid, 0, SETVAL, semctrl)==-1)
        {
               perror("semctl(SETVAL)");
               exit(1);
        }
    }

     if((shmaddr=shmat(shmid, (char *)0, 0))== NULL) {
        perror("shmat");
        exit(1);
     }
     for(i=0; i<20; i++) {
    	 sprintf(&shmaddr[i*30], "shared memory test %d", i+1);
    	 printf("send : %s\n", &shmaddr[i*30]);

     	if(semop(semid, &sv_v,1)==-1){
           perror("semop");
           exit(1);
		}
         for(j=0; j<300000000; j++);
     }
     sprintf(&shmaddr[i*30], "end");

     if(semop(semid, &sv_v,1)==-1){
           perror("semop");
           exit(1);
     }
     if(shmdt(shmaddr)==-1 ) {
        perror("shmdt");
        exit(1);
     }

     struct shmid_ds buf;
     while(1) {
     	if(shmctl(shmid, IPC_STAT, &buf)==-1) {
		if(errno==EINVAL)
			break;
		perror("shmctl");
		exit(1);
	}
     	if(buf.shm_nattch==0)
	     break;
	}
     	usleep(100);

     return 0;
}
