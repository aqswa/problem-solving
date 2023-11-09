//
// Created by LG on 2023-11-09.
//
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> box_size(N, 0);
    for(int i=0; i<N; i++){
        cin >> box_size[i];
    }

    vector<int> dp(N, 1);
    int max = 1;
    for(int i=1; i<N; i++){
        for(int j=i-1; j>=0; j--){
            if(dp[j] + 1 > dp[i] && box_size[j] < box_size[i]){
                dp[i] = dp[j] + 1;
                if(dp[i] > max)
                    max = dp[i];
            }
        }
    }

    cout << max;
}
