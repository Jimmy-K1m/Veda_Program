#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    system("ls -l flock.txt");
    
    if(link("flock.txt", "hlink.txt") == -1)
    {
        perror("link");
        exit(1);
    }
    system("ls -l flock.txt hlink.txt");

    if(symlink("flock.txt", "slink.txt") == -1)
    {
        perror("symlink");
        exit(1);
    }

    system("ls -l flock.txt hlink.txt slink.txt");

    return 0;
}