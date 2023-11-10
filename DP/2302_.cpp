//
// Created by LG on 2023-11-10.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> dp(41); //바꿀 수 없는 두 자리 사이 좌석의 수마다 좌석 배치의 가짓수
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=40; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    vector<int> seats(m+2);
    seats[0] = 0;
    seats[m+1] = n+1;
    for(int i=1; i<=m; i++){
        cin >> seats[i];
    }

    int answer = 1;
    for(int i=1; i<=m+1; i++){
        answer *= dp[seats[i] - seats[i-1] - 1];
    }

    cout << answer;
}
