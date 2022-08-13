//
// Created by LG on 2022-04-03.
//
#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> order(n);
    for(int i=0; i<n; i++){
        cin >> order[i];
    }

    vector<int> dp(n, 1);
    int longest = 1;
    for(int i=1; i<n; i++){
        for(int j=i-1; j>=0; j--){
            if(order[j] < order[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        longest = max(dp[i], longest);
    }

    cout << n-longest;
}
