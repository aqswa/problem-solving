//
// Created by LG on 2023-10-17.
//
#include <iostream>
#include <cstring>

using namespace std;

int T, W;

int main(){
    cin >> T >> W; //자두 떨어지는 초, 최대 이동 횟수

    int dp[T+1][W+1][2]; //초, 횟수, 위치
    memset(dp, -1, sizeof(dp));

    int s;
    cin >> s;

    if(s == 1){
        dp[1][0][0] = 1;
        dp[1][0][1] = 0;
    }
    else{
        dp[1][0][0] = 0;
        dp[1][0][1] = 0;
        dp[1][1][1] = 1;
    }

    for(int i=2; i<=T; i++){
        int pos = 0;
        cin >> pos;
        for(int j=0; j<=W; j++){
            for(int k=0; k<2; k++){
                if(pos == 1){ //자두가 1번 나무에서 떨어졌다면
                    dp[i][j][0] = max(dp[i-1][j][0] + 1, dp[i-1][j-1][1] + 1); //현재 1번 나무 아래 있는 경우
                    dp[i][j][1] = (dp[i-1][j-1][0], dp[i-1][j][1]); //현재 2번 나무 아래에 있는 경우
                }
                else{ //자두가 2번 나무에서 떨어졌다면
                    dp[i][j][0] = (dp[i-1][j][0], dp[i-1][j-1][1]); //현재 1번 나무 아래 있는 경우
                    dp[i][j][1] = max(dp[i-1][j-1][0] + 1, dp[i-1][j][1] +1); //현재 2번 나무 아래 있는 경우
                }
            }
        }
    }

    int max = 0;
    for(int i=1; i<=T; i++){
        for(int j=0; j<=W; j++){
            for(int k=0; k<2; k++){
                if(dp[i][j][k] > max)
                    max = dp[i][j][k];
            }
        }
    }

    cout << max;
}
