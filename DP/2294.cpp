//
// Created by LG on 2022-03-29.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 10001;

int main(){

    int n, k;
    cin >> n >> k;

    vector<int> c(n);
    for(int i=0; i<n; i++)
        cin >> c[i];

    sort(c.begin(), c.end());
    vector<int> dp(k+1, MAX);
    dp[0] = 0;
    for(int i=0; i<n; i++){
        for(int j=c[i]; j<=k; j++){
            dp[j] = min(dp[j], dp[j-c[i]]+1);
        }
    }

    if(dp[k] == MAX)
        cout << -1;
    else
        cout << dp[k];
}
