#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define NAME_POSIX_SHM  "/mytest"
#define SZ_SHM_SEGMENT  1024

int shm_fd;
char *shm_ptr;

int main()
{
	char input[256];

	printf("* SHM Name : %s\n", NAME_POSIX_SHM);
	if ((shm_fd=shm_open(NAME_POSIX_SHM, O_RDWR|O_CREAT|O_EXCL, 0660)) > 0) { 
		printf("* Create SHM\n"); 
		if (ftruncate(shm_fd, SZ_SHM_SEGMENT) == -1)  // set the file size
			exit(1);
	} else {
		if (errno != EEXIST) { // already exist shm 
			perror("shm_open"); 
			exit(1); 
		} 
		shm_fd = shm_open(NAME_POSIX_SHM, O_RDWR, 0); // open shared memory(file)
		if (shm_fd == -1) { 
			perror("shm_open()");
			exit(1); 
		}
	}

	shm_ptr = (char *)mmap(NULL, SZ_SHM_SEGMENT, PROT_READ|PROT_WRITE, MAP_SHARED, shm_fd, 0);		// memory attach
	if (shm_ptr == MAP_FAILED) { 
		perror("mmap");
		exit(1);
	}

	printf("'*' - 현재 공유 메모리 출력\n");
	printf("'.' - 종료.\n");
	printf("키보드입력 - 공유메모리로 문자 입력\n");

	while (1) {
		printf("\n>>");
		if (fgets(input, sizeof(input), stdin) == NULL) {
				break;
	 	}
		if (input[0] == '.') {
	  		break;
	 	} else if (input[0] == '*') {
			printf("shm -> '%.*s'\n", SZ_SHM_SEGMENT, shm_ptr);
	 	} else {
			input[strlen(input)-1]='\0';
	  		memcpy(shm_ptr, input, strlen(input));
	 	}
	}
	munmap(shm_ptr, SZ_SHM_SEGMENT);	// memory detach

	printf("* 공유메모리(%s) 삭제? (y/n)", NAME_POSIX_SHM);
	fgets(input, sizeof(input), stdin);
	if (input[0] == 'y') {
		shm_unlink(NAME_POSIX_SHM); // remove shm 
	}

	return 0;
}
	

