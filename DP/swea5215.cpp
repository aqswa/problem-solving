//
// Created by LG on 2023-11-19.
//
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int T;
    cin >> T;

    for(int t=1; t<=T; t++){
        int score[21];
        int cal[21];
        int dp[21][10001];

        int N, L; //재료 개수, 최대 칼로리
        cin >> N >> L;

        for(int i=1; i<=N; i++){
            cin >> score[i] >> cal[i];
        }

        for(int i=1; i<=N; i++){ //각 재료를 넣는 경우와 넣지 않는 경우를 고려
            for(int j=1; j<=L; j++){
                if(cal[i] <= j){ //현재 재료의 칼로리가 j칼로리보다 작은 경우에만 추가할 수 있음
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-cal[i]] + score[i]); //현재 재료 넣기 않고 j칼로리 최대 점수와, 현재 재료를 넣는 경우 중 더 큰 값
                }
                else{ //현재 재료의 칼로리가 j칼로리보다 큰 경우 추가 못함 -> 이전 재료까지의 최대 점수
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        cout << "#" << t << ' ' << dp[N][L] << '\n';
    }
}
