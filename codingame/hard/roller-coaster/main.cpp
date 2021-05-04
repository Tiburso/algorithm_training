#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int L;
    int C;
    int N;
    cin >> L >> C >> N; cin.ignore();

    vector<int> fifo(N);
    vector<int> gains(N, 0);
    vector<int> indexs(N);

    for (int i = 0; i < N; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        fifo[i] = Pi;
    }

    for (int i = 0; i < N; i++) {
        int currI = i;

        do {
            int next = fifo[currI];
            if (gains[i] + next > L) break;
            
            gains[i] += next;
            currI = (currI+1) % N;
        } while (currI != i);

        indexs[i] = currI;
    }

    long total = 0;
    int curr = 0; 
    for (int i = 0; i < C; i++) {
        total += gains[curr];
        curr = indexs[curr];
    }

    cout << total << endl;
}