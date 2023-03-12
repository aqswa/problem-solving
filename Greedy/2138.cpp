//
// Created by LG on 2023-03-08.
//
#include <iostream>
#include <vector>

using namespace  std;

int solve(string bef, string aft, int n){
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if(bef[i] != aft[i]){

        }
    }

    ans++;

    return ans;
}

int main(){
    int n;
    cin >> n;

    string before, after;
    cin >> before >> after;

    vector<bool> bef(n, 0);
    vector<bool> aft(n, 0);
    for(int i=0; i<n; i++){
        bef[i] = before[i];
        aft[i] = after[i];
    }

    cout << solve(before, after, n);
}
