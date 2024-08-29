#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
int fd = 3;
if(write(fd, "hello", 5) == -1)
{
    perror("write");
    exit(1);
}
close(fd);
return 0;

}