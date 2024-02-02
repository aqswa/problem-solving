#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int N;
vector<vector<int>> graph;

int main() {

	cin >> N;

	vector<vector<int>> distance(N + 1, vector<int>(N + 1, 1e9));

	for (int i = 1; i <= N; i++) {
		distance[i][i] = 0;
	}

	while (true) {
		int a, b;
		cin >> a >> b;

		if (a == -1 && b == -1)
			break;

		distance[a][b] = 1;
		distance[b][a] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (distance[i][k] + distance[k][j] < distance[i][j]) {
					distance[i][j] = distance[i][k] + distance[k][j];
				}
			}
		}
	}

	vector<vector<int>> score(N+1, vector<int>()); //점수, 후보 번호
	for (int i = 1; i <= N; i++) {
		int max = 1;
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			if (distance[i][j] > max) {
				max = distance[i][j];
			}
		}
		score[max].push_back(i);
	}


	for (int i = 1; i <= N; i++) {
		if (score[i].size() > 0) {
			cout << i << ' ' << score[i].size() << '\n';
			for (int j = 0; j < score[i].size(); j++) {
				cout << score[i][j] << ' ';
			}
			break;
		}
	}
}
