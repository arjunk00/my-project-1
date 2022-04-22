#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void handle_sigint(int sig) {
    printf("\nSIGINT received\n");
    // can be used for graceful shutdown

    exit(0);
}

int main() {
    signal(SIGINT, handle_sigint); // triggered by Ctrl+C

    while (1) {
        printf("program running\n");
        sleep(1);
    }
    return 0;
}