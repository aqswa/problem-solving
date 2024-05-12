//
// Created by LG on 2024-05-12.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, S; // 합이 S 이상인 연속된 수열 중에서 가장 짧은 수열의 길이 구하기
    cin >> N >> S;

    vector<int> nums(N, 0);

    for(int i=0; i<N; i++) {
        cin >> nums[i];
    }

    int e = 0;
    int sum = nums[0];
    int answer = N + 1;
    for(int i=0; i<N; i++) {
        if(e < i){
            break;
        }

        while(e < N-1 && sum < S) {
            sum += nums[++e];
        }

        if(sum < S) {
            break;
        }

        if(e - i + 1 < answer) {
            answer = e - i + 1;
        }

        sum -= nums[i];
    }

/*
    int arr[n + 1]; for(int i = 0; i < n; ++i) cin >> arr[i];
    int l = 0, r = 1, ans = INT_MAX, sum = arr[0];
    while(r <= n)
    {
        if(sum < s) {
            sum += arr[r++];
        }
        else {
            ans = min(ans, r - l);
            sum -= arr[l++];
        }
    }
*/

    if(answer == N + 1) {
        cout << 0;
    } else {
        cout << answer;
    }
}
