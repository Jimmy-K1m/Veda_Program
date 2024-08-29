#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);

    printf("tv_sec : %ld, tv_usec : %ld\n", tv.tv_sec, tv.tv_usec);

    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    printf("tv_sec : %ld, tv_usec : %ld\n", ts.tv_sec, ts.tv_nsec);

    //struct tm tm_;
    return 0;
}