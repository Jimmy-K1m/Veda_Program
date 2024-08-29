#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("Hello dup\n");
    int fd;
    fd = open("dup.txt", O_WRONLY|O_TRUNC|O_CREAT, 0644);
    if(fd == -1)
    {
        perror("open");
        exit(1);
    }
    close(1);
    dup(fd);

    printf("hello dup2\n");
    return 0;
}