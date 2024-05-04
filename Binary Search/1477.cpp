//
// Created by LG on 2024-05-04.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, L; //현재 휴게소 수, 더 만들 휴게소 수, 도로 길이
vector<int> rests;
int answer = 1000;

void binary_search(int start, int end) {
    if(start > end) {
        return;
    }

    int mid = (start + end) / 2;

    int cnt = 0;
    for(int i=0; i<=N; i++) {
        int gap = rests[i+1] - rests[i] - 1;
        cnt += gap / mid;
    }

    if(cnt > M) {
        binary_search(mid+1, end);
    } else {
        answer = mid;
        binary_search(start, mid-1);
    }
}

int main() {
    cin >> N >> M >> L;
    rests.assign(N+2, 0);

    for(int i=1; i<=N; i++) {
        cin >> rests[i];
    }
    rests[0] = 0;
    rests[N+1] = L;

    sort(rests.begin(), rests.end());

    binary_search(1, L);

    cout << answer;
}

