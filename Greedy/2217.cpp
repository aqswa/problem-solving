//
// Created by LG on 2023-12-14.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> ropes(n, 0);
    for(int i=0; i<n; i++){
        cin >> ropes[i];
    }

    sort(ropes.begin(), ropes.end());

    int answer =0;
    for(int i=0; i<n; i++){
        if(ropes[i] * (n-i) > answer){
            answer = ropes[i] * (n-i);
        }
    }

    cout << answer;
}
