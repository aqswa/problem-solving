//
// Created by LG on 2024-05-11.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> nums(N, 0);

    for(int i=0; i<N; i++) {
        cin >> nums[i];
    }

    vector<bool> check(100001, false);
    long long cnt = 0;

    int e = 0;
    for(int i=0; i<N-1; i++){
        int cur = nums[i]; // 현재 시작 수
        check[cur] = true;
        if(e < i) {
            e = i;
        }
        while(true) {
            if(e < N-1 && !check[nums[e+1]]) {
                check[nums[e+1]] = true;
                e++;
            } else {
                break;
            }
        }
        cnt += e - i + 1;
        check[cur] = false;
    }

    cout << cnt + 1;

}
