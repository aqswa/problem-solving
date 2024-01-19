#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
int board[20][20];
int visited[20];
vector<int> t1;
int ans = 1e9;

int calc_xp(vector<int> t1, vector<int> t2) {
	int s1 = 0;
	int s2 = 0;
	
	for (int i = 0; i < N / 2; i++) {
		for (int j = i+1; j < N / 2; j++) {
			s1 += board[t1[i]][t1[j]] + board[t1[j]][t1[i]];
			s2 += board[t2[i]][t2[j]] + board[t2[j]][t2[i]];
		}
	}

	return abs(s1 - s2);
}

void solve(int idx, int cnt) {
	if (cnt == N/2) {
		vector<int> t2;
		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				t2.push_back(i);
			}
		}

		int result = calc_xp(t1, t2);
		if (result < ans) {
			ans = result;
		}
		return;
	}

	for (int i = idx; i < N; i++) {
		t1[cnt] = i;
		visited[i] = true;
		solve(i + 1, cnt + 1);
		visited[i] = false;
	}
}

int main() {
	cin >> N;

	t1.assign(N / 2, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	solve(0, 0);
	cout << ans;
}
