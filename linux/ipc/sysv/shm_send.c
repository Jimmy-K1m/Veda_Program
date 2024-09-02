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
	int shmid, i,j ;
	char *shmaddr;

	if((shmid=shmget(0x123400, 30, 0660|IPC_CREAT|IPC_EXCL))==-1) {
		if((shmid=shmget(0x123400, 30, 0660))==-1){
			perror("shmget");
			exit(1);
		}
	}
 	if((shmaddr=shmat(shmid, (char *)0, 0))== NULL) {
		perror("shmat");
		exit(1);
	}
 	for(i=0; i<20; i++) {
 		sprintf(shmaddr, "shared memory test %d", i+1);
 		printf("send : %s\n", shmaddr);
 		for(j=0; j<500000000; j++); // delay 추가
 	}
 	sprintf(shmaddr, "end");

	if(shmdt(shmaddr)==-1 ) {
		perror("shmdt");
		exit(1);
	}

	return 0;
}

