#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

using namespace std;

int main() {
//ftok function is used to generate unique key
    key_t my_key = ftok("shmfile", 65);
// shmget returns an ide in shmid
    int shmid = shmget(my_key, 1024, 0666 | IPC_CREAT);
// shmat to join to shared memory
    char *str = (char *) shmat(shmid, (void *) 0, 0);
    printf("Data read from memory: %s\n", str);
    shmdt(str);
    shmctl(shmid, IPC_RMID, NULL);
    return 0; // destroy the shared memory
}