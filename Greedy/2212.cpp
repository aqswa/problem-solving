//
// Created by LG on 2023-03-12.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> sensor(n, 0);
    for(int i=0; i<n; i++){
        cin >> sensor[i];
    }

    sort(sensor.begin(), sensor.end());

    vector<int> interval(n-1, 0);
    for(int i=1; i<n; i++){
        interval[i-1] = sensor[i] - sensor[i-1];
    }

    sort(interval.begin(), interval.end());

    int ans = 0; //변수 초기화
    for(int i=0; i<n-k; i++){
        ans += interval[i];
    }

    cout << ans;
}
