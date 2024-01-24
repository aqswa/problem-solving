//
// Created by LG on 2024-01-24.
//
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, d, k, c;
    cin >> N >> d >> k >> c; //접시 수, 초밥 가짓수, 연속해서 먹는 초밥 수, 쿠폰 번호

    vector<int> sushi(N, 0);
    for(int i=0; i<N; i++){
        cin >> sushi[i];
    }

    vector<int> visited(3001, -1);
    int ans = 1;
    visited[c] = 30001;
    for(int i=0; i<k; i++){
        int type = sushi[i];
        if(visited[type] < 0){ //처음 먹는 초밥 종류라면
            ans++;
        }
        visited[type]++; //초밥 횟수 늘림
    }

    int p1 = 0;
    int p2 = k % N;
    int cnt = ans;
    while(p1 != N-1){
        if(visited[sushi[p1]] == 0) {
            cnt--;
        }
        visited[sushi[p1]]--;

        if(visited[sushi[p2]] < 0){
            cnt++;
        }
        visited[sushi[p2]]++;

        if(cnt > ans){
            ans = cnt;
        }

        p1 = (p1 + 1) % N;
        p2 = (p2 + 1) % N;
    }

    cout << ans;

}
