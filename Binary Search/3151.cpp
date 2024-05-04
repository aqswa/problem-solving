//
// Created by LG on 2024-05-02.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> coding;
int cnt = 0;

void binary_search(int num, int start, int end) {
    if(start > end) {
        return;
    }

    int mid = (start + end) / 2;

    if(coding[mid] == num) {
        cnt++;
        for(int i=mid+1; i<=end; i++) {
            if(coding[i] == num){
                cnt++;
            } else {
                break;
            }
        }
        for(int i=mid-1; i>=start; i--) {
            if(coding[i] == num) {
                cnt++;
            } else {
                break;
            }
        }
    } else if(coding[mid] < num) {
        binary_search(num, mid+1, end);
    } else {
        binary_search(num, start, mid-1);
    }
}

int main() {
    cin >> N;

    coding.assign(N, 0);
    for(int i=0; i<N; i++) {
        cin >> coding[i];
    }

    sort(coding.begin(), coding.end());

    int total = 0;
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            cnt = 0;
            int num = -(coding[i] + coding[j]);
            binary_search(num, j+1, N-1);
            total += cnt;
        }
    }

    cout << total;
}
