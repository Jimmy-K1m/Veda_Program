#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int file_lock(int fd, int ix);
int file_unlock(int fd, int ix);

int main(int argc, char* argv[])
{
    int fd;
    int count = 0;
    if(fd=open("rlock.txt", O_CREAT|O_WRONLY , 0644) == -1) 
    {
        perror("open");
        exit(1);
    }
    // 파일 lock 설정, lock을 설정하지 못하는 경우 -1 반환

    char buf[16];
    for(int i = 0 ; i < 10; i++)
    {
        memset(buf, 0, 16);
        sprintf(buf, "%d", 0);
        write(fd, buf, 16);
    }
     if(file_lock(fd, atoi(argv[1])) == -1)
    {
        perror("file_lock");
        exit(1);
    }
    sleep(10);
    file_unlock(fd,atoi(argv[1]));
    close(fd);
    return 0;


}

int file_lock(int fd, int ix)
{
    struct flock lock;

    lock.l_type = F_WRLCK; // f_rdlck
    lock.l_whence = SEEK_SET; // 파일의 절대 위치
    lock.l_start = 16*ix; // 파일 오프셋
    lock.l_len = 16; // 잠그려는 파일의 크기
    return fcntl(fd, F_SETLKW, &lock);

}

int file_unlock(int fd, int ix)
{
    struct flock lock;

    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 16*ix;
    lock.l_len = 16;
    return fcntl(fd, F_SETLK, &lock);

}

/*
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
    
    if ((fd = open("flock.txt", O_CREAT | O_RDWR, 0644)) == -1) {
        perror("open");
        exit(1);
    }
    
    if (file_lock(fd) == -1) {
        perror("file_lock");
        exit(1);
    }
    
    int n;
    if ((n = read(fd, &count, sizeof(count))) == -1) {
        perror("read");
        exit(1);
    }

    if (n == 0) {
        count = 0;  // 파일이 비어 있으면 count를 0으로 초기화
    }

    printf("count : %d\n", count);
    count++;

    if (lseek(fd, 0, SEEK_SET) == -1) {  // 파일의 시작 위치로 이동
        perror("lseek");
        exit(1);
    }
    
    if (write(fd, &count, sizeof(count)) == -1) {
        perror("write");
        exit(1);
    }

    sleep(10);

    if (file_unlock(fd) == -1) {
        perror("file_unlock");
        exit(1);
    }

    close(fd);

    return 0;
}

int file_lock(int fd)
{
    struct flock lock;

    lock.l_type = F_WRLCK; // Write lock
    lock.l_whence = SEEK_SET; // Absolute file position
    lock.l_start = 0; // Offset from whence
    lock.l_len = 0; // Lock the whole file
    return fcntl(fd, F_SETLKW, &lock);
}

int file_unlock(int fd)
{
    struct flock lock;

    lock.l_type = F_UNLCK; // Unlock
    lock.l_whence = SEEK_SET; // Absolute file position
    lock.l_start = 0; // Offset from whence
    lock.l_len = 0; // Unlock the whole file
    return fcntl(fd, F_SETLKW, &lock);
}

*/