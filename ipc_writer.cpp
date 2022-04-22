#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

using namespace std;

int main() {
// ftok function is used to generate unique key
    key_t my_key = ftok("shmfile", 65);
// shmat to join to shared memory
    int shmid = shmget(my_key, 1024, 0666 | IPC_CREAT);
    char *str = (char *) shmat(shmid, (void *) 0, 0);
    cout << "Write Data : ";
    fgets(str, 50, stdin);
    printf("Data written in memory: %s\n", str);
//detach from shared memory
    shmdt(str);
    return 0;
}