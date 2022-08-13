//
// Created by LG on 2022-03-14.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> stairs(n, 0);
    for(int i=0; i<n; i++){
        cin >> stairs[i];
    }

    vector<int> dp(n, 0);
    dp[0] = stairs[0];
    dp[1] = stairs[0] + stairs[1];
    dp[2] = max(stairs[0], stairs[1]) + stairs[2];
    for(int i=3; i<n; i++){
        dp[i] = max(dp[i-3] + stairs[i-1], dp[i-2]) + stairs[i];
    }
    cout << dp[n-1];

}
