//
// Created by LG on 2023-11-13.
//
#include <iostream>
#include <vector>

using namespace std;

int n;
int jump[100][100];

int main() {
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> jump[i][j];
        }
    }

    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    dp[0][0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int nr = i + jump[i][j];
            int nc = j + jump[i][j];

            if(i != n-1 && nr < n){
                dp[nr][j] += dp[i][j];
            }

            if(j != n-1 && nc < n){
                dp[i][nc] += dp[i][j];
            }
        }
    }

    cout << dp[n-1][n-1];

}
