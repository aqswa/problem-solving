//
// Created by LG on 2024-06-05.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> answer(N, 0);

    for(int i=1; i<=N; i++) {
        int num;
        cin >> num;
        int cnt = 0;
        for(int j=0; j<N; j++) {
            if(cnt == num) {
                while(answer[j] != 0) {
                    j++;
                }
                answer[j] = i;
                break;
            }
            if(answer[j] == 0) {
                cnt++;
            }
        }
    }

    for(int i=0; i<N; i++) {
        cout << answer[i] << ' ';
    }
}
