#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int N, M;

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	
	cin >> N >> M;

	vector<vector<int>> graph(N + 1, vector<int>());
	vector<int> dp(N + 1, 1);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			dp[i] = max(dp[i], dp[graph[i][j]] + 1);
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << dp[i] << ' ';
	}
}
