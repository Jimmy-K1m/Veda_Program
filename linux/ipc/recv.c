#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;

   

    while(1)
    {
         fd = open("mypipe", O_RDONLY);
        if(fd == -1)
        {
            perror("open");
            exit(1);
        }
        char buf[512];
        int size = read(fd,buf, sizeof(buf));
        buf[size] = '\0';
        if(buf == "end")
        {
            break;
        }
        printf("from send > %s\n", buf);
        close(fd);
    }
    

}