//
// Created by LG on 2023-12-07.
//
#include <vector>
#include <iostream>

using namespace std;

int N, K;
int cnt = 0;

void backtracking(int s, int cur, int sum, int goal, vector<int> array){ //다음 시작 인덱스, 현재 개수, 목표 개수, 배열
    if(cur == goal){
        if(sum == K){
            cnt++;
        }
        return;
    }

    for(int i=s; i<N; i++){
        if(sum + array[i] <= K) {
            sum += array[i];
            backtracking(i + 1, cur + 1, sum, goal, array);
            sum -= array[i];
        }
    }
}

int main(){
    int t;
    cin >> t;

    for(int i=1; i<=t; i++){
        cin >> N >> K;
        vector<int> array(N, 0);
        for(int j=0; j<N; j++){
            cin >> array[j];
        }

        int total = 0;
        bool flag = false;
        for(int j=1; j<=N; j++){
            cnt = 0;
            backtracking(0, 0, 0, j, array);
            if(cnt > 0){
                flag = true;
            }
            if(flag && cnt == 0){
                break;
            }
            total += cnt;
        }

        cout << "#" << i << ' ' << total << '\n';
    }
}
