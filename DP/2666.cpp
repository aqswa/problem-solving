//
// Created by LG on 2023-12-12.
//
#include <iostream>

using namespace std;

int N, K;
int dp[21][21][21]; //현재 열 벽장, 열린 벽장 a, 열린 벽장 b
int array[21];

//top-down 방식
int solve(int cur, int door1, int door2){
    if(cur > K){
        return 0;
    }

    int next = array[cur]; //다음으로 열릴 벽장
    dp[cur][door1][door2] = min(abs(door1 - next) + solve(cur+1, next, door2), abs(door2 - next) + solve(cur+1, door1, next));

    return dp[cur][door1][door2];
}


int main(){
    cin >> N;
    int a, b;
    cin >> a >> b;

    cin >> K;
    for(int i=1; i<=K; i++){
        cin >> array[i];
    }

    cout << solve(1, a, b);
}
