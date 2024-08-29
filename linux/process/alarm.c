#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void alarm_handler(int signo)
{
    printf("alarm_handler\n");
    alarm(5);
}

int main()
{
    signal(SIGALRM, alarm_handler);
    alarm(5);
    for(;;);
}