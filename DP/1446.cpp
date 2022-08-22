//
// Created by LG on 2022-08-16.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n, d;
    cin >> n >> d;

    int dp[d+1];
    for(int i=0; i<=d; i++)
        dp[i] = i;

    vector<vector<int>> path(n, vector<int>(3, 0));
    for(int i=0; i<n; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        if(e > d)
            continue;
        path[i][0] = s;
        path[i][1] = e;
        path[i][2] = w;
    }

    sort(path.begin(), path.end());

    for(int i=0; i<n; i++){
        int temp = dp[path[i][0]] + path[i][2];
        if(dp[path[i][1]] > temp)
            dp[path[i][1]] = temp;
        for(int j=path[i][1]; j<=d; j++){
            if(dp[j] > dp[j-1]+1)
                dp[j] = dp[j-1] + 1;
        }
    }

    cout << dp[d];
}
