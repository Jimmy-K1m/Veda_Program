#include <stdio.h>
#include <spawn.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
int main()
{
	pid_t cpid;
	char buf[1024];
	int ret_err;
	char* argv_chld[] = {"a.out", NULL};
	posix_spawn_file_actions_t faction;
	if((ret_err=posix_spawn_file_actions_init(&faction))!=0) {  // fail
		strerror_r(ret_err, buf, sizeof(buf));
		fprintf(stderr, "file_actions_init fail :  %s\n", buf);
		exit(1);
	}
	if((ret_err= posix_spawn_file_actions_addopen(&faction, 3, "posix_spawn.log",
					O_WRONLY|O_CREAT|O_TRUNC,0644))!=0) {
		strerror_r(ret_err, buf, sizeof(buf));
		fprintf(stderr, "file_actions_addopen fail :  %s\n", buf);
		exit(1);
	}
 	posix_spawn(&cpid, argv_chld[0], &faction, NULL, argv_chld, NULL);
	if((ret_err=posix_spawn_file_actions_destroy(&faction))!=0) {
		strerror_r(ret_err, buf, sizeof(buf));
		fprintf(stderr, "posix_spawn_file_action_destroy: %s\n ", buf);
		exit(1);
	}
	printf("PID : %d , CPID : %d\n", getpid(), cpid);
	wait(NULL);
	printf("exit\n");
       	return 0;	
}