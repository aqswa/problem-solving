//
// Created by LG on 2024-05-01.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> houses;
int answer = 0;

void binary_search(int start, int end) {
    if(start > end) {
        return;
    }

    int mid = (start + end) / 2;

    int cnt = 1;
    int prev = houses[0];

    for(int i=1; i<houses.size(); i++) {
        if(houses[i] - prev >= mid) {
            cnt++;
            prev = houses[i];
        }
    }

    if(cnt >= C) {
        answer = max(answer, mid);
        binary_search(mid+1, end);
    } else {
        binary_search(start, mid-1);
    }
}

int main() {
    cin >> N >> C;
    houses.assign(N, 0);

    for(int i=0; i<N; i++) {
        cin >> houses[i];
    }

    sort(houses.begin(), houses.end());

    int start = 1;
    int end = houses[N-1] - houses[0];

    binary_search(start, end);

    cout << answer;
}