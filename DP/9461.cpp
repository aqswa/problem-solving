//
// Created by LG on 2022-08-14.
//
#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    long long dp[100];
    dp[0] = dp[1] = dp[2] = 1;
    dp[3] = dp[4] = 2;

    for(int i=5; i<100; i++)
        dp[i] = dp[i-1] + dp[i-5];

    while(t--){
        int n;
        cin >> n;
        cout << dp[n-1] << '\n';
    }
}
