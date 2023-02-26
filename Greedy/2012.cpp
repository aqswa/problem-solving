//
// Created by LG on 2023-02-26.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

int main() {
    int n;
    cin >> n;

    vector<long long> expect(n, 0);
    for(int i=0; i<n; i++){
        cin >> expect[i];
    }

    sort(expect.begin(), expect.end());

    long long cnt = 0;
    for(long long i=0; i<n; i++){
        cnt += abs(expect[i] - (i+1));
    }
    cout << cnt;
}
