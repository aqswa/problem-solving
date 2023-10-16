//
// Created by LG on 2023-03-08.
//
#include <iostream>
#include <vector>

using namespace  std;

int solve(vector<bool> bef, vector<bool> aft, int n){
    int cnt = 0;

    if(aft[0] != bef[0]){
        cnt++;
        bef[0] = !bef[0];
        bef[1] = !bef[1];
        if(aft[1] == bef[1]){
            if(aft[2] == bef[2]){
                bef[2] = !bef[2];
            }
        }
        else{
            if(aft[2] != bef[2]){
                bef[2] != bef[2];
            }
        }
    }

    for (int i = 1; i < n-2; i++) {
        if(bef[i] != aft[i]){
            cnt++;
            bef[i] = !bef[i];
            bef[i+1] = !bef[i+1];
            bef[i+2] = !bef[i+2];
        }
    }

    if(bef[n-2] != aft[n-2] && bef[n-1] != aft[n-1]){
        cnt++;
        return cnt;
    }
    else if(bef[n-2] == aft[n-2] && bef[n-2] == aft[n-2]){
        return cnt;
    }
    else { //011 101 010
        return -1;
    }

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

    cout << solve(bef, aft, n);
}
