//
// Created by LG on 2022-04-07.
//

#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<vector<vector<int>>> dp(71, vector<vector<int>>(71, vector<int>(71, 0))); //3차원 벡터

    //0~50: -50~0
    //51~70: 1~20
    for(int i=0; i<71; i++){
        for(int j=0; j<71; j++){
            for(int k=0; k<71; k++){
                if(i-50 <=0 || j-50 <=0 || k-50 <=0)
                    dp[i][j][k] = 1;
                else if(i < j && j < k)
                    dp[i][j][k] = dp[i][j][k-1] + dp[i][j-1][k-1] - dp[i][j-1][k];
                else
                    dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k] + dp[i-1][j][k-1] - dp[i-1][j-1][k-1];
            }
        }
    }

    while(true){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1)
            break;
        int ans = 0;
        if(a <=0 || b <= 0 || c <= 0)
            ans = 1;
        else if(a > 20 || b > 20 || c > 20)
            ans = dp[70][70][70];
        else
            ans = dp[a+50][b+50][c+50];
        cout << "w(" << a << ", " << b << ", " << c << ") = " << ans << '\n';
    }
}