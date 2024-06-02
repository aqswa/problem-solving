//
// Created by LG on 2024-06-02.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int> p1, const pair<int, int> p2) {
    if(p1.first == p2.first) {
        return p1.second < p2.second;
    }
    return p1.first < p2.first;
}

int main() {
    int N;
    cin >> N;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int, int>> lines(N, {0, 0});

    for(int i=0; i<N; i++) {
        cin >> lines[i].first >> lines[i].second;
    }

    sort(lines.begin(), lines.end(), compare);

    int start = lines[0].first;
    int end = lines[0].second;
    int total = end - start;
    for(int i=1; i<N; i++) {
        if(lines[i].second <= end) {
            continue;
        }

        if(lines[i].first > end) {
            start = lines[i].first;
            total += lines[i].second - start;
        } else {
            total += lines[i].second - end;
        }
        end = lines[i].second;
    }

    cout << total;
}