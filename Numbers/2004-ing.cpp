//
// Created by LG on 2023-01-20.
//
#include <iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    long long combination[n+1][n+1];
    combination[0][0] = combination[1][0] = combination[1][1] = 1;
    for(int i=2; i<=n; i++){
        for(int j=0; j<=i; j++){
            if(j==0 || j==i)
                combination[i][j] = 1;
            else
                combination[i][j] = combination[i - 1][j - 1] + combination[i - 1][j];
        }
    }

    /**
    long long num = 0;
    if(n/m >= 2)
        num = combination[n][m];
    else
        num = combination[n][n-m];
     */
    long long num = combination[n][m];
    int five = 0;
    while(num%5 == 0){
        five++;
        num /= 5;
    }
    cout << five;
}


