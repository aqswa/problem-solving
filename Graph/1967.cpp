#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci;

int n;
vector<vector<ci>> tree;

ci bfs(int start) {
	queue<ci> q;
	q.push({ start, -1 }); // 현재 정점, 이전 정점
	vector<int> distance(n + 1, 0);
	distance[start] = 0;

	while (!q.empty()) {
		int cur = q.front().first;
		int prev = q.front().second;
		q.pop();
		for (int i = 0; i < tree[cur].size(); i++) {
			if (tree[cur][i].first != prev) {
				q.push({ tree[cur][i].first, cur });
				distance[tree[cur][i].first] = distance[cur] + tree[cur][i].second;
			}
		}
	}

	int max_dist = 0;
	int max_node = start;
	for (int i = 1; i <= n; i++) {
		if (distance[i] > max_dist) {
			max_dist = distance[i];
			max_node = i;
		}
	}

	return { max_node, max_dist };
}

int main()
{
	cin >> n;

	tree.assign(n + 1, vector<ci>());
	for (int i = 0; i < n - 1; i++) {
		int p, c, w;
		cin >> p >> c >> w;
		tree[p].push_back({ c, w }); //연결된 정점, 가중치
		tree[c].push_back({ p, w });
	}

	ci info = bfs(1);
	cout << bfs(info.first).second;
}
