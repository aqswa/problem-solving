//
// Created by LG on 2024-04-21.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
int N;

bool find(int total, int cur, int start, int end) {
    if(start > end) {
        return false;
    }

    int mid = (start + end) / 2;

    if(arr[mid] + cur < total) {
        return find(total, cur, mid+1, end);
    } else if(arr[mid] + cur > total) {
        return find(total, cur, start, mid-1);
    } else {
        return true;
    }
}

int solution() {
    for(int i=N-1; i>0; i--) {
        for(int j=0; j<i; j++) {
            for(int k=j; k<i; k++) {
                if(arr[j] + arr[k] >= arr[i]){
                    break;
                }
                if(find(arr[i], arr[j] + arr[k], k, i-1)){
                    return arr[i];
                }
            }
        }
    }
}

int main() {
    cin >> N;

    arr.assign(N, 0);
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    cout << solution();
}
