#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
	int shmid, j;
	char *shmaddr;
    int  semid;
    union semun
    {
        int val;
        struct semid_ds *buf;
        unsigned short int *array;
    } semctrl;
    struct sembuf sv_p={0, -1, SEM_UNDO};
    struct sembuf sv_v={0, 1, SEM_UNDO};

	if((shmid=shmget(0x123400, 30*21, 0660|IPC_CREAT|IPC_EXCL))==-1) {
		if((shmid=shmget(0x123400, 30*21, 0660))==-1){
			perror("shmget");
			exit(1);
		}
	}

	// semaphore 생성
    if((semid=semget((key_t)0x123401,1,0660|IPC_CREAT|IPC_EXCL))==-1) {
    	if((semid=semget((key_t)0x123401,1, 0))==-1){
    		perror("semget error ");
        	exit(1);
    	}
    } else {
        semctrl.val = 1;
        if (semctl( semid, 0, SETVAL, semctrl)==-1){ 
               perror("semctl(SETVAL)");
               exit(1);
        }
    }

 	if((shmaddr= shmat(shmid, (char *)0, 0))== NULL) {
		perror("shmat");
		exit(1);
	}
	int i =0;
 	while(1) {
		semop(semid, &sv_p, 1);
 		if(!strcmp(shmaddr+i*30,"end")) {
 			break;
		}
 		if(!strcmp(&shmaddr[i*30],""))
 			continue;
 		printf("recv : %s\n", &shmaddr[i*30]);
		for(j=0; j<99999999; j++);
		i++;
 	}

	if(shmdt(shmaddr) == -1 ) {
		perror("shmdt");
		exit(1);
	}
	if(shmctl(shmid, IPC_RMID, (struct shmid_ds *)0) == -1 ) {
		perror("shmctl");
		exit(1);
	}

	if(semctl(semid, IPC_RMID,  0) == -1 ) {
			perror("semctl");
			exit(1);
		}
	return 0;
}