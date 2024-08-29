#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char*argv[])
{
    int fd;

    if(argc!= 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(1);
    }


    if((fd=open(argv[1], O_RDONLY)) == -1){
        perror("open");
        exit(1);
    }

    fd=open("/etc/passwd", O_RDONLY);

    printf("fd: %d\n", fd);
    return 0;
}