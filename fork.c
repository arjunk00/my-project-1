#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("I am child process, pid = %d\n", getpid());
        printf("My parent pid is %d\n", getppid());
    } else {
        printf("I am parent process, pid = %d\n", getpid());
    }
    return 0;
}