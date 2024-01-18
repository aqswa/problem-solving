//
// Created by LG on 2024-01-18.
//
#include <iostream>

using namespace std;

int nums[11];
int operators[4];
int N;
int p, m, mul, d;
bool visited[10];
int min_ans = 1e9;
int max_ans = -1e9;

int operate(int val, int type, int idx) {
    if (type == 0) {
        return val + nums[idx];
    }
    else if (type == 1) {
        return val - nums[idx];
    }
    else if (type == 2) {
        return val * nums[idx];
    }
    else {
        return val / nums[idx];
    }
}

void solve(int cnt, int val) {
    if (cnt == N-1) {
        if (val > max_ans) {
            max_ans = val;
        }
        if (val < min_ans) {
            min_ans = val;
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (operators[i] > 0) {
            operators[i]--;
            solve(cnt + 1, operate(val, i, cnt+1));
            operators[i]++;
        }
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int size = 0;
    for (int i = 0; i < 4; i++) {
        cin >> operators[i];
    }

    solve(0, nums[0]);

    cout << max_ans << '\n' << min_ans;

}
