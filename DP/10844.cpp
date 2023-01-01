#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<vector<int>> dp(101, vector<int>(10, 0));
    for(int i=0; i<10; i++)
        dp[1][i] = 1;  //i: 자릿수, j: i번 자리에 j가 들어갈 때 계단 수의 개수

    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            if(j > 0 && j < 9)
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
            else if(j==0)
                dp[i][j] = dp[i-1][1];
            else
                dp[i][j] = dp[i-1][8];
            dp[i][j] %= 1000000000;
        }
    }

    int ans = 0;
    for(int i=1; i<10; i++) {
        ans += dp[n][i];
        ans %= 1000000000;
    }

    if(n==1)  //1의 자리의 수인 경우, 맨 앞자리인 1의 자리에 0이 올 수 없으므로 dp[1][0]=0이어야하지만, 1의 자리가 아닌 경우에는 dp[1][0]=1이므로 예외 처리.
        cout << 9;
    else
        cout << ans;

}