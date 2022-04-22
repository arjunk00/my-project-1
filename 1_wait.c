#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("I am child process, pid = %d\n", getpid());
        printf("My parent pid is %d\n", getppid());
    } else {
        wait(NULL);
        printf("I am parent process, pid = %d\n", getpid());
        printf("Because we used wait, it is guaranteed that "
               "the child process has terminated\n");
    }

    printf("This is common to child and parent\n");
    return 0;
}