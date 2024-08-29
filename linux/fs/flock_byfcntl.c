#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int file_lock(int fd);
int file_unlock(int fd);

int main()
{
    int fd;
    int count = 0;
    if((fd=open("flock.txt", O_CREAT|O_RDWR , 0644)) == -1) // creat 함수는 파일이 없을 경우 파일 생성, rdwr은 읽기/쓰기 모두 가능
    {
        perror("open");
        exit(1);
    }
    //파일 lock 설정, lock을 설정하지 못하는 경우 -1 반환
    if(file_lock(fd) == -1)
    {
        perror("file_lock");
        exit(1);
    }
    int n;
    if((n= read(fd, &count, sizeof(count))) == -1)
    {
        perror("read");
        exit(1);
    }
    printf("count : %d\n", count);
    count++;
    write(fd, &count, sizeof(count));
    sleep(10);
    file_unlock(fd);
    close(fd);

    return 0;
}

int file_lock(int fd)
{
    struct flock lock;

    lock.l_type = F_WRLCK; // f_rdlck
    lock.l_whence = SEEK_SET; // 파일의 절대 위치
    lock.l_start = 0; // 파일 오프셋
    lock.l_len = 0; // 잠그려는 파일의 크기
    return fcntl(fd, F_SETLKW, &lock);

}

int file_unlock(int fd)
{
    struct flock lock;

    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    return fcntl(fd, F_SETLKW, &lock);

}