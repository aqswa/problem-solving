//
// Created by LG on 2023-12-07.
//
#include <vector>
#include <iostream>

using namespace std;

int N, K;
int cnt = 0;

void dfs(int s, int sum, vector<int> array){ //다음 시작 인덱스, 현재 개수, 목표 개수, 배열
    if(sum == K){
        cnt++;
        return;
    }

    for(int i=s+1; i<N; i++){
        if(sum + array[i] <= K) {
            dfs(i, sum + array[i], array);
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

        cnt = 0;
        for(int j=0; j<N; j++){
            dfs(j, array[j], array);
        }

        cout << "#" << i << ' ' << cnt << '\n';
    }
}
