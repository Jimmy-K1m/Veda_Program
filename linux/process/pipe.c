#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main()
{
    int pfd[2];
    if (pipe(pfd) == -1) {
        perror("pipe");
        exit(1);
    }

    printf("Read FD: %d, Write FD: %d\n", pfd[0], pfd[1]);

    switch (fork())
    {
    case -1:
        perror("fork");
        exit(1);

    case 0: // child
        close(pfd[0]); // Close unused read end
        dup2(pfd[1], 1); // Redirect stdout to pipe write end
        close(pfd[1]); // Close original write end after duplicating
        execlp("ps", "ps", NULL); // Replace child process with `ps`
        perror("execlp");
        exit(1);

    default: // parent
        close(pfd[1]); // Close unused write end
        dup2(pfd[0], 0); // Redirect stdin to pipe read end
        close(pfd[0]); // Close original read end after duplicating
        execlp("wc", "wc", "-l", NULL); // Replace parent process with `wc -l`
        perror("execlp");
        exit(1);
    }

    return 0;
}
