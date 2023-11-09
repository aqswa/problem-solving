//
// Created by LG on 2023-11-09.
//
#include <iostream>
#include <vector>

using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector<int> dp(N+1, 0);
    dp[0] = 1;
    dp[1] = 3;
    for(int i=2; i<=N; i++){
        dp[i] = (dp[i-1] * 2 + dp[i-2])%9901;
    }

    cout << dp[N];
}
