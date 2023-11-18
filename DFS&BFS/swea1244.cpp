//
// Created by LG on 2023-11-18.
//
#include <iostream>
#include <string>

using namespace std;

string num;
int change;
int answer = 0;

void dfs(int idx, int cnt) {
    if (cnt == change) {
        answer = max(answer, stoi(num));
        return;
    }

    for (int i = idx; i < num.length() - 1; i++) {
        for (int j = i + 1; j < num.length(); j++) {
            if (num[i] <= num[j]) {
                swap(num[i], num[j]);
                dfs(i, cnt + 1);
                swap(num[i], num[j]);
            }
            else if (i == num.length() - 2 && j == num.length() - 1)
            {
                swap(num[i], num[j]);
                dfs(i, cnt + 1);
                swap(num[i], num[j]);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "#" << i << ' ';
        cin >> num >> change;

        answer = 0;
        dfs(0, 0);

        cout << answer << '\n';
    }
}
