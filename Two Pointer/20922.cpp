//
// Created by LG on 2024-06-07.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> nums(N, 0);
    for(int i=0; i<N; i++) {
        cin >> nums[i];
    }

    vector<int> count(100001, 0);
    int s = 0, e = 0;
    int length = 0;
    while(e < N) {
        count[nums[e]]++;
        if(count[nums[e]] > K) {
            while(true) {
                count[nums[s]]--;
                if(nums[s++] == nums[e]) {
                    break;
                }
            }
        } else {
            if(e - s + 1 > length) {
                length = e - s + 1;
            }
        }
        e++;
    }

    cout << length;
}