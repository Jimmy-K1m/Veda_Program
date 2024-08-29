#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int count = 0;

void int_handler(int signo)
{
    printf("int_handler\n");
    count = count+1;
}

int main()
{
    struct sigaction sigact, oldsigact, sigkill;
    sigact.sa_handler = SIG_IGN;
    sigfillset(&sigact.sa_mask);
    sigact.sa_flags = SA_RESTART;


    sigaction(SIGINT, int_handler, &oldsigact);
    sigkill.sa_handler = SIG_IGN; //&sigact, &oldsigact
    if (sigaction(SIGQUIT, &sigact, NULL) == -1) {
        perror("sigaction(SIGQUIT) failed");
        exit(EXIT_FAILURE);
    }
    sigaction(SIGKILL, &sigact, &oldsigact); //&sigact, &oldsigact

    for(;;){
        printf("signal test\n");
        sleep(1);
    }
}
