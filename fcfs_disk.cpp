#include <bits/stdc++.h>

using namespace std;
int sz = 8;

void FCFS(int arr[], int head) {
    int seek_count = 0;
    int distance, cur_track;
    for (int i = 0; i < sz; i++) {
        cur_track = arr[i];
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
    }
    cout << "Total number of seek operations = " <<
         seek_count << endl;
    cout << "Seek Sequence is" << endl;
    for (int i = 0; i < sz; i++) {
        cout << arr[i] << endl;
    }
}

int main() {
//request array
    int arr[sz] = {
            176,
            79,
            34,
            60,
            92,
            11,
            41,
            114
    };
    int head = 50;
    FCFS(arr, head);
    return 0;
}