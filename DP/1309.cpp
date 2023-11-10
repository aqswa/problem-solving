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
        dp[i] = (dp[i-1] * 2 + dp[i-2])%9901; //dp[i] = dp[i - 2] * 3 + (dp[i - 1] - dp[i - 2]) * 2
                                            //전전 칸 * (왼, 오, 없는 경우 3가지) + (직전 행 - 직전 행 빈 경우) * (있거나, 없거나 2가지)
    }

    cout << dp[N];
}
