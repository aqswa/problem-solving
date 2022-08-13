//
// Created by LG on 2022-04-02.
//
#include <iostream>
#include <vector>
using namespace std;

int main(){

    int x;
    cin >> x;

    vector<int> dp(x+1, x);
    dp[x] = 0;
    for(int i=x; i>0; i--){
        if(i%3 == 0)
            dp[i/3] = min(dp[i/3], dp[i]+1);
        if(i%2 == 0)
            dp[i/2] = min(dp[i/2], dp[i]+1);
        dp[i-1] = min(dp[i-1], dp[i]+1);
    }
    cout << dp[1];
}