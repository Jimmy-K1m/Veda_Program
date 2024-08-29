#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s directoryname\n", argv[0]);
        exit(1);
    }
    struct stat fbuf;
    if(stat(argv[1], &fbuf) == -1)
    {
        perror("stat");
        exit(1);
    }


    DIR* dp;

    if(S_ISDIR(fbuf.st_mode))
    {
        printf("Directory\n");      //opendir
        if ((dp = opendir(argv[1])) == NULL)
        {
            perror("opendir");
            exit(1);
        }
        struct dirent* dirp;

        while(1){
            dirp = readdir(dp);
            if(dirp == NULL)
                break;
            printf("inode : %d, filename : %s\n", (int)dirp->d_ino, dirp->d_name);
        }
        closedir(dp);
    } 
    else if(S_ISREG(fbuf.st_mode))
    {
        printf("Regular File\n");   //open
    }


    return 0;
}