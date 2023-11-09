//
// Created by LG on 2023-11-09.
//
#include <iostream>
#include <vector>

using namespace std;

int T, N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    while(T--){
        cin >> N;
        vector<vector<int>> stickers(2, vector<int>(N+1, 0)); //1부터 N열까지
        for(int i=0; i<2; i++){
            for(int j=1; j<=N; j++){
                cin >> stickers[i][j];
            }
        }

        vector<vector<int>> dp(2, vector<int>(N+1, 0));
        dp[0][1] = stickers[0][1];
        dp[1][1] = stickers[1][1];
        for(int i=2; i<=N; i++){
            dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + stickers[0][i];
            dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + stickers[1][i];
        }

        cout << max(dp[0][N], dp[1][N]) << '\n';
    }

}
