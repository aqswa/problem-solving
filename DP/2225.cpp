//
// Created by LG on 2024-05-19.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K; //0 ~ N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수

    vector<vector<int>> dp(K+1, vector<int>(N+1, 0));
    for(int i=0; i<=N; i++) {
        dp[1][i] = 1;
    }

    for(int i=0; i<=K; i++) {
        dp[i][0] = 1;
    }

    for(int i=1; i<=K; i++) {
        for(int j=1; j<=N; j++) {
            dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % 1000000000;
        }
    }

    cout << dp[K][N];
}
