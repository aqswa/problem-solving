//
// Created by LG on 2024-06-06.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    vector<vector<int>> dp(10001, vector<int>(4, 0));

    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    for(int i=4; i<10001; i++) {
        dp[i][1] = 1;
        dp[i][2] = dp[i-2][1] + dp[i-2][2];
        dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
    }

    for(int i=0; i<T; i++) {
        int n;
        cin >> n;
        cout << dp[n][1] + dp[n][2] + dp[n][3] << '\n';
    }


    /*
    vector<int> dp(10001, 1);

    for(int i=2; i<10001; i++) {
        dp[i] += dp[i-2];
    }

    for(int i=3; i<10001; i++) {
        dp[i] += dp[i-3];
    }

    for(int i=0; i<T; i++) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }

    */
}
