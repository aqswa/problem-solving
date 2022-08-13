//
// Created by LG on 2022-04-08.
//
#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> dp(12, 0);
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    for(int i=1; i<=10; i++){
        for(int j=1; j<=3; j++){
            if(i+j < 12)
                dp[i+j] += dp[i];
        }
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
}
