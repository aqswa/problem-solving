//
// Created by LG on 2023-12-10.
//
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> score(n+1, 0);

    score[0] = 0;
    for(int i=1; i<=n; i++){
        cin >> score[i];
    }

    vector<vector<int>> gap(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; i++){
        int min = score[i];
        int max = score[i];
        gap[i][i] = 0;
        for(int j=i-1; j>=1; j--){
            if(score[j] > max){
                max = score[j];
            }
            if(score[j] < min){
                min = score[j];
            }
            gap[i][j] = max - min;
        }
    }

    vector<int> dp(n+1, 0);
    for(int i=2; i<=n; i++){
        for(int j=0; j<i; j++){
            dp[i] = max(dp[i], dp[j] + gap[i][j+1]);
        }
    }

    cout << dp[n];
}
