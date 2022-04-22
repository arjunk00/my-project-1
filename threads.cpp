#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;
#define NUM_THREADS 5

void *print_hello(void *thread_id) {
    long tid;
    tid = (long) thread_id;
    cout << "Hello World! Thread ID, " << tid << endl;
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        cout << "main() : creating thread, " << i << endl;
        rc = pthread_create(&threads[i], NULL, print_hello, (void *) i);
        if (rc) {
            cout << "error, unable to create thread" << rc << endl;
        }
    }
}