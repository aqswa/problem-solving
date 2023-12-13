//
// Created by LG on 2023-12-13.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[10001];

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> coins(n, 0);
    for(int i=0; i<n; i++){
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end());

    dp[0] = 1;
    for(int i=0; i<n; i++){
        int val = coins[i];
        for(int j=val; j<=k; j++){
            dp[j] += dp[j-val];
        }
    }

    cout << dp[k];

}
