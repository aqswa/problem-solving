//
// Created by LG on 2024-06-02.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> score(N, 0);

    for(int i=0; i<N; i++) {
        cin >> score[i];
    }

    int total = 0;

    for(int i=N-2; i>=0; i--) {
        if(score[i] >= score[i+1]) {
            total += score[i] - score[i+1] + 1;
            score[i] = score[i+1] - 1;
        }
    }

    cout << total;
}
