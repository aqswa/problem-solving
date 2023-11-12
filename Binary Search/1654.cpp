//
// Created by LG on 2023-11-11.
//
#include <iostream>
#include <vector>

using namespace  std;

int main() {
    int k, n; //갖고 있는 랜선 수, 필요한 랜선 수
    cin >> k >> n;

    vector<long long> lan_length(k, 0);

    long long max = 0;
    for(int i=0; i<k; i++){
        cin >> lan_length[i];
        if(lan_length[i] > max)
            max = lan_length[i];
    }

    long long left = 1;
    long long right = max;
    long long mid, ans = 0;
    while(left <= right){
        mid = (left + right) / 2;
        int cnt = 0;
        for(int i=0; i<k; i++){
            cnt += lan_length[i] / mid;
        }

        if(cnt >= n){
            left = mid + 1;
            ans = mid;
        }
        else{
            right = mid - 1;
        }
    }

    cout << ans;
}
