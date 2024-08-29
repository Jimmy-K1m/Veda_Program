#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    sigset_t sigmask;
    sigfillset(&sigmask);
    sigdelset(&sigmask, SIGINT);
    sigprocmask(SIG_BLOCK, &sigmask, NULL);

    for(int i = 0 ; i < 10; i++)
    {
        printf("sigpromask\n");
        sleep(1);
    }

    sigprocmask(SIG_UNBLOCK, &sigmask, NULL);
    for(;;);

return 0;
}