#include<stdio.h>
#include<signal.h>
#include<unistd.h>
// compile: gcc -o signalHandler signalHandler.c

void sig_handler(int signalType)
{
    if (signalType == SIGUSR1) // first type of signal to handle
        printf("  received SIGUSR1\n");
    else if (signalType == SIGKILL) // second type of signal to handle
        printf("  received SIGKILL\n");
    else if (signalType == SIGSTOP)// third type of signal to handle
        printf("  received SIGSTOP\n");
}

int main(void)
{
    if (signal(SIGUSR1, sig_handler) == SIG_ERR)
        printf("\n  Cannot catch SIGUSR1\n"); // catch first type of signal
    if (signal(SIGKILL, sig_handler) == SIG_ERR)
        printf("\n  Cannot catch SIGKILL\n"); // catch second type of signal
    if (signal(SIGSTOP, sig_handler) == SIG_ERR)
        printf("\n  Cannot catch SIGSTOP\n"); // catch third type of signal

    // A long long wait so that we can easily issue a signal to this process
    while(1)
        sleep(1);
    return 0;
}
