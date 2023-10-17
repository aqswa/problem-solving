//
// Created by LG on 2023-10-17.
//
#include <iostream>
#include <vector>

using namespace std;

int N, M;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M; //수의 개수, 구해야 할 구간의 수
    vector<int> array(N+1, 0);

    for(int i=1; i<=N; i++){
        cin >> array[i];
    }

    vector<int> dp(N+1, 0);
    dp[1] = array[1];
    for(int i=2; i<=N; i++){
        dp[i] = dp[i-1] + array[i];
    }

    while(M--){
        int a, b;
        cin >> a >> b;
        cout << dp[b] - dp[a-1] << '\n';
    }
}
