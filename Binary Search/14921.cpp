//
// Created by LG on 2024-04-24.
//
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> values;
int ans = 2*10e9;
int A = 0, B = 0;

void binary_search(int idx, int start, int end) {
    if(start > end) {
        return;
    }

    int mid = (start + end) / 2;
    int a = values[idx];
    if(abs(a + values[mid]) < ans) {
        ans = abs(a + values[mid]);
        A = a;
        B = values[mid];
    }

    if(a < 0 && values[mid] < 0) {
        binary_search(idx, mid + 1, end);
    } else if(a > 0) {
        binary_search(idx, start, mid-1);
    } else if(a < 0 && values[mid] > 0) {
        if(abs(a) < values[mid]) {
            binary_search(idx, start, mid-1);
        } else {
            binary_search(idx, mid+1, end);
        }
    } else if(a == 0){
        if(idx != N-1) {
            if(abs(a + values[idx+1]) < ans) {
                ans = abs(a + values[idx+1]);
                A = a;
                B = values[idx+1];
            }
        }
    }
}

int main() {

    cin >> N;
    values.assign(N, 0);

    for(int i=0; i<N; i++) {
        cin >> values[i];
    }

    for(int i=0; i<N-1; i++) {
        binary_search(i, i+1, N-1);
    }

    cout << A << ' ' << B;
}