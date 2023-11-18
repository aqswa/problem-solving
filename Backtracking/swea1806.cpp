#include <vector>
#include <iostream>

using namespace std;

int ans = 0;
int N;
vector<int> col;

bool check(int r, int i) {
    for (int j = 0; j < r; j++) {
        if (col[j] == i) {
            return false;
        }
        if (r-j == abs(i - col[j])) {
            return false;
        }
    }
    return true;
}

void backtracking(int r) {
    if (r == N) {
        ans++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (check(r, i)) {
            col[r] = i;
            backtracking(r + 1);
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> N;
        ans = 0;
        col.assign(N, -1); //각 행의 열 번호
        backtracking(0);

        cout << "#" << i << ' ' << ans << '\n';
    }
}
