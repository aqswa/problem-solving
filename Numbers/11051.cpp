//
// Created by LG on 2023-01-16.
//
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<vector<int>> combination(1001, vector<int>(1001, 0));

    for(int i=0; i<1001; i++){
        for(int j=0; j<i+1; j++){
            if(j==0 || i==j)
                combination[i][j] = 1;
            else {
                combination[i][j] = combination[i - 1][j - 1] + combination[i - 1][j];
                combination[i][j] %= 10007;
            }
        }
    }

    cout << combination[n][k];
}
