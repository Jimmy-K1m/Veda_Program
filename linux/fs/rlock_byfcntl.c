#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int file_lock(int fd, int offset);
int file_unlock(int fd, int offset);

int main(int argc, char* argv[])
{
    int fd;
    char buf[16];

    int offset = atoi(argv[1])*16;


    if((fd=open("rlock.txt", O_RDWR))==-1){
        perror("open");
        exit(1);
    }
    // 파일 lock 을 설정, lock을 설정하지 못하는 경우 -1 반환
    if(file_lock(fd, offset)==-1) {
        perror("file_lock");
        exit(1);
    }

    int n;
    memset(buf, 0, 16);
    lseek(fd, offset, SEEK_SET);
    if((n=read(fd, buf, 16))==-1) {
        perror("read");
        exit(1);
    }

    printf("buf : %s\n", buf);

    lseek(fd, offset, SEEK_SET);
    sprintf(buf, "%d",atoi(buf)+1);
    write(fd, buf, 16);
    sleep(10);
    if(file_unlock(fd, offset)==-1) {
        perror("file_unlock");
        exit(1);
    }
    close(fd);

}

int file_lock(int fd, int offset)
{
    struct flock lock;

    lock.l_type=F_WRLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start=offset;
    lock.l_len=16;
    return fcntl(fd, F_SETLKW, &lock);
}

int file_unlock(int fd, int offset)
{
    struct flock lock;

    lock.l_type=F_UNLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start=offset;
    lock.l_len=16;
    return fcntl(fd, F_SETLK, &lock);
}